#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

// f(1)=k, f(x)f(y)=f(x+y)+f(x-y) => f(t)=f(x)f(t-x)-f(2x-t) 应使 t=ceil(t/2)

ll m, k, n;
map<ll, ll> stf;

ll f(ll t)
{
	if (t == 0)
		return 2;
	if (t == 1)
		return k;
	if (stf[t])
		return stf[t];
	ll x = (t + 1) / 2;
	ll d = 2 * x - t;
	ll fx = f(x);
	if (d)
		return stf[t] = (fx * f(t - x) - f(d)) % m;
	else
		return stf[t] = (fx * fx - 2) % m;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	cin >> m >> k >> n;
	cout << (f(n) + m) % m;
}