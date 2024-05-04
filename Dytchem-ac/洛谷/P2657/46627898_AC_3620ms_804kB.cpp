#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <memory>
using namespace std;
typedef long long ll;
constexpr int Inf = 0x3f3f3f3f;
#define int long long

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

const int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int a, b;

int ans = 0;

void dfs(int now, int p, int f)
{
	//printf("%d %d\n", now, ans);
	if (p == -1)
	{
		if (a <= now && now <= b)
			++ans;
		return;
	}
	ll pre = now / pow10[p] / 10;
	if (pre * pow10[p] * 10 > b || (pre + 1) * pow10[p] * 10 - 1 < a)
		return;
	if (f)
	{
		dfs(0, p - 1, true);
		for (int i = 1; i < 10; ++i)
			dfs(now + i * pow10[p], p - 1, false);
	}
	else
	{
		int res = pre % 10;
		for (int i = res - 2; i > -1; --i)
			dfs(now + i * pow10[p], p - 1, false);
		for (int i = res + 2; i < 10; ++i)
			dfs(now + i * pow10[p], p - 1, false);
	}
}

signed main()
{
	read(a), read(b);
	dfs(0, 9, true);
	printf("%lld", ans);
}