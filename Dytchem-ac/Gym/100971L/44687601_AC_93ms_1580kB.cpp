#include <bits/stdc++.h>
using namespace std;
inline int CEIL(int a, int b) { return (a - 1) / b + 1; }

int n;
int a[200001], b[200001];

bool canWin(int a[], int b[]) {
	int t = 0;
	for (int i = n, j = n;i > 0 && j > 0;) {
		if (a[i] > b[j]) {
			++t;
			--i;
			--j;
		}
		else --j;
	}
	if (t > n - t) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1;i <= n;++i) cin >> a[i];
	for (int i = 1;i <= n;++i) cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	bool aw = canWin(a, b), bw = canWin(b, a);
	if (aw) {
		if (bw) cout << "Both";
		else cout << "First";
	}
	else {
		if (bw) cout << "Second";
		else cout << "None";
	}
}