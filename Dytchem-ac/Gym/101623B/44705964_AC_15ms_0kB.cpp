#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	if (n == 1 || n == 2 || n == 3) {
		cout << 1;
		return 0;
	}
	cout << n - 2;
}