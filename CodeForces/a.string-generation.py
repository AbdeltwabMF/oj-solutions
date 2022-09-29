# https://codeforces.com/contest/1461/problem/A

t = int(input())
pat = "acb"

def Solve():
    n, k = map(int, input().split())
    for i in range(n):
        print(pat[i % 3], end = '')

while t != 0:
    Solve()
    print('')
    t -= 1
