#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int INF = 0x7fffffff;

int a[1000][26];
int b[26];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0;i < n;++i) {
		string s;
		cin >> s;
		for (char c : s) a[i][c - 'a']++;
	}
	int j = 0;
	for (;j < 26;++j) {
		set<int> s;
		bool flag = true;
		for (int i = 0;i < n;++i) {
			auto it = s.find(a[i][j]);
			if (it == s.end()) s.insert(a[i][j]);
			else {
				flag = false;
				break;
			}
		}
		if (flag) goto END;
	}
	if (false) {
	END:
		cout << "YES" << '\n';
		for (int i = 0;i < 26;++i) {
			if (i == j) continue;
			cout << (char)(i + 'a');
		}
		cout << (char)(j + 'a');
		return 0;
	}
	cout << "NO";
}