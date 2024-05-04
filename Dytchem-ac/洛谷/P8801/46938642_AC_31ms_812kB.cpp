#include <iostream>
#include <algorithm>
#include <numeric>
#include <memory>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <utility>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
//#define int long long

using namespace std;
typedef long long ll;
typedef __int128 lll;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1000006;

ll n0, n;
int a, b;
ll p[18];
int cur = -1;
ll pow10[18]{1};

ll ans = 0;

void dfs(int o = cur, ll N = n0, int A = a, int B = b)
{
    if (o < 0)
    {
        if (N > ans)
            ans = N;
        return;
    }
    if (p[o] == 9)
    {
        dfs(o - 1, N, A, B);
        return;
    }
    ll t = N + (9 - p[o]) * pow10[o];
    if (B >= p[o] + 1)
        dfs(o - 1, t, A, B - p[o] - 1);
    if (A >= 9 - p[o])
        dfs(o - 1, t, A - 9 + p[o], B);
    else
        dfs(o - 1, N + A * pow10[o], 0, B);
}

signed main()
{
    for (int i = 1; i <= 17; ++i)
        pow10[i] = 10 * pow10[i - 1];

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> a >> b;
    n0 = n;

    while (n)
    {
        p[++cur] = n % 10;
        n /= 10;
    }

    dfs();

    cout << ans;

    return 0;
}