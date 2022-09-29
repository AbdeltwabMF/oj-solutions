# https://codeforces.com/contest/1068/problem/B

import math

b = int(input())
re = 0

for i in range(1, int(math.sqrt(b)) + 1):
    if b % i == 0:
        re += 1 + (i != b / i)
print(re)

