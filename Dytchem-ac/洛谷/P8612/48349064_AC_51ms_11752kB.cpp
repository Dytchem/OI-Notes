#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define Inf 0x3f3f3f3f
typedef long long ll;

const int N = 60, K = 20;
const ll P = 1e9+7;

int n,m,k;
int a[N][N];
ll dp[N][N][K][K];

ll ask(int x,int y,int cnt,int ma){
	if (dp[x][y][cnt][ma]!=INF) return dp[x][y][cnt][ma];
	if (x==0||y==0) return 0;
	if (x==1&&y==1&&cnt==0) return 1;
	//else if (cnt==0) return 1;
	//if (cnt<0) return 0;
	ll re=ask(x-1,y,cnt,ma)+ask(x,y-1,cnt,ma);
	if (cnt>0&&a[x][y]==ma){ 
		if (cnt==1) re+=ask(x-1,y,0,-1)+ask(x,y-1,0,-1);
		else for (int i=0;i<ma;++i) re+=ask(x-1,y,cnt-1,i)+ask(x,y-1,cnt-1,i);
	}
	
	return dp[x][y][cnt][ma]=re%P;
}

signed main(){
	memset(dp,0x3f,sizeof(dp));
	
	cin>>n>>m>>k;
	for (int i=1;i<=n;++i) for (int j=1;j<=m;++j) cin >> a[i][j];
	
	dp[1][1][1][a[1][1]]=1;
	
	ll ans=0;
	for (int i=0;i<=12;++i)
		ans+=ask(n,m,k,i);
	
	cout<<ans%P;
}