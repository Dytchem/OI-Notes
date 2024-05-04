#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

template <typename T>
inline void read(T& a) {
	a = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') {
		a = (a << 1) + (a << 3) + (c ^ 48);
		c = getchar();
	}
}

int n, m;
bool s[10][100005];

struct info {
	bool x;
	int a, l, r, len;
}tree[10][400005];

void combine(info& re, const info& i1, const info& i2) {
	re.x = i1.x ^ i2.x;
	re.a = (i1.a + i2.a + (i1.len - i1.r) * i2.l + i1.r * (i2.len - i2.l)) % 4001;
	if (i1.x) re.l = i1.l + i2.len - i2.l;
	else re.l = i1.l + i2.l;
	if (i2.x) re.r = i2.r + i1.len - i1.r;
	else re.r = i2.r + i1.r;
	re.len = i1.len + i2.len;
}

void build(int pr, int l, int r, int p) {
	if (l == r) {
		tree[pr][p].len = 1;
		tree[pr][p].a = tree[pr][p].l = tree[pr][p].r = tree[pr][p].x = s[pr][l];
		return;
	}
	int mid = (l + r) >> 1, ps = p << 1;
	build(pr, l, mid, ps);
	build(pr, mid + 1, r, ps + 1);
	combine(tree[pr][p], tree[pr][ps], tree[pr][ps + 1]);
}

info ask(int pr, int s, int t, int l, int r, int p) {
	if (s == l && t == r) {
		return tree[pr][p];
	}
	int mid = (l + r) >> 1, ps = p << 1;
	if (s <= mid) {
		info ls = ask(pr, s, min(t, mid), l, mid, ps);
		if (t > mid) {
			info rs = ask(pr, mid + 1, t, mid + 1, r, ps + 1);
			info re;
			combine(re, ls, rs);
			return re;
		}
		return ls;
	}
	else {
		return ask(pr, max(s, mid + 1), t, mid + 1, r, ps + 1);
	}
}

void change(int pr, int k, bool v, int l, int r, int p) {
	if (k == l && k == r) {
		if (tree[pr][p].x == v) return;
		tree[pr][p].a = tree[pr][p].l = tree[pr][p].r = tree[pr][p].x = v;
		p >>= 1;
		int ps = p << 1;
		while (p != 0) {
			combine(tree[pr][p], tree[pr][ps], tree[pr][ps + 1]);
			p >>= 1;
			ps = p << 1;
		}
	}
	else {
		int mid = (l + r) >> 1, ps = p << 1;
		if (k <= mid) change(pr, k, v, l, mid, ps);
		else change(pr, k, v, mid + 1, r, ps + 1);
	}
}

int main() {
	read(n);read(m);
	for (int i = 1;i <= n;++i) {
		int a;
		read(a);
		for (int pr = 0;pr < 10;++pr) s[pr][i] = (a >> pr) & 1;
	}
	for (int pr = 0;pr < 10;++pr) build(pr, 1, n, 1);
	while (m--) {
		int op, x, y;
		read(op);read(x);read(y);
		if (op == 1) {
			for (int pr = 0;pr < 10;++pr) change(pr, x, (y >> pr) & 1, 1, n, 1);
		}
		else {
			int ans = 0;
			for (int pr = 0;pr < 10;++pr) {
				ans += ask(pr, x, y, 1, n, 1).a * (1 << pr) % 4001;
			}
			printf("%d\n", ans % 4001);
		}
	}
}

/*
4 1
1 0 0 0
2 1 1
*/