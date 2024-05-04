#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 300005, A = 1000006;
int aa[N];

signed main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;++i) cin>>aa[i];
	
	int ans=Inf;
	int res=0;
	for (int bgn=1;;++bgn){
		int t=0;
		int a=bgn,b=bgn;
		for (int i=1;i<=n;++i){
			if (aa[i]!=a) ++t;
			if (a>A){
				t+=res=n-i;
				break;
			}
			a+=b;
			swap(a,b);
		}
		if (res>ans) break;
		ans=min(ans,t);
	} 
	
	cout<<ans;
	
	return 0;
}

/*

10
1 1 2 3 5 8 13 21 34 55

10
1 1 2 4 5 8 13 21 34 56

*/