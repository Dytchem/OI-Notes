#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

char s[34];
int N, R, B, res[34][34], res_all[34][34];

int ans = 0, ansm = 0;

void dfs(int l, int r, const int ls, const int rs) {
	// cout << l << ' ' << r << ' ' << ls << ' ' << rs << ' ' << B << ' ' << ans << '\n';
	if (B < 0) return;
	if (ansm < ans) ansm = ans;
	if (l >= r) return;
	if (ls) {
		int i = l, j = r;
		if (s[i] != s[j]) goto NEXT;
		if (i + 1 == j) B -= res_all[ls][rs] - res_all[ls][i - 1] - res_all[j + 1][rs];
		else B -= res_all[ls][i] - res_all[ls][i - 1] + res_all[j][rs] - res_all[j + 1][rs];
		ans += 2;
		dfs(l + 1, r - 1, ls, rs);
		ans -= 2;
		if (i + 1 == j) B += res_all[ls][rs] - res_all[ls][i - 1] - res_all[j + 1][rs];
		else B += res_all[ls][i] - res_all[ls][i - 1] + res_all[j][rs] - res_all[j + 1][rs];
	NEXT:
		// i = l;
		for (int j = r - 1;j >= i + 1;--j) {
			if (s[i] != s[j]) continue;
			if (i + 1 == j) B -= res_all[ls][j] - res_all[ls][i - 1];
			else B -= res_all[ls][i] - res_all[ls][i - 1] + res[j][j];
			ans += 2;
			dfs(l + 1, j - 1, ls, j);
			ans -= 2;
			if (i + 1 == j) B += res_all[ls][j] - res_all[ls][i - 1];
			else B += res_all[ls][i] - res_all[ls][i - 1] + res[j][j];
		}
		// j = r;
		for (int i = l + 1;i <= j - 1;++i) {
			if (s[i] != s[j]) continue;
			if (i + 1 == j) B -= res_all[i][rs] - res_all[j + 1][rs];
			else B -= res_all[j][rs] - res_all[j + 1][rs] + res[i][i];
			ans += 2;
			dfs(i + 1, r - 1, i, rs);
			ans -= 2;
			if (i + 1 == j) B += res_all[i][rs] - res_all[j + 1][rs];
			else B += res_all[j][rs] - res_all[j + 1][rs] + res[i][i];
		}
		++l;
		--r;
	}
	for (int i = l;i <= r - 1;++i) {
		for (int j = r;j >= i + 1;--j) {
			if (s[i] != s[j]) continue;
			if (i + 1 == j) B -= res_all[i][j];
			else B -= res[i][i] + res[j][j];
			ans += 2;
			dfs(i + 1, j - 1, i, j);
			ans -= 2;
			if (i + 1 == j) B += res_all[i][j];
			else B += res[i][i] + res[j][j];
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &R, &B);
	scanf("%s", s + 1);
	while (R--) {
		int l, r, cost;
		scanf("%d%d%d", &l, &r, &cost);
		res[l][r] += cost;
	}
	for (int i = 1;i <= N;++i) {
		for (int j = i;j <= N;++j) {
			for (int k = i;k <= j;++k) {
				for (int l = k;l <= j;++l) {
					res_all[i][j] += res[k][l];
				}
			}
		}
	}
	// dfs搜索
	dfs(1, N, 0, 0);
	cout << ansm;
}

/*
10 5 10
ababaababb
1 2 3
3 4 5
5 6 7
2 5 8
7 9 2
*/