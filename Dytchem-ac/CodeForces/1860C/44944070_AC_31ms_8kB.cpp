#include <bits/stdc++.h>
using namespace std;
constexpr int Inf = 0x7fffffff;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int m1 = Inf, m2 = Inf;
		int ans = 0;
		while (n--) {
			int p;
			cin >> p;
			if (p < m1) m1 = p;
			else if (p < m2) m2 = p, ++ans;
		}
		cout << ans << '\n';
	}
}