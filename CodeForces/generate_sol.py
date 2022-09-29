#!/bin/python3
#
# Path: generate_sol.py
# Author: Abd El-Twab M. Fakhry @AbdeltwabMF
# Date: 2022-09-29
# Description: Generate solution file for codeforces problem

import time
import random
import hashlib
import json
from requests import get
from bs4 import BeautifulSoup
import os.path

with open('config.json', 'r') as config_file:
    params = json.load(config_file)

unix_stamp_time = str(int(time.time()))
# if the contestId <= contest_max_limit then it is a contest, otherwise it is a gym
contest_max_limit = 9999
root_url = 'https://codeforces.com/'

def get_hash():
    six_random_digits = list("168943")
    random.shuffle(six_random_digits)
    six_random_digits = ''.join(six_random_digits)

    to_be_hashed = six_random_digits + '/' + params['method_name'] + '?apiKey=' + params['apiKey'] + '&count=' + params['count'] + '&from=' + params['from'] + '&handle=' + params['handle'] + '&time=' + unix_stamp_time + '#' + params['secretKey']
    return six_random_digits + hashlib.sha512(to_be_hashed.encode('utf-8')).hexdigest()


def get_submissions():
    request_url = root_url + 'api/' + params['method_name'] + '?handle=' + params['handle'] + '&from=' + params['from'] + '&count=' + params['count'] + '&apiKey=' + params['apiKey'] + '&time=' + unix_stamp_time + '&apiSig=' + get_hash()
    print(request_url)
    return get(request_url)


def check_submissions_status(verdict):
    if verdict == 'OK':
        pass
    else:
        print("Submissions scrapper is rejected by Codeforces, please try again later")
        exit(1)


def filter_submissions():
    response = get_submissions()
    # submissions = json.dumps(response.json())  # convert python dict to json
    submissions = response.json() # convert json to python dict
    check_submissions_status(submissions['status'])

    accepted = []
    for sub in submissions['result']: # iterate over all submissions['result'] array
        if sub['verdict'] == 'OK':
            accepted.append([sub['problem']['contestId'],
                             sub['problem']['index'],
                             sub['problem']['name'],
                             sub['id'],
                             sub['programmingLanguage']])

    # sort according to contestId, index, problem_name
    accepted.sort(reverse=True)
    return accepted

def get_unique_accepted_submissions():
    accepted_submissions = filter_submissions()
    unique_accepted = []
    # pickup the last accepted submission to the problem if there is more than one according to the submissionId
    for ac in accepted_submissions:
        if len(unique_accepted) > 0 and ac[0] == unique_accepted[-1][1] and ac[1] == unique_accepted[-1][2]:
            pass
        else:
            unique_accepted.append([ac[3], ac[0], ac[1], ac[2], ac[4]])

    # sort the unique submissions in descending order from the present to the past
    unique_accepted.sort(reverse=True)
    return unique_accepted


def get_extension(language):
    if 'C++' in language:
        return '.cpp'
    elif 'JavaScript' in language:
        return '.js'
    elif 'Java' in language:
        return '.java'
    elif 'Python' in language or 'PyPy' in language:
        return '.py'
    elif 'GNU C11' in language:
        return '.c'
    else:
        return '.txt'


def write_solutons():
    unique_accepted_submissions = get_unique_accepted_submissions()
    index = 0
    for ac in unique_accepted_submissions:
        gymOrcontest = "contest/" if ac[1] <= contest_max_limit else "gym/"

        solution_url = root_url + gymOrcontest + str(ac[1]) + "/submission/" + str(ac[0])
        problem_url = root_url + gymOrcontest + str(ac[1]) + "/problem/" + str(ac[2])

        extension = get_extension(ac[4])
        problem_name = ac[2] + '.' + ac[3]
        problem_name_lowered = problem_name.lower().replace(' ', '-')
        comment_prefix = '// ' if extension != '.py' else '# '
        header_comment = comment_prefix + problem_url + '\n\n'
        index += 1

        # if the file already exists, then skip it
        if os.path.isfile(problem_name_lowered + extension):
            continue

        # scrape the problem solution
        id_soup = BeautifulSoup(get(solution_url).text, 'html.parser')
        source_code = id_soup.find('pre', id='program-source-text')

        # write the problem solution to a file
        if source_code is not None:
            source_code = source_code.get_text().replace('\r', '')
            with open(problem_name_lowered + extension, 'w') as file:
                file.write(header_comment + source_code)
        else:
            print(str(index) + " Failed to scrape the solution for " + problem_name)
            with open(problem_name_lowered + '.txt', 'w') as file:
                file.write(header_comment)


if __name__ == '__main__':
    write_solutons()
