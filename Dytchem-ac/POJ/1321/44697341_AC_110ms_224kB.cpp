#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int n, k;
vector<pair<int, int>> v;
int cnt;
bool row[9], col[9];

void dfs(const int i, const int t) {
	if (row[v[i].first] || col[v[i].second]) return;
	if (t == k) {
		++cnt;
		return;
	}
	row[v[i].first] = col[v[i].second] = true;
	for (int j = i + 1;j < v.size();++j) {
		dfs(j, t + 1);
	}
	row[v[i].first] = col[v[i].second] = false;
}

int alldfs() {
	cnt = 0;
	for (int i = 0;i < v.size();++i) dfs(i, 1);
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	while (true) {
		v.clear();
		cin >> n >> k;
		if (n == -1) break;
		for (int i = 1;i <= n;++i) {
			for (int j = 1;j <= n;++j) {
				char c;
				cin >> c;
				if (c == '#') v.push_back(make_pair(i, j));
			}
		}
		cout << alldfs() << '\n';
	}
}