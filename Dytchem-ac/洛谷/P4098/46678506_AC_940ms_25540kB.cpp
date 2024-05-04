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

int n, a[N];

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
    for (int i = 1; i <= n; ++i)
        add(a[i]);
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
    for (int i = 1; i <= n; ++i)
        read(a[i]);
    init();

    // cout << ask(1, 5, 7);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int b = 0, c = 0, d = n + 1, e = n + 1;
        for (int j = i - 1; j >= 1; --j) {
            if (a[j] > a[i])
                if (c == 0)
                    c = j;
                else {
                    b = j;
                    break;
                }
        }
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] > a[i])
                if (d == n + 1)
                    d = j;
                else {
                    e = j;
                    break;
                }
        }
        if (c == 0 && d == n + 1)
            continue;
        ans = max(ans, ask(b + 1, i - 1, a[i]));
        ans = max(ans, ask(i + 1, e - 1, a[i]));
    }
    printf("%d", ans);

    return 0;
}