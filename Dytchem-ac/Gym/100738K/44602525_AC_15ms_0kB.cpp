#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll INF = 0x7fffffffffffffff;

const int target = 1000000000;

double a, b, p;

inline double cal(ll n) {
	return a * pow(n, (double)1 / 3) + b * sqrt(n);
}

int main() {
	cin >> a >> b >> p;
	if (a + b >= p) {
		cout << 1;
		return 0;
	}

	ll mi = 0;
	ll ma = INF;
	while (ma - mi > 3) {
		ll mid = (mi + ma) / 2;
		double c = cal(mid);
		if (c < p) mi = mid;
		else ma = mid;
	}
	ll ans = ma - 3;
	for (;cal(ans) < p;++ans) {}

	cout << ans;
}