#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
#define Inf 0x3f3f3f3f

const int N = 100005;

int n;
int hed[N],to[N<<1],nxt[N<<1],wt[N<<1],pos=0;

inline void add(int u,int v,int w){
	nxt[++pos]=hed[u];
	hed[u]=pos;
	to[pos]=v;
	wt[pos]=w;
}

int fa[N],w[N];

void dfs(int o){
	for (int i=hed[o];i;i=nxt[i]){
		int t=to[i];
		if (t==fa[o]) continue;
		fa[t]=o;
		w[t]=w[o]+wt[i];
		dfs(t);
	}
}

signed main(){
	cin>>n;
	for (int i=1;i<n;++i){
		int u,v,w; cin>>u>>v>>w;
		add(u,v,w), add(v,u,w);
	}
	dfs(1);
	int m = max_element(w+1,w+n+1)-w;
	memset(fa,0,sizeof(fa));
	memset(w,0,sizeof(w));
	dfs(m);
	ll d = *max_element(w+1,w+n+1);
	cout<<d*(d+21)/2;
}