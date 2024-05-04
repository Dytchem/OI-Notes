#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
// constexpr ll INF = 0x7fffffffffffffff;
// inline ll CEIL(ll a, ll b) { return (a - 1) / b + 1; }

struct s {
	int id;
	int degree;
	vector<int> nxt;
}ss[200001];

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1;i <= n;++i) {
		ss[i].id = i;
		cin >> ss[i].degree;
		sum += ss[i].degree;
	}
	if ((sum >> 1) != n - 1 || n == 1) {
		cout << -1;
		return 0;
	}

	sort(ss + 1, ss + n + 1, [](const s& s1, const s& s2) {return s1.degree > s2.degree;});

	ss[1].nxt.reserve(ss[1].degree);
	int now = 2;
	for (;now <= 1 + ss[1].degree;) {
		q.push(now);
		ss[1].nxt.push_back(now++);
	}

	while (!q.empty()) {
		int r = q.front();
		q.pop();
		ss[r].nxt.reserve(ss[r].degree - 1);
		for (int i = 1;i < ss[r].degree;++i) {
			if (now == n + 1) {
				cout << -1;
				return 0;
			}
			q.push(now);
			ss[r].nxt.push_back(now++);
		}
	}



	for (int i = 1;i <= n;++i) {
		for (int j : ss[i].nxt) {
			cout << ss[i].id << ' ' << ss[j].id << '\n';
		}
	}
}