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
const ll P = 1e9 + 7;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    if (n == 1)
        return cout << 1, 0;
    ll A = 1, a = 1, b = 0, c = 0;
    for (int i = 2; i <= n; ++i)
    {
        ll A1 = a;
        ll a1 = (A + a + b + c) % P;
        ll b1 = (A + c) % P;
        ll c1 = (A + b) % P;
        A = A1, a = a1, b = b1, c = c1;
    }
    cout << a;

    return 0;
}