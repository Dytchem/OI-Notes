#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll CEIL(ll a, ll b) { return (a - 1) / b + 1; }

int main() {
	ios::sync_with_stdio(false);
	ll n, p, q;
	cin >> n >> p >> q;

	const ll kmax1 = min(n / q, n * (n + 1) / (2 * p));
	const ll kmax2 = min((2 * p - q) / (q * q), ((2 * n + 1) * q - 2 * p) / (q * q));
	const ll kmax = min(kmax1, kmax2);

	if (kmax <= 0) {
		cout << "IMPOSSIBLE";
		return 0;
	}

	const ll k = 1;

	const ll sum = k * p;
	const ll num = k * q;
	ll now = num * (num + 1) / 2;
	/*vector<ll> ans(num + 1);
	vector<ll> ans1(1);
	for (ll i = 1;i <= num;++i) ans[i] = i;
	ans1[0] = n + 1;
	while (now < sum) {
		ll p = ans.back();
		ans.pop_back();
		ll p1 = min(p + sum - now, ans1.back() - 1);
		ans1.push_back(p1);
		now += p1 - p;
	}
	for (ll i = 1;i < ans.size();++i) cout << ans[i] << ' ';
	for (ll i = ans1.size() - 1;i >= 1;--i) cout << ans1[i] << ' ';*/

	const int d = (sum - now) / num;
	const int r = (sum - now) % num;
	for (int i = 1 + d;i <= num - r + d;++i) cout << i << ' ';
	for (int i = num - r + d + 2;i <= num + d + 1;++i) cout << i << ' ';
}