#include <iostream>
#include <queue>
using namespace std;
const int Inf = 0x7fffffff;

int a, b;
const int maxn = 200005;
int dis[maxn];

queue<int> q;

int main() {
	cin >> a >> b;
	// bfs;
	dis[a] = 0;
	q.push(a);
	while (!q.empty()) {
		int x = q.front();
		// cout << x << '\n';
		if (x == b) break;
		q.pop();
		if (x * 2 != a && x * 2 < maxn && dis[x * 2] == 0) q.push(x * 2), dis[x * 2] = dis[x] + 1;
		if (x + 1 != a && x + 1 < maxn && dis[x + 1] == 0) q.push(x + 1), dis[x + 1] = dis[x] + 1;
		if (x - 1 != a && x - 1 >= 0 && dis[x - 1] == 0) q.push(x - 1), dis[x - 1] = dis[x] + 1;
	}
	cout << dis[b];
}