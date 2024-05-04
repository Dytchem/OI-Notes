#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	ll a;
	cin >> a;
	ll ans = 1;
	for (ll i = 62;i >= 0;--i) {
		if ((a >> i) & 1) ans = (ans * ans * 2) % MOD;
		else ans = (ans * ans) % MOD;
	}
	cout << ans;
}