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

ll sma, smi;
inline void solve(ll a, ll b, ll c)
{
	const double det = sqrt(b * b - (a * c << 2));
	sma = ceil((det - b) / (a << 1));
	smi = floor((-det - b) / (a << 1));
}

struct info
{
	int x, y, id;
	bool operator<(const info &i) const { return x < i.x; }
};

set<info> s;
const int bound = 1e6;
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
			const int xs = x - rm, xm = x + rm;
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
					if (x1 < x)
						solve(1, -(x1 << 1) + (y1 << 2), x1 * x1 - (x * y1 << 2));
					else
						solve(1, -(x1 << 1) - (y1 << 2), x1 * x1 + (x * y1 << 2));
					mi = smi;
					ma = sma;
					if (ma > xm)
						bt = big.end();
					else
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
					it = s.lower_bound(info{(int)ma, 0, 0});
					continue;
				}
				if (x1 < x)
					solve(1, -(x1 << 1) + (y1 << 2), x1 * x1 - (x * y1 << 2));
				else
					solve(1, -(x1 << 1) - (y1 << 2), x1 * x1 + (x * y1 << 2));
				xn = sma;
				if (xn <= x1)
					++it;
				else
					it = s.lower_bound(info{(int)xn, 0, 0});
				goto HERE;
			}
			printf("-1\n");
		}
	END:
		continue;
	}
}