class Solution {
public:
    string pushDominoes(string &d) {
        int n = d.size();
        int oo = 0xf3f3f3f3;
        vector <int> ltr(n, oo), rtl(n, oo);
        int R = oo, L = oo;

        for(int i = 0; i < n; ++i) {
            if(d[i] == 'R') {
                R = 0;
                continue;
            }
            else if(d[i] == 'L') {
                R = oo;
                continue;
            }

            ltr[i] = R != oo ? ++R : ltr[i];
        }

       for(int i = n - 1; i >= 0; --i) {
            if(d[i] == 'L') {
                L = 0;
                continue;
            }
            else if(d[i] == 'R') {
                L = oo;
                continue;
            }

            rtl[i] = L != oo ? ++L : rtl[i];
        }

        string res = "";
        for(int i = 0; i < n; ++i) {
            if(d[i] == 'R' || d[i] == 'L') {
                res.push_back(d[i]);
                continue;
            }

            if(ltr[i] == oo || rtl[i] == oo) {
                res.push_back(ltr[i] == oo ? rtl[i] == oo ? '.' : 'L' : rtl[i] == oo ? 'R' : '.');
                continue;
            }

            if(ltr[i] < rtl[i]) {
                res.push_back('R');
            } else if(ltr[i] > rtl[i])
                res.push_back('L');
            else
                res.push_back(d[i]);
        }
        return res;
    }
};
