#include <iostream>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 1003;
int n;
double A[N], B[N];
map<pair<float, float>, bool> mp;
map<pair<int, int>, bool> have;

signed main()
{
    cin >> n;
    int ans = 1;
    for (int i = 1, o = 0; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (have[make_pair(a, b)])
            continue;
        ++ans;
        have[make_pair(a, b)] = true;
        A[++o] = a, B[o] = b;
        map<pair<float, float>, bool> tmp;
        for (int j = 1; j < o; ++j)
        {
            if (A[j] == A[o])
                continue;
            double x = (B[o] - B[j]) / (A[j] - A[o]);
            double y = A[o] * x + B[o];
            pair<float, float> p((float)x, (float)y);
            if (!mp[p])
            {
                ++ans;
                mp[p] = true;
            }
            else if (!tmp[p])
            {
                ++ans;
                tmp[p] = true;
            }
        }
    }
    cout << ans;
    return 0;
}