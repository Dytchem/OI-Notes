#pragma GCC optimize(3)
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
constexpr int Inf = 0x7fffffff;

char s[200005];
int w[200000] = { -1 };
int nxt[200000], nxt1[200000];

int main() {
	int k;
	scanf("%d%s", &k, s);
	int len = strlen(s);

	int cnt = 0;
	unordered_map<int, bool> mp;
	int tmp = 0, tmp1 = 0;
	char c = s[0];
	for (int i = 0;i < len;++i) {
		if (s[i] == c) nxt[i] = tmp;
		else {
			tmp = nxt[i] = i;
			c = s[i];
		}

		mp[s[i]] = true;
		if (mp.size() == k + 1) {
			w[i - 1] = ++cnt;
			mp.clear();
			mp[s[i]] = true;
			tmp1 = i;
		}
		nxt1[i] = tmp1;
	}

	mp.clear();
	int i = 0;
	for (;i < len;++i) {
		if (w[i] > 0) break;
		mp[s[i]] = true;
		w[i] = mp.size() == k ? 1 : -1;
		cout << w[i] << ' ';
	}


	for (;i < len;++i) {
		if (w[i]) cout << w[i] << ' ';
		else {
			mp.clear();
			int j = i;
			w[i] = Inf;
			//int t = 0;
			int nxt0 = nxt1[i];
			for (;j >= 0;--j) {
				if (nxt[j] != j) j = nxt[j] + 1;
				mp[s[j]] = true;
				if (mp.size() == k) {
					if (nxt1[j] == nxt0) j = nxt1[j];
					/*if (j == 0) {
						w[i] = 1;
						break;
					}*/
					if (w[j - 1] == -1) continue;
					w[i] = min(w[i], w[j - 1] + 1);
					//if (++t == 2) break;
				}
				else if (mp.size() == k + 1) {
					break;
				}
			}
			if (w[i] == Inf) w[i] = -1;
			cout << w[i] << ' ';
		}
	}
}