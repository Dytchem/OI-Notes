#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
#define Inf 0x3f3f3f3f

const int N = 100005;

int n;
int hed[N],to[N<<1],nxt[N<<1],pos=0;
ll wt[N<<1];

inline void add(int u,int v,int w){
	nxt[++pos]=hed[u];
	hed[u]=pos;
	to[pos]=v;
	wt[pos]=w;
}

int fa[N];
ll d=0,dp[N];

void dfs(int o){
	for (int i=hed[o];i;i=nxt[i]){
		int t=to[i];
		if (t==fa[o]) continue;
		fa[t]=o;
		dfs(t);
		d=max(d,dp[o]+dp[t]+wt[i]);
		dp[o]=max(dp[o],wt[i]+dp[t]);
	}
}

signed main(){
	cin>>n;
	for (int i=1;i<n;++i){
		int u,v,w; cin>>u>>v>>w;
		add(u,v,w), add(v,u,w);
	}
	dfs(1);
	cout<<d*(d+21)/2;
}