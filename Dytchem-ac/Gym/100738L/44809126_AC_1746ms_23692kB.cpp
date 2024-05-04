#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
inline void read(T& a) {
	a = 0;
	char c = getchar();
	while (c < '0' || c>'9') c = getchar();
	while (c >= '0' && c <= '9') {
		a = (a << 1) + (a << 3) + (c ^ 48);
		c = getchar();
	}
}

const int maxn = 1005;
int n, w;
ll a[maxn][maxn], dosum[maxn][maxn], upsum[maxn][maxn];

bool check(const int d) {
	for (int i1 = 1, i2 = d;i2 <= n;++i1, ++i2) {
		for (int j1 = 1, j2 = d;j2 <= n;++j1, ++j2) {
			if (dosum[i2][j2] - dosum[i1 - 1][j1 - 1] + upsum[i1][j2] - upsum[i2 + 1][j1 - 1] - (d & 1) * a[(i1 + i2) >> 1][(j1 + j2) >> 1] <= w) return true;
		}
	}
	return false;
}

int main() {
	int T;
	read(T);
	while (T--) {
		read(n); read(w);
		for (int i = 1;i <= n;++i) {
			for (int j = 1;j <= n;++j) {
				read(a[i][j]);
				upsum[i][j] = dosum[i][j] = a[i][j];
			}
		}
		for (int i = n + 1, j = 1;j <= n;++j) dosum[i][j] = upsum[i][j] = 0;
		for (int k = 2;k <= n;++k) {
			for (int i = k, j = k;j <= n;++j) dosum[i][j] += dosum[i - 1][j - 1];
			for (int i = k + 1, j = k;i <= n;++i) dosum[i][j] += dosum[i - 1][j - 1];
			for (int i = n + 1 - k, j = k;j <= n;++j) upsum[i][j] += upsum[i + 1][j - 1];
			for (int i = n - k, j = k;i >= 1;--i) upsum[i][j] += upsum[i + 1][j - 1];
		}
		if (check(n)) {
			cout << n << '\n';
			return 0;
		}
		int mi = 0, ma = n;
		while (ma - mi > 1) {
			int mid = (ma + mi) >> 1;
			if (check(mid)) mi = mid;
			else ma = mid;
		}
		cout << mi << '\n';
	}
}