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


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		if (k & 1) {
			string ss[2];
			int now = 1;
			for (char c : s) {
				ss[now].push_back(c);
				now ^= 1;
			}
			sort(ss[0].begin(), ss[0].end());
			sort(ss[1].begin(), ss[1].end());
			now = 1;
			int pos[2]{ 0,0 };
			for (char c : s) {
				cout << ss[now][pos[now]++];
				now ^= 1;
			}
		}
		else {
			sort(s.begin(), s.end());
			cout << s;
		}
		cout << '\n';
	}
}