#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int m, k, a1, ak;
		cin >> m >> k >> a1 >> ak;
		int A1 = a1 % k, Ak = ak + a1 / k;
		int y = m / k, x = m - k * y;
		x -= A1, y -= Ak;
		if (x < 0) x = 0;
		if (y < 0) y = 0;
		int ans = x + y;
		if (a1 >= k) {
			A1 = k - 1;
			Ak = ak + (a1 - k + 1) / k;
			y = m / k, x = m - k * y;
			x -= A1, y -= Ak;
			if (x < 0) x = 0;
			if (y < 0) y = 0;
			ans = min(ans, x + y);
		}
		cout << ans << '\n';
	}
}