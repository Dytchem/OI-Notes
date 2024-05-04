#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii p[17], d[17];

inline void turn(pii& p1) {
	p1.first = -p1.first;
	p1.second = -p1.second;
}

inline int dot(const pii& p1, const pii& p2) {
	return p1.first * p2.first + p1.second * p2.second;
}

inline bool isParall(const pii& p1, const pii& p2) {
	return p1.first * p2.second == p1.second * p2.first;
}

inline bool isSame(const pii& p1, const pii& p2) {
	return isParall(p1, p2) && dot(p1, p2) > 0;
}

inline bool isContra(const pii& p1, const pii& p2) {
	return isParall(p1, p2) && dot(p1, p2) < 0;
}

inline bool isMid(const pii& p, const pii& p1, const pii& p2) {
	const int D = p1.first * p2.second - p1.second * p2.first;
	const int Da = p.first * p2.second - p.second * p2.first;
	const int Db = p1.first * p.second - p1.second * p.first;
	if (D * Da > 0 && D * Db > 0) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	for (int i = 1;i <= 4;++i) {
		for (int j = 1;j <= 4;++j) {
			int a;
			cin >> a;
			p[a] = make_pair(i, j);
		}
	}
	for (int i = 2;i <= 16;++i) {
		d[i].first = p[i].first - p[i - 1].first;
		d[i].second = p[i].second - p[i - 1].second;
	}

	int ans = 1;
	pii p1 = d[2], p2 = d[2];
	bool b1 = true, b2 = true;
	for (int i = 3;i <= 16;++i) {
		if (isSame(p1, p2)) {
			if (isSame(d[i], p1)) {}
			else {
				turn(p1);b1 = false;
				p2 = d[i];b2 = true;
				++ans;
			}
		}
		else {
			if (b1 && isSame(d[i], p1) || b2 && isSame(d[i], p2) || isMid(d[i], p1, p2)) {
				p1 = p2 = d[i];
			}
			else {
				turn(p1);turn(p2);
				if (isSame(d[i], p1)) {
					if (b1) b2 = false;
					else {
						b1 = true;
						b2 = false;
					}
				}
				else if (isSame(d[i], p2)) {
					if (b2) b1 = false;
					else {
						b1 = false;
						b2 = true;
					}
				}
				else if (isMid(d[i], p1, p2)) {
					b1 = b2 = false;
				}
				else if (isContra(d[i], p1)) {
					p1.first = p1.first * 999 + p2.first;
					p1.second = p1.second * 999 + p2.second;
					p2 = d[i];
					b1 = false;
					b2 = true;
				}
				else if (isContra(d[i], p2)) {
					p2.first = p2.first * 999 + p1.first;
					p2.second = p2.second * 999 + p1.second;
					p1 = d[i];
					b2 = false;
					b1 = true;
				}
				else if (isMid(p1, p2, d[i])) {
					p1 = d[i];
					b1 = true;
					b2 = false;
				}
				else {
					p2 = d[i];
					b2 = true;
					b1 = false;
				}
				++ans;
			}
		}
		// cout << i << ' ' << ans << " / " << p1.first << ' ' << p1.second << ' ' << b1 << " / " << p2.first << ' ' << p2.second << ' ' << b2 << '\n';
	}
	cout << ans;
}
