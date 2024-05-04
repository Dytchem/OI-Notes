#include <cstdio>
#include <set>
#include <tuple>
#include <cmath>
using namespace std;
typedef long long ll;

template <typename T>
inline void read(T &a)
{
	a = 0;
	char c = getchar();
	while (c < '0' || c > '9')
		c = getchar();
	while (c >= '0' && c <= '9')
	{
		a = (a << 1) + (a << 3) + (c ^ 48);
		c = getchar();
	}
}

inline ll solvema(ll a, ll b, ll c)
{
	return ceil((sqrt(b * b - 4 * a * c) - b) / (2 * a));
}

inline ll solvemi(ll a, ll b, ll c)
{
	return floor((-sqrt(b * b - 4 * a * c) - b) / (2 * a));
}

set<tuple<int, int, int>> s; // x, y, id
const int bound = 1e6;
set<tuple<int, int, int>> big;

int rm;

int main()
{
	int n;
	read(n);
	for (int i = 1; i <= n; ++i)
	{
		int t, x, y;
		read(t);
		read(x);
		read(y);
		if (t == 1)
		{
			if (y > bound)
				big.insert(make_tuple(x, y, i));
			else
				s.insert(make_tuple(x, y, i));
			if (rm < y)
				rm = y;
		}
		else
		{
			const ll xs = x - rm, xm = x + rm;
			if (false)
			{
				auto bt = big.lower_bound(make_tuple(xs, 0, 0));
				while (bt != big.end())
				{
					const ll x1 = get<0>(*bt);
					if (x1 > xm)
						break;
					const ll y1 = get<1>(*bt), dx = x - x1, dy = y - y1;
					if (dx * dx + dy * dy < y1 * y1)
					{
						printf("%d\n", get<2>(*bt));
						s.erase(bt);
						goto END;
					}
					ll xn = x1 < x ? solvema(1, -2 * x1 + 4 * y1, x1 * x1 - 4 * x * y1) : solvema(1, -2 * x1 - 4 * y1, x1 * x1 + 4 * x * y1);
					if (xn <= x1)
						++bt;
					else
						bt = big.lower_bound(make_tuple(xn, 0, 0));
				}
			}
			else
			{
				auto it = s.lower_bound(make_tuple(xs, 0, 0));
				auto bt = big.lower_bound(make_tuple(xs, 0, 0));
				while (true)
				{
					ll mi, ma;
					if (bt != big.end())
					{
						const ll x1 = get<0>(*bt), y1 = get<1>(*bt), dx = x - x1, dy = y - y1;
						if (dx * dx + dy * dy < y1 * y1)
						{
							printf("%d\n", get<2>(*bt));
							big.erase(bt);
							goto END;
						}
						mi = x1 < x ? solvemi(1, -2 * x1 + 4 * y1, x1 * x1 - 4 * x * y1) : solvemi(1, -2 * x1 - 4 * y1, x1 * x1 + 4 * x * y1);
						ma = x1 < x ? solvema(1, -2 * x1 + 4 * y1, x1 * x1 - 4 * x * y1) : solvema(1, -2 * x1 - 4 * y1, x1 * x1 + 4 * x * y1);
						++bt;
					}
					else
						mi = xm;
					ll x1, y1, dx, dy;
				HERE:
					if (it == s.end())
						break;
					x1 = get<0>(*it);
					if (x1 > xm)
						break;
					y1 = get<1>(*it);
					dx = x - x1;
					dy = y - y1;
					//printf("%lld %lld\n", x1, y1);
					if (dx * dx + dy * dy < y1 * y1)
					{
						printf("%d\n", get<2>(*it));
						s.erase(it);
						goto END;
					}
					if (x1 > mi)
					{
						it = s.lower_bound(make_tuple(ma, 0, 0));
						continue;
					}
					ll xn = x1 < x ? solvema(1, -2 * x1 + 4 * y1, x1 * x1 - 4 * x * y1) : solvema(1, -2 * x1 - 4 * y1, x1 * x1 + 4 * x * y1);
					if (xn <= x1)
						++it;
					else
						it = s.lower_bound(make_tuple(xn, 0, 0));
					goto HERE;
				}
			}
			printf("-1\n");
		}
	END:
		continue;
	}
}