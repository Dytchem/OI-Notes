#include <bits/stdc++.h>
using namespace std;

template <typename T>
void read(T& a) {
	a = 0;
	bool f = false;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = true;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		a = (a << 1) + (a << 3) + c ^ 48;
		c = getchar();
	}
}

const int maxn = 3005;
char diff[maxn][maxn];
bool lazl[maxn][maxn], lazr[maxn][maxn];


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			char last = 0;
			for (int j = 1; j <= n; ++j) {
				char now;
				cin >> now;
				now -= '0';
				diff[i][j] = now ^ last;
				last = now;
				lazl[i][j] = lazr[i][j] = false;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n - 1; ++i) {
			char now = diff[i][1];
			if (now) {
				++ans;
				lazl[i + 1][1] ^= 1;
				diff[i + 1][1] ^= 1;
				lazr[i + 1][2] ^= 1;
				diff[i + 1][3] ^= 1;
			}
			if (lazl[i][1]) {
				lazl[i + 1][1] ^= 1;
				diff[i + 1][1] ^= 1;
			}
			for (int j = 2; j <= n - 1; ++j) {
				now ^= diff[i][j];
				if (now) {
					++ans;
					lazl[i + 1][j - 1] ^= 1;
					diff[i + 1][j - 1] ^= 1;
					lazr[i + 1][j + 1] ^= 1;
					diff[i + 1][j + 2] ^= 1;
				}
				if (lazl[i][j]) {
					lazl[i + 1][j - 1] ^= 1;
					diff[i + 1][j - 1] ^= 1;
				}
				if (lazr[i][j]) {
					lazr[i + 1][j + 1] ^= 1;
					diff[i + 1][j + 2] ^= 1;
				}
			}
			now ^= diff[i][n];
			if (now) {
				++ans;
				lazl[i + 1][n - 1] ^= 1;
				diff[i + 1][n - 1] ^= 1;
				lazr[i + 1][n] ^= 1;
			}
			if (lazr[i][n]) lazr[i + 1][n] ^= 1;
		}
		char now = 0;
		for (int j = 1; j <= n; ++j) {
			now ^= diff[n][j];
			ans += now;
		}
		cout << ans << '\n';
	}
}

/*

1
10
1010110101
0101011011
1101001011
0110110111
1111111111
1111111111
0100000011
0111111111
1011111111
0011011101

ans: 46
*/