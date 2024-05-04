#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <memory>
using namespace std;
typedef long long ll;
constexpr int Inf = 0x3f3f3f3f;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

int n;
const ll mod = 0xffffffff;
ll cnt[32];
bool st[2][2][2][2];

inline ll num(int p, int type)
{
	if (type == 0)
		return n - cnt[p];
	else
		return cnt[p];
}

inline ll num(int p, int i, int j, int k, int l)
{
	return (num(p, i) * num(p, j) * num(p, k) & mod) * num(p, l) & mod;
}

int main()
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				for (int l = 0; l < 2; ++l)
					st[i][j][k][l] = (i | j) ^ (k & l);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		ll ai;
		cin >> ai;
		for (int p = 0; p < 32; ++p)
			cnt[p] += (ai >> p) & 1;
	}
	ll ans = 0;
	for (int p = 0; p < 32; ++p)
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k)
					for (int l = 0; l < 2; ++l)
						if (st[i][j][k][l])
							ans = (ans + (num(p, i, j, k, l) << p)) & mod;
	cout << ans;
}