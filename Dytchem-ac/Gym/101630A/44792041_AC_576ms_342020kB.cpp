#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
void read(T& a) {
	a = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') {
		a = (a << 1) + (a << 3) + (c ^ 48);
		c = getchar();
	}
}

struct node {
	set<int> ids;
	node* ls = nullptr, * rs = nullptr;
};

const int maxn = 2e5 + 5;
const int maxx = 2e9;
const int bound = 1e7;
list<int> big;
int ask[maxn][2];
set<int> id0;

stack<node*> mem; // 内存池

inline void create(node*& re) {
	if (mem.empty()) re = new node;
	else {
		re = mem.top();
		mem.pop();
	}
}

void update(int id, int s, int t, int l, int r, node* p) {
	if (s == l && t == r) {
		p->ids.insert(id);
		return;
	}
	int mid = (l > 0 || r < 0) ? l + ((r - l) >> 1) : (l + r) >> 1;
	if (s <= mid) {
		if (!p->ls)  create(p->ls);
		update(id, s, min(t, mid), l, mid, p->ls);
	}
	if (t > mid) {
		if (!p->rs) create(p->rs);
		update(id, max(s, mid + 1), t, mid + 1, r, p->rs);
	}
}

void erase(int id, int s, int t, int l, int r, node* p) {
	if (!p->ls && !p->rs) {
		p->ids.erase(id);
		return;
	}
	int mid = (l > 0 || r < 0) ? l + ((r - l) >> 1) : (l + r) >> 1;
	if (p->ls && s <= mid) {
		erase(id, s, min(t, mid), l, mid, p->ls);
		if (p->ls->ids.empty() && !p->ls->ls && !p->ls->rs) {
			// delete p->ls;
			mem.push(p->ls);
			p->ls = nullptr;
		}
	}
	if (p->rs && t > mid) {
		erase(id, max(s, mid + 1), t, mid + 1, r, p->rs);
		if (p->rs->ids.empty() && !p->rs->ls && !p->rs->rs) {
			// delete p->rs;
			mem.push(p->rs);
			p->rs = nullptr;
		}
	}
}

set<int>& query(int x, int l, int r, node* p) {
	if (!p->ls && !p->rs) {
		return p->ids;
	}
	if (!p->ids.empty()) {
		if (!p->ls)  create(p->ls);
		if (!p->rs)  create(p->rs);
		p->ls->ids.insert(p->ids.begin(), p->ids.end());
		p->rs->ids.insert(p->ids.begin(), p->ids.end());
		p->ids.clear();
	}
	int mid = (l > 0 || r < 0) ? l + ((r - l) >> 1) : (l + r) >> 1;
	if (x <= mid) {
		if (!p->ls) return id0;
		else return query(x, l, mid, p->ls);
	}
	else {
		if (!p->rs) return id0;
		else return query(x, mid + 1, r, p->rs);
	}
}

int main() {

	node* n0 = new node();

	int n;
	read(n);
	for (int id = 1;id <= n;++id) {
		int t, x, y;
		read(t);read(x);read(y);
		if (t == 1) {
			ask[id][0] = x;
			ask[id][1] = y;
			if (y > bound) big.push_back(id);
			else update(id, x - y, x + y, -maxx, +maxx, n0);
		}
		else {
			for (auto it = big.begin();it != big.end();++it) {
				if (ask[*it][0] - ask[*it][1] > x || ask[*it][0] + ask[*it][1] < x) continue;
				const ll dx = x - ask[*it][0], dy = y - ask[*it][1], r = ask[*it][1];
				if (dx * dx + dy * dy < r * r) {
					big.erase(it);
					printf("%d\n", *it);
					goto END;
				}

			}
			for (const int id : query(x, -maxx, +maxx, n0)) {
				const ll dx = x - ask[id][0], dy = y - ask[id][1], r = ask[id][1];
				if (dx * dx + dy * dy < r * r) {
					erase(id, ask[id][0] - ask[id][1], ask[id][0] + ask[id][1], -maxx, +maxx, n0);
					printf("%d\n", id);
					goto END;
				}
			}
			printf("-1\n");
		}
	END: continue;
	}
}