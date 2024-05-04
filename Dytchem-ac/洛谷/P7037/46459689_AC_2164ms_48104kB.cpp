#include <bits/stdc++.h>
#define y0 y86274264781
using namespace std;
typedef long long ll;
constexpr int     Inf = 0x3f3f3f3f;
constexpr ll      INF = 0x3f3f3f3f3f3f3f3f;

template <typename T> inline void read(T& a)
{
    a      = 0;
    char c = getchar();
    // bool f = false;
    while (c < '0' || c > '9') {
        // if (c == '-') f = true;
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        a = (a << 1) + (a << 3) + (c ^ 48);
        c = getchar();
    }
    // if (f) a = -a;
}

const int   N = 1000006;
int         n, q;
vector<int> nxt[N];
int         fa[N], dep[N], top[N], rnk[N], dfn[N], typ[N], hson[N], lef[N];

int         type = 0;
inline void dfs1(const int now = 1)
{
    if (nxt[now].empty()) {
        lef[now] = 1;
        typ[now] = type;
        return;
    }
    if (now == 1) {
        for (int i : nxt[now]) {
            dep[i] = dep[now] + 1;
            dfs1(i);
            ++type;
            lef[now] += lef[i];
            if (lef[hson[now]] < lef[i]) hson[now] = i;
        }
        return;
    }
    for (int i : nxt[now]) {
        dep[i] = dep[now] + 1;
        dfs1(i);
        lef[now] += lef[i];
        if (lef[hson[now]] < lef[i]) hson[now] = i;
    }
}

int         cnt = 0;
inline void dfs2(const int now = 1, const int tp = 1)
{
    top[now] = tp;
    dfn[now] = ++cnt;
    rnk[cnt] = now;
    if (hson[now])
        dfs2(hson[now], tp);
    else
        return;
    for (int i : nxt[now]) {
        if (i == hson[now]) continue;
        dfs2(i, i);
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

int main()
{
    read(n), read(q);
    for (int i = 2; i <= n; ++i) {
        read(fa[i]);
        nxt[fa[i]].push_back(i);
    }
    dfs1();
    dfs2();

    // lca(9, 8);

    vector<set<int>> tson(type);  // set存rnk
    vector<int>      tmp(type);

    int ans1 = 0, ans2 = 0;
    while (q--) {
        char op;
        int  a;
        scanf("\n%c", &op), read(a);

        auto& s = tson[typ[a]];

        if (op == '+')
            s.insert(dfn[a]);
        else
            s.erase(dfn[a]);
        if (s.size() >= 2) {
            int t = lef[lca(rnk[*s.begin()], rnk[*s.rbegin()])] - s.size();
            ans2 += t - tmp[typ[a]];
            tmp[typ[a]] = t;
        }
        else if (s.size() == 1) {
            if (op == '+') ++ans1;  // 从0增为1
            ans2 -= tmp[typ[a]];
            tmp[typ[a]] = 0;
        }
        else {  // 从1减为0
            --ans1;
        }
        // cout << '(' << tmp[typ[a]] << ')' << endl;

        printf("%d %d\n", ans1, ans2);
    }

    return 0;
}

/*

15 100
1 1 2 2 3 3 4 4 5 5 6 6 7 7
+ 8
+ 9
+ 10
+ 11
- 8

*/