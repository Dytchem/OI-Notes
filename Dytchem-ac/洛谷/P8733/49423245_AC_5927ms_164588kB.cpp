#include <bits/stdc++.h>
using namespace std;
//#define int ll
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
#define Inf 0x3f3f3f3f

const int N = 20;
int n, D;
int x[N],y[N];
double dp[1<<N][N];
double dis[N][N];


signed main(){
	cin>>n>>D;
	for (int i=0;i<n;++i){
		cin>>x[i]>>y[i];
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<i;++j){
			double d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			dis[i][j]=dis[j][i]=d<=D?d:Inf;
		}
	}
	for (int k=0;k<n;++k){
		for (int i=0;i<n;++i){
			for (int j=0;j<i;++j)
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	for (int i=0;i<1<<n;++i) for (int j=0;j<n;++j) dp[i][j]=Inf;
	dp[1][0]=0;
	for (int i=1;i<1<<n;++i){
		if (i&1==0) continue;
		for (int u=0;u<n;++u){
			if ((i>>u)&1==0) continue;
			for (int v=0;v<n;++v){
				if ((i>>v)&1) continue;
				dp[i|(1<<v)][v]=min(dp[i|(1<<v)][v],dp[i][u]+dis[u][v]);
			}
		}
	}
	
	double ans=Inf;
	
	for (int i=1;i<n;++i){
		ans=min(ans,dp[(1<<n)-1][i]+dis[i][0]);
	}
	
	printf("%.2lf",ans);
	
	return 0;
}