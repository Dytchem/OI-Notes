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
const int N = 100005;
const int A = 1000006;

int n;
int nxt[A << 1];
int a[N];

int cr(int x)
{
    if (!nxt[x])
        return nxt[x] = x + 1, x;
    else
        return nxt[x] = cr(nxt[x]);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[i] = cr(x);
    }
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';

    return 0;
}