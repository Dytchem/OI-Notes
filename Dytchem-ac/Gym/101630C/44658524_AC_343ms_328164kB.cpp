#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 0x7fffffff;
constexpr ll INF = 0x7fffffffffffffff;

vector<vector<int>> nxt;
vector<vector<int>> rnxt;
vector<vector<bool>> b;
vector<bool> vis;
vector<bool> rvis;

void dfs(const int x) {
	for (const int y : nxt[x]) {
		if (vis[y]) continue;
		vis[y] = true;
		b[x][y] = true;
		dfs(y);
	}
}

void rdfs(const int x) {
	for (const int y : rnxt[x]) {
		if (rvis[y]) continue;
		rvis[y] = true;
		b[y][x] = true;
		rdfs(y);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int need = m - 2 * n;
		nxt.clear(); nxt.resize(n + 1);
		rnxt.clear(); rnxt.resize(n + 1);
		b.clear(); b.resize(n + 1); for (auto& v : b) v.resize(n + 1);
		vis.clear(); vis.resize(n + 1);
		rvis.clear(); rvis.resize(n + 1);
		while (m--) {
			int x, y;
			scanf("%d%d", &x, &y);
			nxt[x].push_back(y);
			rnxt[y].push_back(x);
		}

		vis[1] = true;
		dfs(1);
		rvis[1] = true;
		rdfs(1);
		for (int x = 1;x <= n;++x) {
			for (const int y : nxt[x]) {
				if (!b[x][y]) {
					printf("%d %d\n", x, y);
					if (--need == 0) goto END;
				}
			}
		}
	END:
		continue;
	}
}

/*
1
4 10
1 2
2 1
2 3
3 2
3 4
4 3
4 1
1 4
1 3
2 4
*/