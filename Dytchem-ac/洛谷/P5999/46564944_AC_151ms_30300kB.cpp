#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
inline void read(T& a)
{
    a      = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        a = (a << 1) + (a << 3) + (c ^ 48);
        c = getchar();
    }
}

constexpr int N = 2003, MOD = 1e9 + 7;
ll            f[N][N];

int main()
{
    int n, s, t;
    read(n), read(s), read(t);
    f[1][1] = 1;
    for (ll i = 2; i <= n; ++i) {
        if (i == s || i == t) {
            for (ll j = 1; j <= i; ++j) {
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
            }
        }
        else {
            for (ll j = 1; j <= i; ++j) {
                f[i][j] = (f[i - 1][j - 1] * (j - (i > s) - (i > t)) + f[i - 1][j + 1] * j) % MOD;
            }
        }
    }
    printf("%lld", f[n][1] % MOD);
}