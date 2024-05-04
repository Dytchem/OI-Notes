#include <iostream>
#include <deque>

#define end eeeeeeeee

using namespace std;
typedef long long ll;
constexpr int Inf = 0x3f3f3f3f;
#define int long long

int y, n, m;
int a[10];
int dp[5000006];
int val[5000006], pos[5000006], bgn = 1, end = 1;

signed
main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	cin >> y >> n >> m;
	if (y <= n)
	{
		cout << 1;
		return 0;
	}
	else if (y <= 2 * n)
	{
		cout << 2;
		return 0;
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> a[i];
		if (a[i] == 1)
			--m, --i;
	}
	sort(a, a + m);
	for (int o = 1; o <= n; ++o)
		dp[o] = 1;
	for (int o = n + 1; o <= 2 * n; ++o)
		dp[o] = 2;
	val[end] = 2, pos[end] = 2 * n, ++end;
	for (int o = 2 * n + 1; o <= y; ++o)
	{
		if (pos[bgn] < o - n)
			++bgn;
		dp[o] = val[bgn] + 1;
		for (int i = 0; i < m; ++i)
		{
			if (o % a[i])
				continue;
			dp[o] = min(dp[o], dp[o / a[i]] + 1);
		}
		end = lower_bound(&val[bgn], &val[end], dp[o]) - &val[bgn] + bgn;
		val[end] = dp[o], pos[end] = o, ++end;
	}
	cout << dp[y];
}