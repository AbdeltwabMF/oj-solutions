class Solution {
public:
    int reverse(int x) {
        int MAX_INTEGER = 2147483647;
        bool neg = x < 0;
        int ret = 0;
        while(x) {
            if(ret && !neg && MAX_INTEGER / ret < 10) return 0;
            if(ret && neg && (-MAX_INTEGER-1) / ret > -10) return 0;
            ret *= 10;
            if(neg)
                ret += (x % 10) * -1;
            else
                ret += x % 10;
            cout << ret << endl;
            x /= 10;
        }
        return neg ? ret * -1 : ret;
    }
};
