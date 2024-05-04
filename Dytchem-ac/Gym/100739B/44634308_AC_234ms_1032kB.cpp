#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const int ma = 400;

int n;
int a[100000];
int ans[ma + 1][ma + 1];

int dfs(const int q, const int p) {
	if (q >= n) return 0;
	if (q <= ma && ans[q][p]) return ans[q][p];
	const int re = a[q] + dfs(q + p, p);
	if (q <= ma) ans[q][p] = re;
	return re;
}

int main() {
	int Q;
	scanf("%d%d", &n, &Q);
	for (int i = 0;i < n;++i) scanf("%d", &a[i]);
	while (Q--) {
		int p, q;
		scanf("%d%d", &q, &p);
		if (p == 0) {
			cout << 0 << '\n';
		}
		else if (p <= ma) {
			cout << dfs(q, p) << '\n';
		}
		else {
			int ansm = 0;
			for (int i = q;i < n;i += p) ansm += a[i];
			cout << ansm << '\n';
		}
	}
}