#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 102, M = 21;
int n,m,k;
int a[N];
int dp[1<<M];

signed main(){
	memset(dp,0x3f,sizeof(dp));
	
	cin>>n>>m>>k;
	for (int i=0;i<n;++i){
		for (int j=0;j<k;++j){
			int ai;
			cin>>ai;
			a[i]|=1<<(ai-1);
		}
	}
	
	dp[0]=0;
	for (int i=0;i<(1<<m);++i){
		if (dp[i]==Inf) continue;
		for (int j=0;j<n;++j){
			int nxt=i|a[j];
			dp[nxt]=min(dp[nxt],dp[i]+1);
		}
	}
	
	cout<<(dp[(1<<m)-1]==Inf?-1:dp[(1<<m)-1]);
	
	return 0;
}