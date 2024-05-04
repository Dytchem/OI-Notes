#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
// constexpr ll INF = 0x7fffffffffffffff;
inline ll CEIL(ll a, ll b) { return (a - 1) / b + 1; }

ll n, d;
ll a[(int)1e5 + 1];
ll dp[(int)1e5 + 1];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> d;
	d <<= 1;
	for (ll i = 1;i <= n;++i) {
		cin >> a[i];
	}

	for (ll i = 2;i <= n;++i) {
		dp[i] = dp[i - 1];
		if (a[i - 1] <= a[i])
			dp[i] += (a[i] - a[i - 1]) / d + 1;
		else {
			ll canUp = CEIL((a[i - 1] - a[i]), d) - 1;
			a[i] += d * min(canUp, dp[i]);
		}
	}
	cout << dp[n];
	return 0;

	/*for (ll i = n - 1;i >= 1;--i) {
		dp[i] = dp[i + 1];
		if (a[i] <= a[i + 1])
			dp[i] += (a[i + 1] - a[i]) / d + 1;
	}
	cout << dp[1];
	return 0;*/
}