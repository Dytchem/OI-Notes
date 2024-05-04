#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int Inf = 0x3f3f3f3f;
// #define int long long

template <typename T>
inline void read(T& a)
{
    a      = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        a = (a << 1) + (a << 3) + (c ^ 48);
        c = getchar();
    }
}

const int N = 500005, P = 30;

int n;
pair<int, int> a[N];

// 可持久化Trie树
int cnt[N << 5][2], son[N << 5][2], root[N];
int cur = 0;  // 每次操作在++cur
int gen = 0;
inline void add(int key)
{
    int lst = root[gen];
    int now = root[++gen] = ++cur;
    for (int p = P - 1; p >= 0; --p) {
        int c        = (key >> p) & 1;
        son[now][c]  = ++cur;
        son[now][!c] = son[lst][!c];
        cnt[now][c]  = cnt[lst][c] + 1;
        cnt[now][!c] = cnt[lst][!c];
        now          = son[now][c];
        lst          = son[lst][c];
    }
}
inline void init()
{
    root[0] = ++cur;
    gen     = 0;
    for (int i = 0; i < n; ++i)
        add(a[i].first);
}
inline int ask(int l, int r, int k)
{
    if (l > r)
        return 0;
    int lcur = root[l - 1], rcur = root[r];
    int re = 0;
    for (int p = P - 1; p >= 0; --p) {
        int c = (k >> p) & 1;
        if (cnt[rcur][!c] - cnt[lcur][!c] != 0) {
            re += 1 << p;
            lcur = son[lcur][!c], rcur = son[rcur][!c];
        }
        else {
            lcur = son[lcur][c], rcur = son[rcur][c];
        }
    }
    return re;
}
// END

int main()
{
    read(n);
    for (int i = 0; i < n; ++i) {
        read(a[i].first);
        a[i].second = i + 1;
    }

    init();

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int b = 0, c = 0, d = n + 1, e = n + 1;
        for (int j = i - 1; j >= 1; --j) {
            if (a[j - 1].first > a[i - 1].first)
                if (c == 0)
                    c = j;
                else {
                    b = j;
                    break;
                }
        }
        for (int j = i + 1; j <= n; ++j) {
            if (a[j - 1].first > a[i - 1].first)
                if (d == n + 1)
                    d = j;
                else {
                    e = j;
                    break;
                }
        }
        if (c == 0 && d == n + 1)
            continue;
        ans = max(ans, ask(b + 1, i - 1, a[i - 1].first));
        ans = max(ans, ask(i + 1, e - 1, a[i - 1].first));
    }

    /*
    sort(a, a + n);

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        int b = 0, c = 0, d = n + 1, e = n + 1;
        for (int j = i + 1; j < n; ++j) {
            if (a[j].second < a[i].second) {
                if (c == 0)
                    c = a[j].second;
                else {
                    b = a[j].second;
                    break;
                }
            }
            else {
                if (d == n + 1)
                    d = a[j].second;
                else {
                    e = a[j].second;
                    break;
                }
            }
        }
        if (c == 0 && d == n + 1)
            continue;
        ans = max(ans, ask(b + 1, a[i].second - 1, a[i].first));
        ans = max(ans, ask(a[i].second + 1, e - 1, a[i].first));
    }
    */

    printf("%d", ans);

    return 0;
}

/*

10
2 5 7 8 6 13 52 89 45 22

ans: 116

*/