#include <bits/stdc++.h>
using namespace std;
inline int CEIL(int a, int b) { return (a - 1) / b + 1; }

int a[200000];

int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	int ma = a[0] + a[1];
	int mi = a[n - 1] - a[0];
	int i;
	if (ma - mi <= 1) cout << "NO";
	else {
		cout << "YES\n" << mi + 1;
	}
}