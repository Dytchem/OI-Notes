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
const int N = 10004, M = 100005;

int u[M], v[M];
int c[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        cin >> u[i] >> v[i];
        ++c[u[i]], ++c[v[i]];
    }

    ll ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        ans += 2 * (c[u[i]] - 1) * (c[v[i]] - 1);
    }

    cout << ans;

    return 0;
}