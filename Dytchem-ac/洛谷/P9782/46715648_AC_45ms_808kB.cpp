#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int l = max(s.size(), t.size());
    s.resize(l + 1);
    t.resize(l + 1);
    char ans[l + 1];
    int jw = 0;
    for (int i = 0; i < l + 1; ++i) {
        if (s[i] == 0)
            s[i] = 'A';
        if (t[i] == 0)
            t[i] = 'A';
        ans[i] = s[i] - 'A' + t[i] + jw;
        if (ans[i] > 'Z')
            ans[i] -= 26, jw = 1;
        else
            jw = 0;
    }
    bool f  = true;
    int cnt = 0;
    for (int i = l; i >= 0; --i) {
        if (f && ans[i] <= 'A')
            continue;
        f = false;
        cout << ans[i];
        ++cnt;
    }
    if (cnt == 0)
        cout << 'A';
}