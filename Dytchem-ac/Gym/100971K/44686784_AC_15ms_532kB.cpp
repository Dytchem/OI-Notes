#include <bits/stdc++.h>
using namespace std;

bool check(string& s) {
	for (int i = 0, j = s.size() - 1;i < j;++i, --j) {
		if (s[i] != s[j]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int ans = -1;
	bool f = true;
	for (int i = 0, j = s.size() - 1;i < j;) {
		if (s[i] != s[j]) {
			if (ans != -1) {
				f = false;
				break;
			}
			else {
				ans = i;
				++i;
			}
		}
		else {
			++i;
			--j;
		}
	}
	if (f) {
		if (ans == -1) {
			int mid = s.size() / 2 + 1;
			s.erase(s.begin() + mid - 1);
			if (check(s)) cout << "YES\n" << mid;
			else cout << "NO";
			return 0;
		}
		cout << "YES\n" << ans + 1;
		return 0;
	}
	ans = -1;
	f = true;
	for (int i = 0, j = s.size() - 1;i < j;) {
		if (s[i] != s[j]) {
			if (ans != -1) {
				f = false;
				break;
			}
			else {
				ans = j;
				--j;
			}
		}
		else {
			++i;
			--j;
		}
	}
	if (f) {
		if (ans == -1) {
			int mid = s.size() / 2 + 1;
			s.erase(s.begin() + mid - 1);
			if (check(s)) cout << "YES\n" << mid;
			else cout << "NO";
			return 0;
		}
		cout << "YES\n" << ans + 1;
	}
	else cout << "NO";
}