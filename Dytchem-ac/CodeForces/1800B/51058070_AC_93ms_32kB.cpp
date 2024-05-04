#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
//#define int long long

const int N = 200005, L = 128;
int a[L];

signed main(){
	int t;cin>>t;while (t--){
		memset(a,0,sizeof(a));
		int n,k;cin>>n>>k;
		for (int i=0;i<n;++i){
			char c;cin>>c;
			a[c]++;
		}
		int ans=0;
		for (int i='a',j='A';i<='z';++i,++j){
			if (a[i]>a[j]) swap(a[i],a[j]);
			int m=(a[i]+a[j])/2,d=m-a[i];
			if (k>=d) k-=d,ans+=m;
			else if (k==0) ans+=min(a[i],a[j]);
			else ans+=min(a[i],a[j])+k,k=0;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
} 