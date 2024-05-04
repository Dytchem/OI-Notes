#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;
constexpr int Inf = 0x3f3f3f3f;
#define int long long

int y, n, m;
int a[10];
int dp[5000006];

namespace dddl
{
int q[5000006], bgn = 1, bgn1 = 1, end = 1;
inline void push(int v)
{
	if (v <= q[bgn1])
		bgn1 = end;
	q[end++] = v;
}
inline void pop()
{
	++bgn;
	bgn1 = max(bgn1, bgn);
}
inline int qmin()
{
	return q[bgn1];
}
} // namespace dddl

using namespace dddl;

signed main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	cin >> y >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a[i];
		if (a[i] == 1)
			--m, --i;
	}
	sort(a, a + m);
	for (int o = 1; o <= y; ++o)
	{
		push(dp[o - 1]);
		if (o > n)
			pop();
		dp[o] = qmin() + 1;
		for (int i = 0; i < m; ++i)
		{
			if (o % a[i])
				continue;
			dp[o] = min(dp[o], dp[o / a[i]] + 1);
		}
	}
	//for (int i = 1; i <= y; ++i)
	//	cout << dp[i] << ' ';

	cout << dp[y];
}