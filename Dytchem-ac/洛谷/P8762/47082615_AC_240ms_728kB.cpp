#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

inline ll solve(ll x){
	ll l=1,r=2e6;
	while (r-l>1){
		ll mid=l+r>>1;
		if (x<=mid*(mid+1)/2){
			r=mid;
		}
		else l=mid;
	}
	return l;
}

inline ll pre(ll x){
	if (x==0) return 0;
	ll n=solve(x);
	ll l=x-n*(n+1)/2;
	return n*(n+1)*(n+2)/6+l*(l+1)/2;
}

signed main(){
	int T;
	cin>>T;
	while (T--){
		ll l,r;
		cin>>l>>r;
		cout<<pre(r)-pre(l-1)<<'\n';
	}
}

/*

1
1 1000000000000

*/