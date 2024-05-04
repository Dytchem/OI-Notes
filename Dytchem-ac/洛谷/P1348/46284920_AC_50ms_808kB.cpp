#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	int a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = a; i <= b; ++i)
	{
		ans += (i & 1) | !(i & 3);
	}
	cout << ans;
}