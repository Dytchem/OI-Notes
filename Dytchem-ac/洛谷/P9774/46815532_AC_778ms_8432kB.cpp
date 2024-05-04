#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define int ll

int T, p;
int stans[2000006]{1, 1};

int f(int x)
{
    if (x < p)
        return stans[x];
    int k = x / p, y = x - k * p;
    int re = ((k & 1 ? -1 : 1) * f(k) * stans[y] % p + p) % p;
    return re;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> T >> p;

    for (int i = 2; i < p; ++i)
        stans[i] = stans[i - 1] * i % p;

    while (T--) {
        int n;
        cin >> n;
        cout << f(n) << '\n';
    }
}

/*

2 10007
56526482141861
65244265146814

*/