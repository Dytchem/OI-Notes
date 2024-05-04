#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <memory>
using namespace std;
typedef long long ll;
constexpr int Inf = 0x3f3f3f3f;

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

int n, m;
int a[100], stmi[100][100][10], stma[100][100][10];
int pre[101];

int mi(int l, int r, int m)
{
	if (stmi[l][r][m] != Inf)
		return stmi[l][r][m];
	int re = Inf;
	if (m == 1)
		re = ((pre[r + 1] - pre[l]) % 10 + 10) % 10;
	else
		for (int i = l + m - 2; i < r; ++i)
		{
			// printf("%d %d %d \n", l, i, r);
			re = min(re, mi(l, i, m - 1) * mi(i + 1, r, 1));
		}
	stmi[l][r][m] = re;
	if (r < n)
		stmi[l + n][r + n][m] = re;
	if (l >= n)
		stmi[l - n][r - n][m] = re;
	//printf("%d %d %d %d\n", l, r, m, re);
	return re;
}

int ma(int l, int r, int m)
{
	if (stma[l][r][m] != Inf)
		return stma[l][r][m];
	int re = 0;
	if (m == 1)
		re = ((pre[r + 1] - pre[l]) % 10 + 10) % 10;
	else
		for (int i = l + m - 2; i < r; ++i)
		{
			re = max(re, ma(l, i, m - 1) * ma(i + 1, r, 1));
		}
	stma[l][r][m] = re;
	if (r < n)
		stma[l + n][r + n][m] = re;
	if (l >= n)
		stma[l - n][r - n][m] = re;
	return re;
}

int main()
{
	memset(stmi, 0x3f, sizeof(stmi));
	memset(stma, 0x3f, sizeof(stma));

	read(n), read(m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for (int i = 0; i < 2 * n; ++i)
	{
		pre[i + 1] = pre[i] + a[i];
		//printf("%d\n", pre[i + 1]);
	}

	int ansmi = Inf, ansma = 0;

	for (int l = 0, r = n - 1; l < n; ++l, ++r)
	{
		ansmi = min(ansmi, mi(l, r, m));
		ansma = max(ansma, ma(l, r, m));
		//printf("%d %d\n", ansmi, ansma);
	}
	printf("%d\n%d", ansmi, ansma);
}