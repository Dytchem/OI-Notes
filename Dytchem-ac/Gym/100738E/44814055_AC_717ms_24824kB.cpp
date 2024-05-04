#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 0x7fffffff;

template<typename T>
inline void read(T& a) {
	a = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') {
		a = (a << 1) + (a << 3) + (c ^ 48);
		c = getchar();
	}
}

struct V {
	int id, dis = Inf, fid;
	inline bool operator <(const V& v)const { return dis > v.dis; }
};

const int maxn = 200005, maxm = 400005;
int n, m;
vector<int> nxt[maxn], cst[maxn];
bool vis[maxn];
priority_queue<V> pq;
vector<int> nxt0[maxn];
int cnt[maxn];

void dfs(const int id) {
	if (nxt0[id].empty()) cnt[id] = 1;
	else {
		cnt[id] = 1;
		for (const int sid : nxt0[id]) {
			dfs(sid);
			cnt[id] += cnt[sid];
		}
	}
}

vector<int> ans(const int id) { // 少汇多
	if (nxt0[id].empty()) {
		return vector<int>{id, id};
	}

	int sidm = nxt0[id][0];
	for (const int sid : nxt0[id]) {
		if (cnt[sidm] < cnt[sid]) sidm = sid;
	}

	vector<int> re = ans(sidm);
	printf("Drive %d %d %d\n", re[0], sidm, id);
	for (const int sid : nxt0[id]) {
		if (sid == sidm) continue;
		vector<int> v = ans(sid);
		printf("Drive %d %d %d\n", v[0], sid, id);
		for (auto it = v.begin() + 1;it != v.end();++it) printf("Move %d %d %d\n", *it, v[0], re[0]);
		re.insert(re.end(), v.begin() + 1, v.end());
	}
	re.push_back(id);
	printf("Move %d %d %d\n", id, id, re[0]);

	return re;
}


int main() {
	read(n); read(m);
	while (m--) {
		int x, y, c;
		read(x); read(y); read(c);
		nxt[x].push_back(y);
		nxt[y].push_back(x);
		cst[x].push_back(c);
		cst[y].push_back(c);
	}
	pq.push(V{ 1,0 });
	int cost = 0;
	int i = 1;
	while (i <= n) {
		const int id = pq.top().id, dis = pq.top().dis, fid = pq.top().fid;
		pq.pop();
		if (vis[id]) continue;
		vis[id] = true;
		cost += dis;
		nxt0[fid].push_back(id);
		++i;
		for (int j = 0;j < nxt[id].size();++j) {
			if (vis[nxt[id][j]]) continue;
			pq.push(V{ nxt[id][j],cst[id][j],id });
		}
	}
	printf("%d\n", cost);
	dfs(1);
	ans(1);
	printf("Done\n");
}