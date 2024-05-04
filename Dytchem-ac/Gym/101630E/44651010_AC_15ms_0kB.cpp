#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 0x7fffffff;
constexpr ll INF = 0xfffffffffffffff;

int zero = 0;
int pos[1001];
vector<int> ans;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (a > 0) pos[a]++;
		else if (a == 0) zero++;
		else {
			if (pos[-a]) pos[-a]--;
			else if (zero > 0) {
				zero--;
				ans.push_back(-a);
			}
			else goto END;
		}
	}

	cout << "Yes\n";
	for (int i : ans) cout << i << ' ';
	while (zero--) cout << "1 ";


	if (false) {
	END:
		cout << "No";
	}
}