#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int target = 1000000000;

int main() {
	ll n;
	cin >> n;
	if (n <= 4) {
		cout << -1;
		return 0;
	}
	ll ans = 0;
	ll now = 0;
	while (now < target) {
		ll x = n / 2;
		ll y = n - x;
		now = x * y;
		ans++;
		n = now;
	}
	cout << ans;
}