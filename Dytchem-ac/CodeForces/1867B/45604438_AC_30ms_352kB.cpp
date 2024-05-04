#define _CRT_SECURE_NO_WARNINGS
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

const int maxn = 100005;
bool b[maxn];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s;
		cin >> s;
		for (int i = 1; i <= n; ++i) b[i] = s[i - 1] - '0';

		int cnt = 0;
		for (int i = 1, j = n; i < j; ++i, --j) if (b[i] != b[j]) ++cnt;
		//cout << '(';
		for (int i = 0; i < cnt; ++i) cout << 0;
		if (n & 1) {
			for (int i = cnt; i <= n - cnt; ++i) cout << 1;
			for (int i = n - cnt + 1; i <= n; ++i) cout << 0;
		}
		else {
			for (int i = cnt, f = 1; i <= n - cnt; ++i, f ^= 1) cout << f;
			for (int i = n - cnt + 1; i <= n; ++i) cout << 0;
		}
		//cout << ')';
		cout << '\n';
	}
}