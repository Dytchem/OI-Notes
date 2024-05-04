#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <memory>

using namespace std;

int n;
char s[101][101];
inline int check(int x, int y)
{
	if (x < 1 || y < 1 || x > n || y > n)
		return -1;
	else if (s[x][y] == 'J')
		return 1;
	else if (s[x][y] == 'B')
		return -1;
	else
		return 0;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int cnt0 = check(i, j);
			for (int x = 1; x <= n; ++x)
			{
				for (int y = 1; y <= n; ++y)
				{
					int dx = y - j, dy = i - x;
					int cnt = cnt0 + check(x, y) + check(i + dx, j + dy) + check(x + dx, y + dy);
					if (cnt >= 3)
					{
						ans = max(ans, dx * dx + dy * dy);
					}
				}
			}
		}
	}
	cout << ans;
}