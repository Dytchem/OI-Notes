#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

char a1[5],a2[9],a3[13];
int b1,b2,b3;

void add(char c){
	switch (c){
		case 'Y':++b1;break;
		case 'R':++b2;break;
		case 'G':++b3;break;
	}
}

bool check(){
	if (b1==1&&b2==2&&b3==3) return true;
	else return false;
}

signed main(){
	int T;
	cin>>T;
	while (T--){
		cin>>a3>>a2>>a1;
		for (int i=0;i<4;++i){
			b1=0,b2=0,b3=0;
			add(a1[i]);
			add(a2[i]),add(a2[i+4]);
			add(a3[i]),add(a3[i+4]),add(a3[i+8]);
			if (!check()) {
				cout<<"NO\n";
				goto end;
			}
		}
		cout<<"YES\n";
		end: continue;
	}
	return 0;
} 