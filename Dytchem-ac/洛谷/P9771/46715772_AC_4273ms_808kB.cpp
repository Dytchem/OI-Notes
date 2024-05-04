#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int lst = -1;
    int ans = 0;
    int f   = 1;  // 1递增，2递减，3混乱
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (f == 1) {
            if (a == lst + 1) {}
            else if (a == lst - 1)
                ++ans, f = 2;
            else
                ++ans, f = 3;
        }
        else if (f == 2) {
            if (a == lst - 1) {}
            else if (a == lst + 1)
                ++ans, f = 1;
            else
                ++ans, f = 3;
        }
        else {
            if (a == lst + 1)
                f = 1;
            else if (a == lst - 1)
                f = 2;
            else
                ++ans;
        }
        lst = a;
    }
    --ans;
    cout << ans;
}