#include <iostream>

using namespace std;
typedef long long ll;
constexpr int Inf = 0x3f3f3f3f;
// #define int long long

const int N = 500005;
const ll P  = 998244353;
int n;
int ls[N], rs[N];
ll a[N << 1], b[N << 1];

ll ans = 0;

void init_dfs(int o = 1)
{
    if (o >= n) {
        ans = (ans + a[o]) % P;
        return;
    }
    init_dfs(ls[o]);
    init_dfs(rs[o]);
    a[o] = a[ls[o]] * a[rs[o]] % P;
    ans  = (ans + a[o]) % P;
}

ll sum = 0;

ll dfs(int o = 1)  // 返回o结点一共乘了多少
{
    if (o >= n) {
        ans = ((ans + (sum + a[o]) * (b[o] - 1)) % P + P) % P;
        cout << ans << ' ';
        sum = sum * b[o] % P;
        return b[o];
    }
    sum   = (sum + a[o]) % P;
    ll re = dfs(ls[o]) * dfs(rs[o]) % P;
    sum   = ((sum - re * a[o]) % P + P) % P;
    return re;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = n; i < 2 * n; ++i)
        cin >> a[i];
    for (int i = n; i < 2 * n; ++i)
        cin >> b[i];
    for (int i = 1; i < n; ++i)
        cin >> ls[i] >> rs[i];

    init_dfs();

    // cout << ans << ' ';

    dfs();

    return 0;
}