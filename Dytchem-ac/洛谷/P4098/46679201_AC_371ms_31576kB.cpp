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

// 链表
struct Node
{
    Node *pre, *nxt;
    int id;
} nodes[N];

inline void del(Node* o)
{
    o->pre->nxt = o->nxt;
    o->nxt->pre = o->pre;
}
// END

int n;
pair<int, Node*> a[N];

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
    nodes[0].pre = &nodes[0];
    nodes[0].nxt = &nodes[1];
    nodes[0].id  = 0;
    for (int i = 1; i <= n; ++i) {
        read(a[i].first);
        nodes[i].id      = i;
        a[i].second      = &nodes[i];
        nodes[i].pre     = &nodes[i - 1];
        nodes[i - 1].nxt = &nodes[i];
    }
    nodes[n].nxt     = &nodes[n + 1];
    nodes[n + 1].pre = &nodes[n];
    nodes[n + 1].nxt = &nodes[n + 1];
    nodes[n + 1].id  = n + 1;

    init();
    sort(a + 1, a + n + 1);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int b = a[i].second->pre->pre->id;
        int c = a[i].second->pre->id;
        int d = a[i].second->nxt->id;
        int e = a[i].second->nxt->nxt->id;
        if (c == 0 && d == n + 1)
            continue;
        ans = max(ans, ask(b + 1, a[i].second->id - 1, a[i].first));
        ans = max(ans, ask(a[i].second->id + 1, e - 1, a[i].first));
        del(a[i].second);
    }

    printf("%d", ans);

    return 0;
}

/*

10
2 5 7 8 6 13 52 89 45 22

ans: 116

*/