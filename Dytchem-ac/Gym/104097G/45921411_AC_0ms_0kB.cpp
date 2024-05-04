#pragma GCC optimize(3)
#include <iostream>
using namespace std;

const int maxn = 2000006;
int n, m, q, b, dx;
int a[maxn], maxa = 0;
int val[25];
int st[maxn];

struct bnum {
	int m = 0, real;
	bnum(int x) : real(x) {
		int i = 0;
		for (; x != 0; ++i) {
			val[i] = x % b;
			m += val[i];
			x /= b;
		}
		for (; i < 25; ++i)
			val[i] = 0;
	}
	inline void operator++() {
		real += dx;
		val[0] += dx;
		m += dx;
	}
	inline void clean() {
		for (int i = 0; val[i] >= b && i < 24; ++i) {
			int jw = val[i] / b;
			val[i + 1] += jw;
			m -= jw * dx;
			val[i] -= jw * b;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> q;

	int ans0 = 0;

	for (int i = 1; i <= n; ++i) {
		int ai;
		cin >> ai;
		++a[ai];
		if (maxa < ai)
			maxa = ai;
		if (ai == m)
			++ans0;
	}

	for (b = 2; b <= maxa; ++b) {
		dx = b - 1;
		int ans = 0;
		for (bnum x(m); x.real <= maxa; ++x) {
			//cout << x.real << ' ' << x.m << '\n';
			if (a[x.real]) {
				x.clean();
				if (x.m == m)
					ans += a[x.real];
			}
		}
		st[b] = ans;
	}

	while (q--) {
		cin >> b;
		if (b > maxa) {
			cout << ans0 << '\n';
			continue;
		}
		cout << st[b] << '\n';
	}
}