#include <iostream>

using namespace std;
typedef long long ll;
constexpr int Inf = 0x3f3f3f3f;
#define int long long

const int N = 100005;
int n, m, p;
int fac[N]{1, 1};

inline int qpow(int a, int n)
{
    int re = 1;
    while (n) {
        if (n & 1)
            re = re * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return re;
}

int C(int n, int m)
{
    if (m == 0)
        return 1;
    int a = n % p, b = m % p;
    if (a < b)
        return 0;
    for (int i = 2; i <= a; ++i) {
        fac[i] = fac[i - 1] * i % p;
    }
    int y = fac[a] * qpow(fac[b] * fac[a - b] % p, p - 2) % p;
    return C(n / p, m / p) * y % p;
}

signed main()
{
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> p;
        cout << (C(n + m, n) + p) % p << '\n';
    }
}