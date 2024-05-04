#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int INF = 0x7fffffff;

bitset<26> a[1000][26];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << n - 1 << '\n';
	for (int i = 1, w = (n + 1) * (n + 1) / 4;i < n;++i, --w) {
		cout << i << ' ' << i + 1 << ' ' << w << '\n';
	}
}