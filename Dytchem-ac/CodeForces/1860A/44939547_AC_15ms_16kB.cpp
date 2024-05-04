#include <bits/stdc++.h>
using namespace std;

string s;
int len, maxi;
int cnt = 0;
string ans = "", ansm = "";
void dfs(const int i) {
	if (ansm != "" || cnt < 0 || cnt > maxi - i || i >= len && ans.substr(i - len, len) == s) return;
	if (i == maxi) {
		ansm = ans;
		return;
	}
	ans.push_back('(');
	++cnt;
	dfs(i + 1);
	--cnt;
	ans.pop_back();
	ans.push_back(')');
	--cnt;
	dfs(i + 1);
	++cnt;
	ans.pop_back();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ans.clear();
		ansm.clear();
		cin >> s;
		len = s.size();
		maxi = len << 1;
		dfs(0);
		if (ansm != "") cout << "YES\n" << ansm << '\n';
		else cout << "NO\n";
	}
}