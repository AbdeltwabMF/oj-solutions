// https://codeforces.com/contest/1040/problem/B

#include <bits/stdc++.h>

using namespace std;

const int rl=1e9;
int n,k;

void xu_ly()
{
    cin >> n >> k;
    if (2*k+1>=n)
    {
        cout << 1 << endl;
        cout << (n+1)/2;
        return;
    }
    int i,j,an,ani,anj,nu;
    an=rl;
    for (i=1;i<=k+1;i=i+1)
    {
        for (j=n;j>=n-k;j=j-1)
        {
            if (i<=n && j>=1 && i<j)
            {
                if (j-i-1-2*k>=0 && (j-i-1-2*k)%(2*k+1)==0)
                {
                    nu=(j-i-1-2*k)/(2*k+1);
                    if (nu<an)
                    {
                        an=nu;
                        ani=i;
                        anj=j;
                    }
                }
            }
        }
    }
    cout << an+2 << endl;
    for (i=ani;i<=anj;i=i+2*k+1)
    {
        cout << i << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    xu_ly();
}