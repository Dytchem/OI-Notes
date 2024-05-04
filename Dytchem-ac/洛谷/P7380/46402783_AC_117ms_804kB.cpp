#include <bits/stdc++.h>
#define y0 y86274264781
using namespace std;
typedef long long ll;
constexpr int     Inf = 0x3f3f3f3f;
constexpr ll      INF = 0x3f3f3f3f3f3f3f3f;

struct p
{
    int x, y;
};

int  n;
bool have[602][602];
bool ans[305][305];
int  x0, y0;
int  xmin = -Inf, ymin = -Inf, xmax = Inf, ymax = Inf;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void bfs()
{
    queue<p> q;
    q.push(p{x0, y0});
    xmin = xmax = x0, ymin = ymax = y0;
    ans[x0][y0] = true;
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int xmid = 2 * x + dx[i], ymid = 2 * y + dy[i];
            if (!have[xmid][ymid]) continue;
            int x1 = x + dx[i], y1 = y + dy[i];
            if (!have[2 * x1][2 * y1] || ans[x1][y1]) continue;
            q.push(p{x1, y1});
            xmin = min(xmin, x1), xmax = max(xmax, x1);
            ymin = min(ymin, y1), ymax = max(ymax, y);
            ans[x1][y1] = true;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a *= 2, b *= 2, c *= 2, d *= 2;
        if (a == c) {
            for (int j = min(b, d); j <= max(b, d); ++j) have[a][j] = true;
        }
        else {
            for (int i = min(a, c); i <= max(a, c); ++i) have[i][b] = true;
        }
    }
    cin >> x0 >> y0;
    bfs();
    for (int i = ymax; i >= ymin; --i) {
        for (int j = xmin; j <= xmax; ++j) {
            if (ans[j][i])
                cout << '#';
            else
                cout << '.';
        }
        cout << '\n';
    }
}