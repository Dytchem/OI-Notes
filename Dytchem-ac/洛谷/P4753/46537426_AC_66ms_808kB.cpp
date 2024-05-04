#include <iostream>
using namespace std;

const int N = 100005;
int a[N], ans[N], p = -1;

int main()
{
	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 1; i <= m; ++i)
		cin >> a[i];
	a[m + 1] = n;
	int last = 0;
	for (int i = 1; i <= m + 1; ++i)
	{
		if (a[i] - last < s)
			continue;
		last = a[i];
		a[i] = -1;
		ans[++p] = i;
	}
	if (last != n)
	{
		cout << "NO";
		return 0;
	}
	for (int i = m; i >= 0; --i)
	{
		if (a[i] == -1)
			continue;
		if (last - a[i] < s)
		{
			cout << "NO";
			return 0;
		}
		last = a[i];
		a[i] = 0;
		ans[++p] = i;
	}
	if (last != 0)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for (int i = 0; i <= p; ++i)
		cout << ans[i] << ' ';
}