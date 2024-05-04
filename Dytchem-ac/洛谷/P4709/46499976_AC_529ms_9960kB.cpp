#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int     Inf = 0x3f3f3f3f;
constexpr ll      INF = 0x3f3f3f3f3f3f3f3f;

const ll    MOD = 998244353;
const int   N   = 100005;
int         nn;
int         nxt[N], cnt[N];
bool        vis[N];
ll          fac[N], inv[N];
ll          dp[N];
vector<int> all_i;

inline ll qpow(ll a, int n)
{
    ll re = 1;
    while (n) {
        if (n & 1)
            re = re * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return re;
}

inline int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

inline ll C(int n, int m)
{
    return (fac[n] * inv[m] % MOD) * inv[n - m] % MOD;
}

inline ll f(int s, int n)
{
    if (dp[n] != INF)
        return dp[n];
    ll re = 0;
    if (n == 0)
        return 1;
    for (int i : all_i) {
        if (i > n)
            break;
        if (gcd(s * i, nn) != i)
            continue;
        re = (re + (((C(n - 1, n - i) * qpow(s, i - 1) % MOD) * fac[i - 1] % MOD) * f(s, n - i))) % MOD;
    }
    return dp[n] = re;
}

int main()
{
    cin >> nn;
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= nn; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = qpow(fac[i], MOD - 2);
        if (nn % i == 0)
            all_i.push_back(i);
    }
    for (int i = 1; i <= nn; ++i)
        cin >> nxt[i];
    for (int i = 1; i <= nn; ++i) {
        if (vis[i])
            continue;
        vis[i] = true;
        int j = nxt[i], c = 1;
        while (!vis[j]) {
            ++c;
            vis[j] = true;
            j      = nxt[j];
        }
        ++cnt[c];
    }
    ll ans = 1;
    for (int i = 1; i <= nn; ++i) {
        if (!cnt[i])
            continue;
        memset(dp, 0x3f, sizeof(dp));
        ans = ans * f(i, cnt[i]) % MOD;
    }
    cout << ans;

    return 0;
}