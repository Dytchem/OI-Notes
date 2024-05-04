#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 10004;
int n; ll t;
bitset<N> b0,b,c;

signed main(){
	cin>>n>>t;
	for (int i=1;i<=n;++i){
		char a;
		cin>>a;
		b0[i]=b[i]=a-'0';
	}
	ll cnt=0;
	while (t--){
		b^=b<<1;
		//for (int i=1;i<=n;++i) cout<<b[i];
		//cout<<'\n';
		++cnt;
		if (b==b0) break;
	}
	if (t!=-1){
		t%=cnt;
		while (t--)
			b^=b<<1;
	}
	
	for (int i=1;i<=n;++i) cout<<b[i];
	
	return 0;
}


/*

5 8 10110

*/