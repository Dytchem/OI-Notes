#include <bits/stdc++.h>
using namespace std;
inline int CEIL(int a, int b) { return (a - 1) / b + 1; }

int a[200001];
vector<int> ps;

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> a[i];
		if (a[i] == i) {
			ps.push_back(i);
		}
	}
	if (ps.empty()) {
		cout << 0 << '\n';
		return 0;
	}
	cout << CEIL(ps.size(), 2) << '\n';
	if (ps.size() % 2 == 0) {
		for (int i = 0;i <= ps.size() - 2; i += 2) cout << ps[i] << ' ' << ps[i + 1] << '\n';
	}
	else if (ps.size() == 1) {
		int j = ps[0];
		int i = 1;
		for (;i <= n && i == j;++i) {}
		cout << i << ' ' << ps[0] << '\n';
	}
	else {
		cout << ps[0] << ' ' << ps[1] << '\n';
		cout << ps[1] << ' ' << ps[2] << '\n';
		for (int i = 3;i <= ps.size() - 2;i += 2) cout << ps[i] << ' ' << ps[i + 1] << '\n';
	}
}