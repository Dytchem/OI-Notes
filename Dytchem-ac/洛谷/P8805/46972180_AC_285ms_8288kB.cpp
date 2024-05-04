#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long

const int N = 100005,M=N<<1;

int n,m;
int hed[N],to[M],nxt[M],deg[N],cur=0;
int hson[N],top[N],dep[N],siz[N],fa[N];
int sum[N];

inline void add(int u,int v){
	nxt[++cur]=hed[u];
	hed[u]=cur;
	to[cur]=v;
	++deg[u];
}

void dfs1(int o=1){
	siz[o]=1;
	for (int i=hed[o];i;i=nxt[i]){
		int j=to[i];
		if (j==fa[o]) continue;
		dep[j]=dep[o]+1;
		sum[j]=sum[o]+deg[j];
		fa[j]=o;
		dfs1(j);
		siz[o]+=siz[j];
		if (siz[hson[o]]<siz[j]) hson[o]=j;
	}
}

void dfs2(int o=1,int t=1){
	top[o]=t;
	if (hson[o]){
		dfs2(hson[o],t);
		for (int i=hed[o];i;i=nxt[i]){
			int j=to[i];
			if (j==hson[o]||j==fa[o]) continue;
			dfs2(j,j);
		}
	}
}

inline int lca(int u,int v){
	while (top[u]!=top[v]){
		if (dep[top[u]]>dep[top[v]]) u=fa[top[u]];
		else v=fa[top[v]];
	}
	return dep[u]<dep[v]?u:v;
}

inline int dis(int u,int v){
	if (u==v) return deg[u];
	int l=lca(u,v);
	return sum[u]+sum[v]-2*sum[l]+deg[l];
}

inline void init(){
	sum[1]=deg[1];
	dfs1();
	dfs2();
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		add(u,v),add(v,u);
	}
	init();
	while (m--){
		int u,v;
		cin>>u>>v;
		cout<<dis(u,v)<<'\n';
	}
	
	return 0;
}

/*

7 5
1 2
1 3
2 4
2 5
3 6
3 7
1 4
3 5
1 1
7 5
5 6

5 3
1 2
2 3
3 4
4 5
1 5
1 3
2 3

*/