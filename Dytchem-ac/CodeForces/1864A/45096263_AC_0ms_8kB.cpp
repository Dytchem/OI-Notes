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


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int x, y, n;
		cin >> x >> y >> n;
		int m = n - 1;
		int d = m * (m + 1) / 2;
		if (x > y - d) cout << -1 << '\n';
		else {
			cout << x << ' ';
			int now = y - d;
			for (int i = m; i > 0; --i) {
				cout << (now += i) << ' ';
			}
			cout << '\n';
		}
	}
}