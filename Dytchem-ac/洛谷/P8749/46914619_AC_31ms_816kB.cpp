#include <iostream>
#include <queue>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define x0 cycucckdux

const ll N = 1000000009;

signed main()
{
    int n;
    cin >> n;
    if (n == 1)
        return cout << 1, 0;
    queue<int> q;
    q.push(0);
    q.push(1);
    q.push(0);
    int ans = 1;
    int maxj = INF;
    bool active = false;
    for (int i = 2;; ++i)
    {
        int lst = q.front();
        q.pop();
        q.push(0);
        int j = 1;
        int f = 0;
        for (; j <= min(i, maxj); ++j)
        {
            ++ans;
            int now = lst + q.front();
            //cout << ans << ' ' << now << '\n';
            lst = q.front();
            if (now == n)
                return cout << ans, 0;
            q.pop();
            if (now > N)
            {
                active = true;
                while (q.front())
                    q.pop();
                q.pop();
                maxj = j - 1;
                f = 1;
                break;
            }
            q.push(now);
        }
        if (active && f == 0)
        {
            while (q.front())
                q.pop();
            q.pop();
        }
        q.push(0);
        ans += i - j + 1 - f;
        if (maxj == 3)
        { // 开始O(1)求
            double x0 = (3 + sqrt(8 * n + 1)) / 2;
            int x = round(x0);
            if (abs(x - x0) < 0.01)
            {
                return cout << x * (x - 1) / 2 + 3, 0;
            }
            else
            {
                return cout << n * (n + 1) / 2 + 2, 0;
            }
        }
    }
    return 0;
}