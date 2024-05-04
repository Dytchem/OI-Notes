#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int INF = 0x7fffffff;

int n;
pair<int, int> ps[100];

int main() {
	cin >> n;
	for (int i = 0;i < n;++i) cin >> ps[i].first >> ps[i].second;
	auto p1 = *max_element(ps, ps + n);
	auto p2 = *min_element(ps, ps + n);
	int a = p1.first - p2.first;
	int b = p1.second - p2.second;
	if (n == (a + 1) * (b + 1) && p1.first >= 0 && p1.second >= 0 && p2.first <= 0 && p2.second <= 0) {
		cout << a + b;
	}
	else {
		cout << -1;
	}
}