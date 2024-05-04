#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
constexpr int maxn = 52;

struct point { int x, y; point(int x, int y) :x(x), y(y) {} };

vector<point> wenhao;
const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
char cell[maxn][maxn];
bool vis[maxn][maxn], vis1[maxn][maxn];
int n, m;

bool check() {
	memset(vis, 0, sizeof(vis));
	bool flag = false;
	for (int i = 1;i <= n;++i) {
		for (int j = 1;j <= m;++j) {
			if (cell[i][j] == '.' && !vis[i][j]) {
				if (flag) return false;
				flag = true;
				queue<point> q;
				q.push(point(i, j));
				vis[i][j] = true;
				while (!q.empty()) {
					const int x = q.front().x, y = q.front().y;
					q.pop();
					for (int i = 0;i < 4;++i) {
						const int x1 = x + dx[i], y1 = y + dy[i];
						if (vis[x1][y1]) continue;
						vis[x1][y1] = true;
						switch (cell[x1][y1]) {
						case '.':
						case '?':
							q.push(point(x1, y1));break;
						default:continue;
						}
					}
				}
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1;i <= n;++i) {
		for (int j = 1;j <= m;++j) {
			cin >> cell[i][j];
			if (cell[i][j] == '?') wenhao.push_back(point(i, j));
		}
	}

	if (check()) {
		copy(&vis[1][1], &vis[n][m] + 1, &vis1[1][1]);
		for (point& p : wenhao) {
			if (vis1[p.x][p.y]) cell[p.x][p.y] = '.';
			else cell[p.x][p.y] = '#';
		}
		/*for (int i = 1;i <= n;++i) {
			for (int j = 1;j <= m;++j) {
				cout << cell[i][j];
			}
			cout << '\n';
		}*/
		for (point& p : wenhao) {
			if (vis1[p.x][p.y]) {
				cell[p.x][p.y] = '#';
				if (check()) {
					cout << "Ambiguous";
					return 0;
				}
				cell[p.x][p.y] = '.';
			}
		}
		for (int i = 1;i <= n;++i) {
			for (int j = 1;j <= m;++j) {
				cout << cell[i][j];
			}
			cout << '\n';
		}
	}
	else {
		cout << "Impossible";
	}
}

/*
5 7
?#####?
#.###.#
#.###.#
#.???.#
?#####?

1 3
..?
*/
