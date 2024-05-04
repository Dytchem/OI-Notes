#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <memory>
#include <bitset>

using namespace std;

bitset<100005> b[7];

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int p, t;
		cin >> p >> t;
		b[p][t] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= 6; ++i)
	{
		for (int j = 1; j <= 100000;)
		{
			if (b[i][j])
				j += 60, ++ans;
			else
				j += 1;
		}
	}
	cout << ans;
}