#include <bits/stdc++.h>
//#define int long long
using namespace std;

int w[300005];

signed main() {
	int n, L;
	cin >> n >> L;
	for (int i = 0; i < n; ++i) cin >> w[i];
	sort(w, w + n);
	double ans = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += w[i];
		ans += w[i] / sum;
	}
	cout << setprecision(20) << ans * L / 2;
}