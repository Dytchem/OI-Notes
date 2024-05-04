#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int INF = 0x7fffffff;

int T, n, km, a[300][200], fx[300][200], zg[300][200], i, j, k, flag;

int main() {
	float b, f, fm;
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d %f", &n, &b);
		flag = 0;
		for (j = 0; j < n; j++) {
			fm = -4;
			for (k = 0; k < n; k++) {
				scanf("%f", &f);
				if (flag == 0 && k != j && f > fm) {
					fm = f;
					km = k;
				}
			}
			if (flag == 0) {
				if (fm < b) flag = 1;
				else fx[i][j] = km;
			}
		}
		if (n == 1) printf("kono jinsei, imi ga nai!\n");
		else if (flag == 1) printf("hbxql\n");
		else {
			for (j = 0; j < n; j++) {
				k = j;
				while (zg[i][k] == 0) {
					zg[i][k] = 1;
					k = fx[i][k];
					if (k == j)	break;
					if (zg[i][k] == 1) goto END;
				}
			}
			printf("wish you the best in your search\n");
			if (0) {
			END:    		printf("hbxql\n");
			}
		}
	}

	return 0;
}