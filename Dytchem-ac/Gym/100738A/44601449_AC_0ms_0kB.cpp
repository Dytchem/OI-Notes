#include <bits/stdc++.h>
using namespace std;

double solve(double a, double b, double c) {
	return (sqrt(b * b - 4 * a * c) - b) / (2 * a);
}

bool isTrue(int a, int b, int A, int B) {
	if (a <= A && b <= B) return true;
	if (a > A) return false;
	double y = solve((double)b * b / (a * a) + 1, (double)-2 * A, (double)A * A - b * b);
	double x = sqrt(a * a - y * y);
	/*cout << x << ' ' << b * y / a << "\n";
	cout << (A - y) * (A - y) + (b * y / a) * (b * y / a);*/
	if (x + b * y / a <= B) return true;
	return false;
}

int main() {
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	if (a1 > b1) swap(a1, b1);
	if (a2 > b2) swap(a2, b2);
	if (isTrue(a1, b1, a2, b2) || isTrue(a2, b2, a1, b1)) cout << "Yes";
	else cout << "No";
}