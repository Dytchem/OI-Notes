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

const int pm = 1e5;

vector<int> ps;
bitset<pm + 1> b;

vector<int> ans;

void dfs(int now) {
	// cout << '(' << now << ') ';
	if (now == 1) return;
	const int now0 = now;
	for (int p : ps) {
		if (p * p > now) break;
		while (now % p == 0) now /= p;
		if (now == 1) {
			const int d = now0 / p;
			ans.push_back(now0 - d);
			dfs(now0 - d);
			return;
		}
	}
	const int d = now0 / now;
	ans.push_back(now0 - d);
	dfs(now0 - d);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 2; i <= pm; ++i) {
		if (!b[i]) ps.push_back(i);
		for (int j : ps) {
			if (i * j > pm) break;
			b[i * j] = true;
			if (i % j == 0) break;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		ans.clear();
		ans.push_back(x);
		dfs(x);
		cout << ans.size() << '\n';
		for (int a : ans) cout << a << ' ';
		cout << '\n';
		// cout << '\n';
	}
}