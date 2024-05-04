#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// f(1)=k, f(x)f(y)=f(x+y)+f(x-y) => f(t)=f(x)f(t-x)-f(2x-t) 应使 t=ceil(t/2)

ll m, k, n;
ll stf[50000007];

ll f(ll t)
{
	if (t < 50000007 && stf[t])
		return stf[t];
	ll x = (t + 1) / 2;
	ll d = 2 * x - t;
	ll fx = f(x);
	ll re;
	if (d)
		re = (fx * f(t - x) - f(d)) % m;
	else
		re = (fx * fx - 2) % m;
	if (t < 50000007)
		stf[t] = re;
	return re;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	cin >> m >> k >> n;

	stf[0] = 2, stf[1] = k;
	cout << (f(n) + m) % m;
}