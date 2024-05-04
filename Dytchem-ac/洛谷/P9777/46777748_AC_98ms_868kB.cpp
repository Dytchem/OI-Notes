#include <iostream>

using namespace std;
typedef long long ll;
#define int long long

int m, k, n;

struct mat
{
	int a[2][2];
	inline void p2()
	{
		int b[2][2];
		b[0][0] = (a[0][0] * a[0][0] + a[0][1] * a[1][0]) % m;
		b[0][1] = (a[0][0] * a[0][1] + a[0][1] * a[1][1]) % m;
		b[1][0] = (a[1][0] * a[0][0] + a[1][1] * a[1][0]) % m;
		a[1][1] = (a[1][0] * a[0][1] + a[1][1] * a[1][1]) % m;
		a[0][0] = b[0][0], a[0][1] = b[0][1], a[1][0] = b[1][0];
	}
};

struct vec
{
	int a[2];
	inline void rm(const mat &ma)
	{
		int b = (ma.a[0][0] * a[0] + ma.a[0][1] * a[1]) % m;
		a[1] = (ma.a[1][0] * a[0] + ma.a[1][1] * a[1]) % m;
		a[0] = b;
	}
};

signed
main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> m >> k >> n;

	mat A;
	A.a[0][0] = k, A.a[0][1] = -1, A.a[1][0] = 1, A.a[1][1] = 0;
	vec v;
	v.a[0] = k, v.a[1] = 2;
	while (n)
	{
		if (n & 1)
			v.rm(A);
		A.p2();
		n >>= 1;
	}
	cout << (v.a[1] + m) % m;
}