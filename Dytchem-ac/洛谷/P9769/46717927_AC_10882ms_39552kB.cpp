#include <iostream>
#include <deque>

using namespace std;
typedef long long ll;
constexpr int Inf = 0x3f3f3f3f;
#define int long long

int y, n, m;
int a[10];
int dp[5000006];

struct P
{
	int val, pos;
	inline bool operator<(const P &p) const { return val < p.val; }
};

signed
main()
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
	deque<P> q;
	for (int o = 1; o <= n; ++o)
		dp[o] = 1;
	q.push_back(P{1, n});
	for (int o = n + 1; o <= y; ++o)
	{
		if (q.front().pos < o - n)
			q.pop_front();
		dp[o] = q.front().val + 1;
		for (int i = 0; i < m; ++i)
		{
			if (o % a[i])
				continue;
			dp[o] = min(dp[o], dp[o / a[i]] + 1);
		}
		//while (!q.empty() && q.back().val >= dp[o])
		//	q.pop_back();
		q.resize(lower_bound(q.begin(), q.end(), P{dp[o], o}) - q.begin());
		//q.end() = lower_bound(q.begin(), q.end(), P{dp[o], o});
		q.push_back(P{dp[o], o});
	}
	cout << dp[y];
}