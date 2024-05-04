#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;
	cin >> n;
	map<string, int> mp;
	vector<string> v;
	for (int i = 0;i < n;++i) {
		string s;
		cin >> s;
		v.push_back(s);
		mp[s]++;
	}
	int m;
	cin >> m;
	map<string, int> cor, wro;
	map<string, string> tra;
	for (int i = 0;i < m;++i) {
		string d, e, c;
		cin >> d >> e >> c;
		tra[d] = e;
		if (c == "correct") cor[d]++;
		else wro[d]++;
	}
	ll cntc = 1, cnta = 1;
	for (auto& p : mp) {
		cntc *= pow(cor[p.first], p.second);
		cnta *= pow(cor[p.first] + wro[p.first], p.second);
	}

	ll cntw = cnta - cntc;

	if (cntc == 1 && cntw == 0) {
		for (auto& p : v) {
			cout << tra[p] << ' ';
		}
		cout << "\ncorrect";
		return 0;
	}
	else if (cntc == 0 && cntw == 1) {
		for (auto& p : v) {
			cout << tra[p] << ' ';
		}
		cout << "\nincorrect";
		return 0;
	}

	cout << cntc << " correct";
	cout << '\n';
	cout << cntw << " incorrect";
}