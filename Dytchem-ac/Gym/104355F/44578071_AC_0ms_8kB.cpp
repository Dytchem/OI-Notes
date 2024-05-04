#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int INF = 0x7fffffff;

int n;
char a[101];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= 3 * (n - 1);++i) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u] += 1 << v;
		if (a[u] == 6 || a[u] == 12 || a[u] == 14) {
			if (i % 2) cout << "Nocriz";
			else cout << "Sheauhaw";
			return 0;
		}
	}
}