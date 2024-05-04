#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c & 1) {
			if (a < b) cout << "Second";
			else cout << "First";
		}
		else {
			if (a <= b) cout << "Second";
			else cout << "First";
		}
		cout << "\n";
	}
}