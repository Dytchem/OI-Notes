#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <memory>

using namespace std;
typedef long long ll;
constexpr int     Inf = 0x3f3f3f3f;
// #define int long long

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

// const int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int a, b;
int p[11];
int stf[10][10];

int f(int res, int now, bool flag)  // flag代表前面数位是否饱和
{
    if (now == -1)
        return 1;
    int re = 0;
    if (flag) {
        if (res == -2) {  // res = -2代表前导0
            if (p[now] == 0)
                re += f(-2, now - 1, true);
            else
                re += f(-2, now - 1, false);
            for (int i = 1; i <= p[now]; ++i)
                re += f(i, now - 1, i == p[now]);
            return re;
        }
        else {
            for (int i = 0; i <= p[now]; ++i) {
                if (abs(i - res) < 2)
                    continue;
                re += f(i, now - 1, i == p[now]);
            }
            return re;
        }
    }
    else {
        if (res == -2) {
            re += f(-2, now - 1, false);
            for (int i = 1; i <= 9; ++i)
                re += f(i, now - 1, false);
            return re;
        }
        else {
            if (stf[res][now] != Inf)
                return stf[res][now];
            for (int i = res - 2; i >= 0; --i)
                re += f(i, now - 1, false);
            for (int i = res + 2; i <= 9; ++i)
                re += f(i, now - 1, false);
            return stf[res][now] = re;
        }
    }
}

int work(int a)
{
    for (int i = 0; i <= 10; ++i) {
        p[i] = a % 10;
        a /= 10;
    }
    return f(-2, 9, true);
}

signed main()
{
    memset(stf, 0x3f, sizeof(stf));
    read(a), read(b);
    printf("%d", work(b) - work(a - 1));
}