#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

struct point {
	int x, y, z, d;
	point(int X, int Y, int Z, int D) :x(X), y(Y), z(Z), d(D) {}
};

bool road[32][32][32];
int dx[] = { 1,0,-1,0,0,0 }, dy[] = { 0,1,0,-1,0,0 }, dz[] = { 0,0,0,0,1,-1 };

int main() {
	ios::sync_with_stdio(false);
	while (true) {
		int L, R, C;
		cin >> L >> R >> C;
		if (L == 0) return 0;
		int x0, y0, z0, x1, y1, z1;
		memset(road, 0, sizeof(road));
		for (int i = 1;i <= L;++i) {
			for (int j = 1;j <= R;++j) {
				for (int k = 1;k <= C;++k) {
					char c;
					cin >> c;
					switch (c) {
					case '.':road[i][j][k] = true;break;
					case 'S':x0 = i, y0 = j, z0 = k;break;
					case 'E':x1 = i, y1 = j, z1 = k, road[i][j][k] = true;break;
					}
				}
			}
		}

		/*for (int i = 1;i <= L;++i) {
			for (int j = 1;j <= R;++j) {
				for (int k = 1;k <= C;++k) {
					cout << road[i][j][k];
				}
				cout << '\n';
			}
			cout << '\n';
		}*/

		queue<point> q;
		q.push(point(x0, y0, z0, 0));
		while (!q.empty()) {
			const int x = q.front().x, y = q.front().y, z = q.front().z, d = q.front().d;
			// cout << x << ' ' << y << ' ' << z << ' ' << d << '\n';
			if (x == x1 && y == y1 && z == z1) break;
			q.pop();
			for (int i = 0;i < 6;++i) {
				const int x1 = x + dx[i], y1 = y + dy[i], z1 = z + dz[i];
				if (!road[x1][y1][z1]) continue;
				road[x1][y1][z1] = false;
				q.push(point(x1, y1, z1, d + 1));
			}
		}
		if (q.empty()) cout << "Trapped!\n";
		else cout << "Escaped in " << q.front().d << " minute(s).\n";
	}
}