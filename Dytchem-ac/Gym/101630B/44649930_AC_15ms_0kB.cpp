#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 0x7fffffff;
constexpr ll INF = 0xfffffffffffffff;

int a, b, c, w, h;

bool check(int x, int y) {
	if (x > y) swap(x, y);
	if (x <= w && y <= h) return true;
	else return false;
}

int main() {
	int aa[3];
	cin >> aa[0] >> aa[1] >> aa[2] >> w >> h;
	//if (b < c) swap(b, c);
	//if (a < b) swap(a, b);
	//if (b < c) swap(b, c); // c最小
	if (w > h) swap(w, h);
	/*bool b1 = check(2 * a + 2 * c, b + 2 * c) || check(2 * a + b, b + c);
	swap(a, b);
	bool b2 = check(2 * a + 2 * c, b + 2 * c) || check(2 * a + b, b + c);*/
	sort(aa, aa + 3);

	int n = 6;
	bool bb = false;
	while (n--) {
		const int a = aa[0], b = aa[1], c = aa[2];
		bb = bb || check(c + a + c, c + b + c + b);
		bb = bb || check(b + a + b, c + b + c + b);
		bb = bb || check(b + a + c, c + b + c + b);
		bb = bb || check(c + a + c, a + b + c + b);
		bb = bb || check(a+c + a + c, c + b + a);
		bb = bb || check(a+b+a+c+a,b+c);
		bb = bb || check(b + a + c, a+b+c+a);
		bb = bb || check(c + a + c, b + c + b + a);
		next_permutation(aa, aa + 3);
	}

	if (bb) cout << "Yes";
	else cout << "No";
}