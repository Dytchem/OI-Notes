#include <bits/stdc++.h>
using namespace std;

template <typename T>
void read(T& a) {
	a = 0;
	bool f = false;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = true;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		a = (a << 1) + (a << 3) + c ^ 48;
		c = getchar();
	}
}

struct P {
	int x, n;
	inline bool operator<(const P& p)const { return x < p.x; }
};

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<P> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i].x;
			v[i].n = i + 1;
		}
		sort(v.begin(), v.end());
		vector<int> ans(n);
		for (int i = n - 1, j = 1; i >= 0; --i, ++j) {
			ans[v[i].n - 1] = j;
		}
		for (int i : ans) cout << i << ' ';
		cout << '\n';
	}
}