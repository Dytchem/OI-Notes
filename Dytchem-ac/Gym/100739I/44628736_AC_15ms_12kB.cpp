#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	double a, b, r;
	cin >> a >> b >> r;

	const int ma = floor(3.1415926535897932384626 / asin( r/ (r + b)) + 1e-10);
	const int mi = max(3, (int)ceil(3.1415926535897932384626 / asin(r / (r + a)) - 1e-10));
	if (ma < mi) cout << 0;
	else cout << ma - mi + 1;
}