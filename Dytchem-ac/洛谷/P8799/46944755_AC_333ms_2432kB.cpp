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
#include <bitset>
//#define int long long

using namespace std;
typedef long long ll;
typedef __int128 lll;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 200005;

bool a[N], have[N];
int nxt[N], lst[N]; // 双向链表优化复杂度

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    bool f = false;
    while (n--)
    {
        int ai;
        cin >> ai;
        if (a[ai])
            f = true;
        a[ai] = true;
    }
    nxt[0] = 1;
    for (int i = 1; i < N; ++i)
        lst[i] = i - 1, nxt[i] = i + 1;
    for (int i = 1; i < N; ++i)
    {
        if (!a[i])
            continue;
        for (ll j = nxt[1], v = i * j; v < N; j = nxt[j], v = i * j)
        {
            if (a[v])
            {
                have[j] = true;
                nxt[lst[j]] = nxt[j];
                lst[nxt[j]] = lst[j];
            }
        }
    }
    if (n == 1 || f)
        have[1] = true;
    while (q--)
    {
        int b;
        cin >> b;

        if (have[b])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}