#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

inline ll f(ll a, ll b, ll c) {
	ll d = min(a, b);
	return a * a + b * b + c * c + 7 * min(c, d);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;
	cin >> n;
	while (n--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ll ans = 0;
		if (d <= 100) {
			for (int i = 0;i <= d;++i) {
				for (int j = 0;j <= d - i;++j) {
					for (int k = 0;k <= d - i - j;++k) {
						ans = max(ans, f(a + i, b + j, c + k));
					}
				}
			}
		}
		else {
			ans = max(f(a + d, b, c), f(a, b + d, c));
			ans = max(ans, f(a, b, c + d));
		}
		cout << ans << '\n';
	}
}