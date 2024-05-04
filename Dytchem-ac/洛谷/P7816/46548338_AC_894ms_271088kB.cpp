#include <bits/stdc++.h>
using namespace std;

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

constexpr int N = 1000006, M = 3000006, S = 2 * (M + N), Inf = 0x3f3f3f3f;

int  n, m0, m;
int  hed1[N], hed2[N], nxt1[S], nxt2[S], to1[S], to2[S], id1[S / 2], id2[S / 2], siz[N];
int  cur1 = -1, cur2 = -1;
bool vis[S / 2];
char ans[M];
int  cur = -1;

inline void add1(int u, int v)
{
    to1[++cur1] = v;
    nxt1[cur1]  = hed1[u];
    hed1[u]     = cur1;
    ++siz[u];

    to1[++cur1] = u;
    nxt1[cur1]  = hed1[v];
    hed1[v]     = cur1;
    ++siz[v];

    id1[cur1 / 2] = ++cur;
}

inline void add2(int u, int v)
{
    to2[++cur2] = v;
    nxt2[cur2]  = hed2[u];
    hed2[u]     = cur2;
    ++siz[u];

    to2[++cur2] = u;
    nxt2[cur2]  = hed2[v];
    hed2[v]     = cur2;
    ++siz[v];

    id2[cur2 / 2] = ++cur;
}

void dfs(int now, bool c)
{
    // printf("%d ", now);
    if (c) {
        for (int i = hed1[now]; i != Inf; i = hed1[now]) {
            if (vis[id1[i / 2]]) {
                hed1[now] = nxt1[i];
                continue;
            }
            vis[id1[i / 2]] = true;
            if (id1[i / 2] < m0)
                ans[id1[i / 2]] = i & 1;
            hed1[now] = nxt1[i];
            dfs(to1[i], 1);
        }
        for (int i = hed2[now]; i != Inf; i = hed2[now]) {
            if (vis[id2[i / 2]]) {
                hed2[now] = nxt2[i];
                continue;
            }
            vis[id2[i / 2]] = true;
            if (id2[i / 2] < m0)
                ans[id2[i / 2]] = i & 1;
            hed2[now] = nxt2[i];
            dfs(to2[i], 0);
        }
    }
    else {
        for (int i = hed2[now]; i != Inf; i = hed2[now]) {
            if (vis[id2[i / 2]]) {
                hed2[now] = nxt2[i];
                continue;
            }
            vis[id2[i / 2]] = true;
            if (id2[i / 2] < m0)
                ans[id2[i / 2]] = i & 1;
            hed2[now] = nxt2[i];
            dfs(to2[i], 0);
        }
        for (int i = hed1[now]; i != Inf; i = hed1[now]) {
            if (vis[id1[i / 2]]) {
                hed1[now] = nxt1[i];
                continue;
            }
            vis[id1[i / 2]] = true;
            if (id1[i / 2] < m0)
                ans[id1[i / 2]] = i & 1;
            hed1[now] = nxt1[i];
            dfs(to1[i], 1);
        }
    }
}

int main()
{
    memset(hed1, 0x3f, sizeof(hed1));
    memset(hed2, 0x3f, sizeof(hed2));
    memset(nxt1, 0x3f, sizeof(nxt1));
    memset(nxt2, 0x3f, sizeof(nxt2));

    read(n), read(m0);
    for (int i = 0; i < m0; ++i) {
        int u, v, w;
        read(u), read(v), read(w);
        if (w == 1)
            add1(u, v);
        else
            add2(u, v);
    }
    m = m0;
    for (int i = 1; i <= n; ++i) {
        if (siz[i] & 1) {
            add1(0, i), ++m;
        }
    }

    dfs(0, 1);

    for (int i = 0; i < m0; ++i)
        putchar(ans[i] + '0');
}
