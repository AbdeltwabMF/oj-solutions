// https://codeforces.com/contest/1443/problem/A

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'
#define Min(a, b)   (((a) < (b)) ? (a) : (b))
#define Max(a, b)   (((a) > (b)) ? (a) : (b))

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void File() {
    freopen("input.in",  "r", stdin);
    freopen("output.out", "w", stdout);
}

const int N = 1e6 + 9, M = 2e6 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
ll INF = 0x3f3f3f3f3f3f3f3f;

vector <int> primes;
bool isPrime[N];

void sieve(int x)
{
    int basis [3] = {2, 3, 5};
    int wheel [8] = {7, 11, 13, 17, 19, 23, 29, 1};
    int inc   [8] = {4, 2, 4, 2, 4, 6, 2, 6};
    int inx[31];

    memset(inx,        -1, sizeof inx);
    memset(isPrime, true, sizeof isPrime);

    for(int i : basis) if(x >= i)
            primes.push_back(i);

    for(int i = 0; i < 8; ++i)
        inx[wheel[i]] = i;

    int c = 0;
    for(ll i = 7; i <= x; i += inc[c++])
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            int d = inx[i % 30];

            for(ll j = i * i; j <= x; j += i * inc[d++])
            {
                isPrime[j] = false;
                if(d == 8) d = 0;
            }
        }
        if(c == 8) c = 0;
    }
}

int n;

void Solve()
{
	cin >> n;

	vector <int> Candidate;

	for(int i = n << 2, j = n; j; i -= 2, --j)
        cout << i << " ";
    cout << endl;
}

int main()
{
    Fast();

    sieve(1000);

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
