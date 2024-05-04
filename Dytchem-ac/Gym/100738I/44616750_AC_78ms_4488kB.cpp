#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
constexpr int INF = 0x7fffffff;
// inline ll CEIL(ll a, ll b) { return (a - 1) / b + 1; }

struct node
{
	vector<int> nxt;
} nodes[100001];

int n, k;
int mp[100001];
int tmp[100001];

int cnt(const int root, bool isReturn)
{
	if (isReturn && tmp[root])
		return tmp[root];
	if (nodes[root].nxt.empty())
		return 1;
	int re0 = 1, re = 1;
	priority_queue<pair<int, int>> pq;
	// map<int, int> mp;
	for (int i : nodes[root].nxt)
	{
		pq.push(make_pair(cnt(i, true), i));
	}
	for (int j = 1; j <= k - 1 && !pq.empty(); ++j)
	{
		re0 += pq.top().first;
		mp[pq.top().second] = pq.top().first;
		pq.pop();
	}

	if (isReturn)
		tmp[root] = re = re0;
	else
	{
		for (int i : nodes[root].nxt)
		{
			if (mp[i])
			{
				if (pq.empty())
					re = max(re, re0 + cnt(i, false) - mp[i]);
				else
					re = max(re, re0 + cnt(i, false) - mp[i] + pq.top().first);
			}
			else
			{
				re = max(re, re0 + cnt(i, false));
			}
			mp[i] = 0;
		}
	}
	return re;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		int size;
		cin >> size;
		nodes[i].nxt.reserve(size);
		for (int j = 0; j < size; ++j)
		{
			int nxt;
			cin >> nxt;
			nodes[i].nxt.push_back(nxt);
		}
	}

	cout << cnt(1, false);
}