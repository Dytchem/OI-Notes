#include <bits/stdc++.h>
using namespace std;

int main() {
	double x1, y1, x2, y2, vx1, vy1, vx2, vy2;
	cin >> x1 >> y1 >> x2 >> y2 >> vx1 >> vy1 >> vx2 >> vy2;
	const double x = x2 - x1, y = y2 - y1, vx = vx2 - vx1, vy = vy2 - vy1;
	if (x * vx + y * vy >= 0) printf("%.20lf", sqrt(x * x + y * y));
	else {
		const double A = vy, B = -vx;
		printf("%.20lf", abs(A * x + B * y) / sqrt(A * A + B * B));
	}
}