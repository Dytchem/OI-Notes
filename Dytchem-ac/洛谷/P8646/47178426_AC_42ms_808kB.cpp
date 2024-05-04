#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 102;
int n,a[N];
const int S = 100005;
bool dp[S];

inline int gcd(int a,int b){
	if (b) while ((a%=b)&&(b%=a));
	return a+b;
}

signed main(){
	cin>>n;
	for (int i=1;i<=n;++i) cin>>a[i],dp[a[i]]=true;
	sort(a+1,a+n+1);
	int g=a[1];
	for (int i=2;i<=n;++i) g=__gcd(g,a[i]);
	if (g!=1) return cout<<"INF",0;
	for (int i=1;i<S;++i){
		if (!dp[i]) continue;
		for (int j=1;j<=n;++j){
			if (i+a[j]>=S) break;
			dp[i+a[j]]=true;
		}
	}
	int ans=0;
	for (int i=1;i<S;++i){
		if (!dp[i]) ++ans;
	}
	cout<<ans;
	return 0;
}