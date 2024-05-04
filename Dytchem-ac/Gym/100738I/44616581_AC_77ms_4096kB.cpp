#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
constexpr int INF = 0x7fffffff;
// inline ll CEIL(ll a, ll b) { return (a - 1) / b + 1; }

struct node {
	vector<int> nxt;
}nodes[100001];

int n, k;
int cnt_tmp[100001];

int cnt(const int root, bool isReturn) {
	if (isReturn && cnt_tmp[root] != 0) return cnt_tmp[root];
	const int size = nodes[root].nxt.size();
	if (size == 0) return 1;
	int re = 1;
	if (isReturn) {
		priority_queue<int> q;
		for (int i : nodes[root].nxt) {
			q.push(cnt(i, true));
		}
		for (int j = 1;j <= k - 1 && !q.empty();++j) {
			re += q.top();
			q.pop();
		}
		cnt_tmp[root] = re;
	}
	else {
		for (int i : nodes[root].nxt) {
			priority_queue<int> q;
			int tmp = 1 + cnt(i, false);
			for (int j : nodes[root].nxt) {
				if (j == i) continue;
				q.push(cnt(j, true));
			}
			for (int j = 1;j <= k - 1 && !q.empty();++j) {
				tmp += q.top();
				q.pop();
			}
			if (re < tmp) re = tmp;
		}
	}
	return re;
}


int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1;i <= n;++i) {
		int size;
		cin >> size;
		nodes[i].nxt.reserve(size);
		for (int j = 0;j < size;++j) {
			int nxt;
			cin >> nxt;
			nodes[i].nxt.push_back(nxt);
		}
	}

	cout << cnt(1, false);
}