#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
char s[maxn];
int n;
int sa[maxn], rk[maxn << 1], rk2[maxn << 1];

int k = 1;
inline bool cmp(const int& x, const int& y) {
	if (rk[x] == rk[y])
		return rk[x + k] < rk[y + k];
	else
		return rk[x] < rk[y];
}

inline bool equ(const int& x, const int& y) {
	return rk[x] == rk[y] && rk[x + k] == rk[y + k];
}

int cnt[maxn << 2];

void insert(int k, int l = 1, int r = n, int p = 1) {
	++cnt[p];
	if (l == r) return;
	int mid = l + r >> 1;
	int ps = p << 1;
	if (k <= mid) insert(k, l, mid, ps);
	else insert(k, mid + 1, r, ps + 1);
}

int kthmin(int k, int l = 1, int r = n, int p = 1) {
	if (l == r) return l;
	int mid = l + r >> 1;
	int ps = p << 1;
	if (k <= cnt[ps]) return kthmin(k, l, mid, ps);
	else return kthmin(k - cnt[ps], mid + 1, r, ps + 1);
}

int main() {

	/*n = 6;
	int a[]{ 1,3,5,6,2,4 };
	for (int b : a) insert(b);
	cout << kthmin(6);
	return 0;*/

	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) {
		sa[i] = i;
		rk[i] = s[i];
	}
	for (; k <= n; k <<= 1) {
		sort(sa + 1, sa + 1 + n, cmp);
		rk2[sa[1]] = 1;
		for (int i = 2; i <= n; ++i)
			rk2[sa[i]] = rk2[sa[i - 1]] + !equ(sa[i - 1], sa[i]);
		swap(rk, rk2);
	}

	//for (int i = 1; i <= n; ++i)
	//	printf("%d ", sa[i]);
	//return 0;

	int Q;
	scanf("%d", &Q);
	vector<int> ans(Q);
	vector<pair<pair<int, int>, int>> q(Q);
	for (int i = 0; i < Q; ++i) {
		int L;
		scanf("%d%d", &L, &q[i].first.second);
		q[i].first.first = n + 1 - L;
		q[i].second = i;
	}
	sort(q.begin(), q.end());

	int im_last = 0;
	for (const auto& p : q) {
		int im = p.first.first, K = p.first.second;
		for (int i = im_last + 1; i <= im; ++i) insert(rk[i]);
		ans[p.second] = sa[kthmin(K)];
		im_last = im;
	}
	for (int a : ans)
		printf("%d\n", a);
}