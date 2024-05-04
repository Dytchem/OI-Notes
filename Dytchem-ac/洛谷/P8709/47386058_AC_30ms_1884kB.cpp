#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 100005;
int n;
ll a[N],sum[N];


signed main(){
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=0;
	for (int i=1;i<=n;++i){
		ans+=a[i]*(sum[n]-sum[i]);
	}
	cout<<ans;
	
	return 0;
} 