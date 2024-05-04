#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, d;
		cin >> n >> m >> d;
		vector<int> s(m + 2);
		vector<int> eatdu(m + 2);
		int eatall = 1;
		s[0] = 1;
		for (int i = 1; i <= m; ++i) {
			cin >> s[i];
			eatdu[i] = (s[i] - s[i - 1] - 1) / d;
			eatall += 1 + eatdu[i];
		}
		s[m + 1] = n + 1;
		eatdu[m + 1] = (s[m + 1] - s[m] - 1) / d;
		eatall += eatdu[m + 1];
		int ansi = 0, delta = 0;
		int i = 1;
		if (s[1] == 1) ++i, --eatall;
		int cnt = 0;
		for (; i <= m; ++i) {
			int delta1 = (s[i + 1] - s[i - 1] - 1) / d - eatdu[i] - eatdu[i + 1] - 1;
			if (delta > delta1) delta = delta1, ansi = i, cnt = 1;
			else if (delta == delta1) ++cnt;
		}
		if (delta == 0 && s[1] == 1) ++cnt;
		//cout << '(';
		cout << eatall + delta << ' ' << cnt << '\n';
	}
}