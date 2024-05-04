#include <cstdio>
#include <set>
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

struct info
{
	ll x;
	int y;
	int id;
	bool operator<(const info &i) const { return x < i.x; }
};

set<info> s;
const int bound = 3e4;
set<info> big;

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
				big.insert(info{x, y, i});
			else
				s.insert(info{x, y, i});
			if (rm < y)
				rm = y;
		}
		else
		{
			const ll xs = x - rm, xm = x + rm;
			auto it = s.lower_bound(info{xs, 0, 0});
			auto bt = big.lower_bound(info{xs, 0, 0});
			while (true)
			{
				ll mi, ma;
				if (bt != big.end())
				{
					const ll x1 = bt->x, y1 = bt->y, dx = x - x1, dy = y - y1;
					if (dx * dx + dy * dy < y1 * y1)
					{
						printf("%d\n", bt->id);
						big.erase(bt);
						goto END;
					}
					const ll b1 = -(x1 << 1) + (y1 << 2), b2 = -(x1 << 1) - (y1 << 2);
					const ll x1x1 = x1 * x1, xy14 = (x * y1) << 2;
					mi = x1 < x ? solvemi(1, b1, x1x1 - xy14) : solvemi(1, b2, x1x1 + xy14);
					ma = x1 < x ? solvema(1, b1, x1x1 - xy14) : solvema(1, b2, x1x1 + xy14);
					++bt;
				}
				else
					mi = xm;
				ll x1, y1, dx, dy, xn;
			HERE:
				if (it == s.end())
					break;
				x1 = it->x;
				if (x1 > xm)
					break;
				y1 = it->y;
				dx = x - x1;
				dy = y - y1;
				//printf("%lld %lld\n", x1, y1);
				if (dx * dx + dy * dy < y1 * y1)
				{
					printf("%d\n", it->id);
					s.erase(it);
					goto END;
				}
				if (x1 > mi)
				{
					it = s.lower_bound(info{ma, 0, 0});
					continue;
				}
				xn = x1 < x ? solvema(1, -(x1 << 1) + (y1 << 2), x1 * x1 - (x * y1 << 2)) : solvema(1, -(x1 << 1) - (y1 << 2), x1 * x1 + (x * y1 << 2));
				if (xn <= x1)
					++it;
				else
					it = s.lower_bound(info{xn, 0, 0});
				goto HERE;
			}
			printf("-1\n");
		}
	END:
		continue;
	}
}