#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <memory>
using namespace std;
typedef long long ll;
constexpr int Inf = 0x3f3f3f3f;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

const int mod = 1e9 + 7;
const int maxn = 505;
int n, k;
char s[maxn];

ll dp[maxn][maxn][4]; // 0全 1单 2左* 3右*
ll ask(const int l, const int r, const int type = 0)
{
	if (dp[l][r][type] != INF)
		return dp[l][r][type];
	ll re = 0;
	if (r - l < 1)
		re = 0;
	else if (r - l == 1 && type < 2 && (s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?'))
		re = 1;
	else if (type == 0)
	{
		for (int mid = l + 1; mid <= r - 2; ++mid)
		{
			re = (re + ask(l, mid, 1) * (ask(mid + 1, r, 0) + ask(mid + 1, r, 2))) % mod;
		}
		re += ask(l, r, 1);
	}
	else if (type == 1)
	{
		if ((s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?'))
			re = (r - l - 1 <= k && all_of(&s[l + 1], &s[r - 1] + 1, [](const char &c) { return c == '*' || c == '?'; })) + ask(l + 1, r - 1, 0) + ask(l + 1, r - 1, 2) + ask(l + 1, r - 1, 3);
	}
	else if (type == 2)
	{
		for (int i = 1; i <= min(k, r - l - 1) && (s[l + i - 1] == '*' || s[l + i - 1] == '?'); ++i)
			re += ask(l + i, r, 0);
	}
	else if (type == 3)
	{
		for (int i = 1; i <= min(k, r - l - 1) && (s[r - i + 1] == '*' || s[r - i + 1] == '?'); ++i)
			re += ask(l, r - i, 0);
	}
	return dp[l][r][type] = re % mod;
}

int main()
{
	memset(dp, 0x3f, sizeof(dp));
	scanf("%d%d%s", &n, &k, s + 1);
	printf("%lld", ask(1, n) % mod);
	//printf("\n%lld\n%lld\n%lld", ask(6, 10), ask(6, 10, 1), ask(8, 8, 3));
	return 0;
}