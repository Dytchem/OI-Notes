#include <bits/stdc++.h>
using namespace std;

int a, b, a1, b1, a2, b2;

bool f(int a1, int b1) { return a1 <= a && b1 <= b; }
bool g(int a1, int b1) { return f(a1, b1) || f(b1, a1); }

int main() {

	cin >> a >> b >> a1 >> b1 >> a2 >> b2;

	bool ans = false;
	ans |= g(a1 + a2, max(b1, b2)) || g(b1 + b2, max(a1, a2));
	swap(a1, b1);
	ans |= g(a1 + a2, max(b1, b2)) || g(b1 + b2, max(a1, a2));
	swap(a2, b2);
	ans |= g(a1 + a2, max(b1, b2)) || g(b1 + b2, max(a1, a2));
	swap(a1, b1);
	ans |= g(a1 + a2, max(b1, b2)) || g(b1 + b2, max(a1, a2));
	if (ans) cout << "YES";
	else cout << "NO";
}