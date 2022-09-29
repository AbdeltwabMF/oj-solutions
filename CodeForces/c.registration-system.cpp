// https://codeforces.com/contest/4/problem/C

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

/**----------------->>  Quality Over Quantity  <<----------------**/

class Trie
{
    Trie* children[36];
    int prefixes, words;
    bool eow;
    char letter;
    vector <string> lex;

  public :
    Trie (char le = '\0') {
        memset(children, 0, sizeof children);
        prefixes = words = 0;
        eow = false;
        letter = le;
    }

    void insert(string str) {
        Trie* cur = this;
        int inx;
        for(char i : str) {
            if(isalpha(i)) inx = i - 'W';
            else inx = i - '0';
            if(cur->children[inx] == 0)
                cur->children[inx] = new Trie(i);

            cur = cur->children[inx];
            cur->prefixes++;
        }

        cur->eow = true;
        cur->words++;
    }

    bool search(string str) {
        Trie* cur = this;
        int inx;
        for(char i : str) {
            if(isalpha(i)) inx = i - 'W';
            else inx = i - '0';
            if(cur->children[inx] == 0)
                return false;

            cur = cur->children[inx];
        }
        return cur->eow;
    }

    int count_word(string str) {
        Trie* cur = this;
        int inx;
        for(char i : str) {
            if(isalpha(i)) inx = i - 'W';
            else inx = i - '0';
            if(cur->children[inx] == 0)
                return false;

            cur = cur->children[inx];
        }
        return cur->words;
    }

    int count_prefix(string str) {
        Trie* cur = this;
        int inx;
        for(char i : str) {
            if(isalpha(i)) inx = i - 'W';
            else inx = i - '0';
            if(cur->children[inx] == 0)
                return 0;

            cur = cur->children[inx];
        }
        return cur->prefixes;
    }

  private :
    void dfs(Trie* node, string str = "") {
        if(node->eow)
            lex.push_back(str);
        for(int i = 0; i < 26; ++i) if(node->children[i])
                dfs(node->children[i], str + node->children[i]->letter);
    }

    bool dlete(Trie* node, string str, int i) {
        if(i == (int)str.size()) {
            for(int j = 0; j < 26; ++j)
                if(node->children[j]) {
                    if(--node->words == 0) {
                        node->prefixes--;
                        node->eow = false;
                    }
                    return true;
                }

            if(--node->words == 0)
                return false;
            else {
                node->prefixes--;
                return true;
            }
        }

        int inx = str[i] - '0';
        if(!dlete(node->children[inx], str, i + 1)) {
            node->children[inx] = 0;
            for(int j = 0; j < 26; ++j)
                if(node->children[j] || node->eow) {
                    node->prefixes--;
                    return true;
                }
            return false;
        } else {
            node->prefixes--;
            return true;
        }
    }

  public :
    bool dlete(string str) {
        if(!search(str)) return false;
        dlete(this, str, 0);
        return true;
    }

    vector <string> lex_sort() {
        lex.clear();
        Trie* root = this;
        for(int i = 0; i < 26; ++i) if(root->children[i])
                dfs(root->children[i], string(1, root->children[i]->letter));

        return lex;
    }

    void print() {
        lex_sort();
        for(int i = 0; i < (int)lex.size(); ++i)
            cout << lex[i] << '\n';
    }
};

int n;
string s;

void Solve()
{
    Trie trie;

    cin >> n;
    while(n--)
    {
        cin >> s;
        if(trie.search(s))
        {
            cout << s << trie.count_word(s) << endl;
            trie.insert(s);
        }
        else
        {
            trie.insert(s);
            cout << "OK" << endl;
        }
    }
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i) Solve();
}
