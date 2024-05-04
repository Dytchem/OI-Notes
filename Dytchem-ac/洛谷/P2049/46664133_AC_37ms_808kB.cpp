#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <memory>

using namespace std;
typedef long long ll;
constexpr int Inf = 0x3f3f3f3f;
// #define int long long

template <typename T>
inline void read(T &a)
{
	a = 0;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		a = (a << 1) + (a << 3) + (c ^ 48);
		c = getchar();
	}
}

int m, n, k;
int a[101][101];
bitset<100> stf[101][101];

void f(int m, int n)
{
	if (m < 1 || n < 1 || stf[m][n].any())
		return;
	f(m - 1, n), f(m, n - 1);
	for (int i = 0; i < k; ++i)
	{
		if (stf[m - 1][n][i] || stf[m][n - 1][i])
			stf[m][n][i * a[m][n] % k] = true;
	}
}

int main()
{
	read(m), read(n), read(k);
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			read(a[i][j]);
	stf[1][1][a[1][1] % k] = true;
	f(m, n);
	printf("%d\n", (int)stf[m][n].count());
	for (int i = 0; i < k; ++i)
		if (stf[m][n][i])
			printf("%d ", i);
}