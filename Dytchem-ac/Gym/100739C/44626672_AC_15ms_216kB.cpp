#include <bits/stdc++.h>
using namespace std;

struct s {
	int x, y, r, d;
	s(int X, int Y, int R, int D) {
		x = X;
		y = Y;
		r = R;
		d = D;
	}
};

int n;
char a[205][205];
bool vis[205][205][4];
queue<s> ps;

int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
int bfs() {
	vis[1][1][0] = true;
	ps.push(s(1, 1, 0, 0));
	while (!ps.empty()) {
		const int x = ps.front().x;
		const int y = ps.front().y;
		const int r = ps.front().r;
		const int d = ps.front().d;
		// cout << x << ' ' << y << ' ' << r << ' ' << d << '\n';
		ps.pop();
		const int x1 = x + dx[r];
		const int y1 = y + dy[r];
		if (a[x1][y1] == '.' && !vis[x1][y1][r]) {
			if (x1 == n && y1 == n && r == 0) {
				return d + 1;
			}
			ps.push(s(x1, y1, r, d + 1));
			vis[x1][y1][r] = true;
		}
		const int r1 = (r + 1) % 4;
		if (!vis[x][y][r1]) {
			if (x == n && y == n && r1 == 0) {
				return d + 1;
			}
			ps.push(s(x, y, r1, d + 1));
			vis[x][y][r1] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 1;i <= n;++i) {
		for (int j = 1;j <= n;++j) {
			cin >> a[i][j];
		}
	}

	cout << bfs();
}