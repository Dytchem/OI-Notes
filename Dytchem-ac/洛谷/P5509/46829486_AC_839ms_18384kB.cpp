#include <iostream>

using namespace std;
typedef long long ll;
constexpr int Inf = 0x3f3f3f3f;
#define int long long

// 答案 = (nk-1)!/[(nk-n)!(n-1)!(k-1)^(n-1)] = C(nk-1,n-1)/(k-1)^(n-1) ;

const int MOD = 1145141;
int fac[MOD]{1, 1}, inv[MOD]{1, 1};

inline int qpow(int a, int n)
{
	int re = 1;
	while (n)
	{
		if (n & 1)
			re = re * a % MOD;
		a = a * a % MOD;
		n >>= 1;
	}
	return re;
}

inline int Inv(int a)
{
	return qpow(a, MOD - 2);
}

inline void init()
{
	for (int i = 2; i < MOD; ++i)
	{
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = Inv(fac[i]);
	}
}

inline int ccnt(int n, int m)
{
	return n / MOD - m / MOD - (n - m) / MOD + n / MOD / MOD - m / MOD / MOD - (n - m) / MOD / MOD;
}

inline int qcnt(int a, int n)
{
	if (a % MOD)
		return 0;
	else
		return n;
}

inline int C(int n, int m)
{
	if (m == 0)
		return 1;
	int re = fac[n % MOD] * inv[m % MOD] % MOD * inv[(n - m) % MOD] % MOD * C(n / MOD, m / MOD) % MOD;
	if (ccnt(n, m) & 1)
		re = (-re + MOD) % MOD;
	return re;
}

inline int solve(int n, int k)
{
	int c = ccnt(n * k - 1, n - 1), q = qcnt(k - 1, n - 1);
	if (c > q)
		return 0;
	else if (c < q)
		return -1;
	else
		return C(n * k - 1, n - 1) * Inv(qpow(q ? (k - 1) / MOD : k - 1, (n - 1) % (MOD - 1))) % MOD;
}

signed main()
{
	init();
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		cout << solve(n, k) << '\n';
	}
}

/*

1
1000000000 1000000000

ans: 149914

*/