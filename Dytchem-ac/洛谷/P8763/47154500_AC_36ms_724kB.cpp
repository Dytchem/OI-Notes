#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 10004;
int n; ll t;
bitset<N> b;

signed main(){
	cin>>n>>t;
	for (int i=1;i<=n;++i){
		char a;
		cin>>a;
		b[i]=a=='1';
	}
	
	ll mod=1;
	for (;mod<n;mod<<=1);
	t%=mod;
	while (t--) b^=b<<1;
	
	for (int i=1;i<=n;++i) cout<<b[i];
	
	return 0;
}


/*

5 8 10110

*/