#include <bits/stdc++.h>
#define y0 QQ1054329487
using namespace std;
typedef long long ll;
constexpr int     Inf = 0x3f3f3f3f;
constexpr ll      INF = 0x3f3f3f3f3f3f3f3f;

template <typename T>
inline void read(T& a)
{
    a      = 0;
    char c = getchar();
    // bool f = false;
    while (c < '0' || c > '9') {
        // if (c == '-') f = true;
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        a = (a << 1) + (a << 3) + (c ^ 48);
        c = getchar();
    }
    // if (f) a = -a;
}

#define int ll

const int N = 51, M = N * (N - 1) / 2;
const int MOD = 1e9 + 7;

int stf[N][M], stg[N], sth[N][M][N], stC[N][N], pow2[N * N];

int g(int n), h(int n, int m, int t), C(int n, int m), mypow(int a, int n);

int f(int n, int m)
{
    if (stf[n][m] != INF)
        return stf[n][m];
    int re = 0;
    if (m == 0) {
        re = g(n);
        for (int i = 1; i <= n - 1; ++i) {
            re -= f(n, i);
        }
        re %= MOD;
    }
    else {
        for (int i = 1; i <= n - m; ++i) {
            for (int d = 1; d <= m; ++d) {
                re = (re + ((C(n - 1, i - 1) * f(i, 0) % MOD) * h(n - i, m - d, d) % MOD) * mypow(i, d)) % MOD;
            }
        }
    }
    return stf[n][m] = re;
}

int g(int n)
{
    if (stg[n] != INF)
        return stg[n];
    int re = pow2[n * (n - 1) / 2];
    for (int i = 1; i <= n - 1; ++i) {
        re = (re - (C(n - 1, i - 1) * g(i) % MOD) * pow2[(n - i) * (n - i - 1) / 2]) % MOD;
    }
    return stg[n] = re;
}

int h(int n, int m, int t)
{
    if (sth[n][m][t] != INF)
        return sth[n][m][t];
    if (t == 1)
        return sth[n][m][t] = f(n, m) * n % MOD;
    int re = 0;
    for (int i = 1; i <= n - t + 1; ++i) {
        for (int j = 0; j <= min(m, i - 1); ++j) {
            re = (re + ((C(n - 1, i - 1) * f(i, j) % MOD) * i % MOD) * h(n - i, m - j, t - 1)) % MOD;
        }
    }
    return sth[n][m][t] = re;
}

int C(int n, int m)
{
    if (stC[n][m] != INF)
        return stC[n][m];
    if (n == m || m == 0)
        return stC[n][m] = 1;
    else
        return stC[n][m] = (C(n - 1, m) + C(n - 1, m - 1)) % MOD;
}

int mypow(int a, int n)
{
    if (n == 0)
        return 1;
    else {
        int m = mypow(a, n / 2);
        return (m * m % MOD) * ((n & 1) ? a : 1) % MOD;
    }
}

signed main()
{
    memset(stf, 0x3f, sizeof(stf));
    memset(stg, 0x3f, sizeof(stg));
    memset(sth, 0x3f, sizeof(sth));
    memset(stC, 0x3f, sizeof(stC));
    for (int j = 0; j < N; ++j) {
        stf[0][j] = stf[1][j] = 0;
    }
    stf[1][0] = 1;
    stg[0] = 0, stg[1] = 1, stg[2] = 1;
    pow2[0] = 1;
    for (int i = 1; i < N * N; ++i)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i <= m; ++i)
        ans += f(n, i) + MOD;
    cout << ans % MOD;

    return 0;
}