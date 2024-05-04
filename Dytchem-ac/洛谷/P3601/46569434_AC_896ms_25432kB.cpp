#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

template <typename T>
inline void read(T& a)
{
    a      = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        a = (a << 1) + (a << 3) + (c ^ 48);
        c = getchar();
    }
}

const int   maxsize = 1000006;
const ll    MOD     = 666623333;
bool        vis[maxsize];
vector<int> ps;
ll          a[maxsize], b[maxsize], val[maxsize];

inline void init()
{
    for (int i = 2; i <= maxsize; ++i) {
        if (!vis[i])
            ps.push_back(i);
        for (int p : ps) {
            if (i * p > maxsize)
                break;
            vis[i * p] = true;
            if (i % p == 0)
                break;
        }
    }
    // for (int i:ps) printf("%d ",i);
}

int main()
{
    init();
    ll l, r;
    read(l), read(r);
    ll ans = (l + r) * (r - l + 1) / 2 % MOD;
    for (ll x = l; x <= r; ++x) {
        a[x - l] = b[x - l] = x;
        val[x - l]          = 1;
    }
    for (ll p : ps) {
        for (ll x = (l - 1) / p * p + p; x <= r; x += p) {
            b[x - l] /= p;
            do {
                a[x - l] /= p;
            } while (a[x - l] % p == 0);
            val[x - l] *= p - 1;
        }
    }
    for (ll x = l; x <= r; ++x) {
        if (a[x - l] == 1)
            ans -= b[x - l] * val[x - l];
        else
            ans -= b[x - l] / a[x - l] * (a[x - l] - 1) * val[x - l];
    }
    printf("%lld", (ans % MOD + MOD) % MOD);
}