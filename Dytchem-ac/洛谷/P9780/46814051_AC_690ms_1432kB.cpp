#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define int ll

int m, k;
bool bgn[1000006];

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> m >> k;
    int lst = -1;
    int cnt = 0, sum = 0;
    for (int i = 1; i <= m; ++i) {
        int a;
        cin >> a;
        if (a > lst) {
            bgn[i] = true;
            ++cnt;
            sum += i - 1;
        }
        lst = a;
    }
    sum += m;

    for (int i = 1; i < cnt; ++i)
        cout << "-1 ";
    cout << sum << ' ';
    for (int i = 1; i <= m; ++i) {
        if (bgn[i])
            continue;
        cout << (sum += i - 1) << ' ';
    }
}