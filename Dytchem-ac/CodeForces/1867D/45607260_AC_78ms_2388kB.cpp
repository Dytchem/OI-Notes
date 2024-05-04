#include <iostream>
#include <bitset>
#include <cstring>
#include <memory>
#include <vector>
using namespace std;

const int maxn = 200005;
int a[maxn];
long long dis[maxn], d = 0;
bitset<maxn> vis;

int solve()
{
	memset(&vis, 0, sizeof(vis));
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	if (k == 1)
	{
		for (int i = 1; i <= n; ++i)
			if (a[i] != i)
				return cout << "NO", 0;
		return cout << "YES", 0;
	}

	bool f = false;
	for (int i = 1; i <= n; ++i)
	{
		if (vis[i])
			continue;
		int j = i;
		long long d0 = d, cnt;
		// memset(dis + 1, 0, sizeof(int) * n);
		while (dis[j] <= d0)
		{
			if (vis[j])
				goto end;
			vis[j] = true;
			dis[j] = ++d;
			j = a[j];
		}
		cnt = d + 1 - dis[j];

		if (cnt != k)
			return cout << "NO", 0;
		else if (cnt == k)
			f = true;
	end:
		continue;
	}
	if (f)
		return cout << "YES", 0;
	else
		return cout << "NO", 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << '\n';
	}
}