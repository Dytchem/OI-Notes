#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;
constexpr int Inf = 0x3f3f3f3f;
// #define int long long

const int N = 30004;
int n;

namespace slpf {
int hed[N], to[N << 1], nxt[N << 1], cur = 0;
int fa[N], dep[N], siz[N], dfn[N], hson[N], top[N];  // 不要0号结点
inline void add(int u, int v)
{
    nxt[++cur] = hed[u];
    hed[u]     = cur;
    to[cur]    = v;
}
inline void dfs1(int o)
{
    siz[o] = 1;
    for (int j = hed[o]; j; j = nxt[j]) {
        int i = to[j];
        if (i == fa[o])
            continue;
        fa[i]  = o;
        dep[i] = dep[o] + 1;
        dfs1(i);
        siz[o] += siz[i];
        if (siz[hson[o]] < siz[i])
            hson[o] = i;
    }
}
int rk = 0;
inline void dfs2(int o, int t)
{
    dfn[o] = ++rk;
    top[o] = t;
    if (hson[o]) {
        dfs2(hson[o], t);
        for (int j = hed[o]; j; j = nxt[j]) {
            int i = to[j];
            if (i == fa[o] || i == hson[o])
                continue;
            dfs2(i, i);
        }
    }
}
inline int lca(int a, int b)
{
    while (top[a] != top[b]) {
        if (dep[top[a]] > dep[top[b]])
            a = fa[top[a]];
        else
            b = fa[top[b]];
    }
    return dep[a] < dep[b] ? a : b;
}
inline void init()
{
    dfs1(1);
    dfs2(1, 1);
}
}  // namespace slpf

namespace xds {
int ma[N << 2], sum[N << 2];
inline void change(int o, int k, int l = 1, int r = n, int p = 1)
{
    if (l == r) {
        ma[p] = sum[p] = k;
        return;
    }
    int m = l + r >> 1, ls = p << 1;
    if (o <= m)
        change(o, k, l, m, ls);
    else
        change(o, k, m + 1, r, ls | 1);
    ma[p]  = max(ma[ls], ma[ls | 1]);
    sum[p] = sum[ls] + sum[ls | 1];
}
inline int qmax(int a, int b, int l = 1, int r = n, int p = 1)
{
    if (a > b)
        swap(a, b);
    if (a == l && b == r)
        return ma[p];
    int m = l + r >> 1, ls = p << 1;
    int re = -Inf;
    if (a <= m)
        re = max(re, qmax(a, min(b, m), l, m, ls));
    if (b > m)
        re = max(re, qmax(max(a, m + 1), b, m + 1, r, ls | 1));
    return re;
}
inline int qsum(int a, int b, int l = 1, int r = n, int p = 1)
{
    if (a > b)
        swap(a, b);
    if (a == l && b == r)
        return sum[p];
    int m = l + r >> 1, ls = p << 1;
    int re = 0;
    if (a <= m)
        re += qsum(a, min(b, m), l, m, ls);
    if (b > m)
        re += qsum(max(a, m + 1), b, m + 1, r, ls | 1);
    return re;
}
}  // namespace xds

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        slpf::add(a, b), slpf::add(b, a);
    }
    slpf::init();
    for (int i = 1; i <= n; ++i) {
        int w;
        cin >> w;
        xds::change(slpf::dfn[i], w);
    }
    int q;
    cin >> q;
    using namespace slpf;
    using namespace xds;
    while (q--) {
        char s[10];
        int u, v;
        cin >> s >> u >> v;

        if (s[1] == 'M') {
            int ans = -Inf;
            int o   = lca(u, v);
            while (top[u] != top[o]) {
                ans = max(ans, qmax(dfn[u], dfn[top[u]]));
                u   = fa[top[u]];
            }
            ans = max(ans, qmax(dfn[u], dfn[o]));
            while (top[v] != top[o]) {
                ans = max(ans, qmax(dfn[v], dfn[top[v]]));
                v   = fa[top[v]];
            }
            ans = max(ans, qmax(dfn[v], dfn[o]));
            cout << ans << '\n';
        }
        else if (s[1] == 'S') {
            int ans = 0;
            int o   = lca(u, v);
            while (top[u] != top[o]) {
                ans += qsum(dfn[u], dfn[top[u]]);
                u = fa[top[u]];
            }
            ans += qsum(dfn[u], dfn[o]);
            while (top[v] != top[o]) {
                ans += qsum(dfn[v], dfn[top[v]]);
                v = fa[top[v]];
            }
            ans += qsum(dfn[v], dfn[o]);
            ans -= qsum(dfn[o], dfn[o]);
            cout << ans << '\n';
        }
        else {
            change(dfn[u], v);
        }
    }
}

/*

7
1 2
1 3
2 4
2 5
3 6
3 7
1 2 3 4 5 6 7
6
QMAX 4 7
QSUM 4 7
QMAX 5 6
QSUM 5 6
QMAX 2 7
QSUM 2 7

ans:
7
17
6
17
7
13


*/