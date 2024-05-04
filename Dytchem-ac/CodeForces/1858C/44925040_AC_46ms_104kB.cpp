#include <bits/stdc++.h>
using namespace std;

bool b[100005];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(b, 0, sizeof(b));
		int cnt = 0;
		int x = 1, x0 = 1;
		while (true) {
			++cnt;
			cout << x << ' ';
			b[x] = true;
			x <<= 1;
			if (x > n) {
				x = x0;
				while (x <= n && b[x]) ++x;
				x0 = x;
			}
			if (cnt == n) break;
		}
		cout << '\n';
	}
}