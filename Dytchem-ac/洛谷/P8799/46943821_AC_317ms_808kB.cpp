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

bitset<N> a, have;

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
    for (int i = 1; i < N; ++i)
    {
        if (!a[i])
            continue;
        for (int j = 2, v = i * j; v < N; v = (++j) * i)
        {
            if (a[v])
                have[j] = true;
        }
    }
    while (q--)
    {
        int b;
        cin >> b;
        if (b == 1 && (n == 1 || f))
            cout << "YES\n";
        else if (have[b])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}