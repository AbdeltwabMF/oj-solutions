// https://codeforces.com/contest/706/problem/A

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'
#define Min(a, b)   (((a) < (b)) ? (a) : (b))
#define Max(a, b)   (((a) > (b)) ? (a) : (b))

using namespace std;

typedef int64_t    ll;
//typedef complex <long double> point;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void File() {
    freopen("beads.in",  "r", stdin);
    freopen("beads.out", "w", stdout);
}

const int N = 5e5 + 9, M = 1e5 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-9, PI  = acos(-1);

template <class T>
class point
{
    public :
    T x, y;

    point() = default;
    point(T _x, T _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        if(fabs(x - other.x) > EPS) // if(x != other.x)
            return x < other.x;
        return y < other.y;
    }

    bool operator == (point other) const {
        return ((fabs(x - other.x) < EPS) && (fabs(y - other.y) < EPS)); // " < EPS " equal to " == zero "
    }

    bool operator > (point other) const {
        if(fabs(x - other.x) > EPS)
            return x > other.x;
        return y > other.y;
    }

    T dist(point other) { // Euclidean distance
		T dx = this->x - other.x;
		T dy = this->y - other.y;
        return sqrtl(dx * dx + dy * dy);
    }

    T DTR(T theta) {
        return theta * PI / 180.0;
    }

    T RTD(T theta) {
        return theta * 180.0 / PI;
    }

    point rotate(T theta) {
        T rad = DTR(theta);
        return point(cos(theta) * this->x - sin(theta) * this->y,
                     sin(theta) * this->x + cos(theta) * this->y);
    }
};

template <class T>
istream & operator >> (istream & in, point <T> & p) noexcept {
    T a, b;
    cin >> a >> b;
    p.x = a;
    p.y = b;
    return in;
}

template <class T>
ostream & operator << (ostream & out, const point <T> p) noexcept {
    out << "(" << p.x << " " << p.y << ")";
    return out;
}

int n;
long double x, y, z;

void Solve()
{
    point <long double> vas;
    cin >> vas >> n;

    long double best = 1e12, cur;
    for(int i = 0; i < n; ++i)
    {
        cin >> x >> y >> z;
        cur = vas.dist(point <long double> (x, y)) / z;
        best = min(best, cur);
    }
    cout << best << endl;
}

int main()
{
    Fast();
    cout << fixed << setprecision(20);

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
