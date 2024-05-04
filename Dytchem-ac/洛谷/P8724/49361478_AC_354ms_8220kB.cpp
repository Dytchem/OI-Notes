#include <bits/stdc++.h>
using namespace std;
//#define int ll
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
#define Inf 0x3f3f3f3f

const int N = 10004, M = 100005;
int n,m;

int hed[N],to[M<<1],nxt[M<<1],wgt[M<<1],typ[M<<1];
int pos=0;

void add(int u,int v,int w,int t){
	for (int i=hed[u];i;i=nxt[i]){
		if (to[i]==v&&typ[i]==t){
			if (wgt[i]>w) wgt[i]=w;
			return;
		}
	}
	nxt[++pos]=hed[u];
	hed[u]=pos;
	to[pos]=v;
	wgt[pos]=w;
	typ[pos]=t;
}

struct point{
	int v,d,t;
	bool operator <(const point& p)const{
		return d==p.d?t>p.t:d>p.d;
	}
};

int dj1(){
	bool vis[N];memset(vis,0,sizeof(vis));
	priority_queue<point> pq;
	pq.push(point{1,0,0});
	while (!pq.empty()){
		int u=pq.top().v,d=pq.top().d;//cout<<d<<'\n';
		pq.pop();
		if (vis[u]) continue;
		vis[u]=true;
		if (u==n) return d;
		for (int i=hed[u];i;i=nxt[i]){
			if (vis[to[i]]||typ[i]) continue;
			pq.push(point{to[i],d+wgt[i],0});
		}
	}
	return -1;
}

int dj2(){
	int re=Inf;
	int cnt=0;
	int vis[N][3];memset(vis,0,sizeof(vis));
	priority_queue<point> pq;
	pq.push(point{1,0,0});
	while (!pq.empty()){
		int u=pq.top().v,d=pq.top().d,t=pq.top().t;
		pq.pop();
		if (vis[u][t]) continue;
		vis[u][t]=true;
		if (u==n){
			re=min(re,d);
			if (++cnt==3) return re;
			continue;
		}
		for (int i=hed[u];i;i=nxt[i]){
			if (vis[to[i]][typ[i]]||t+typ[i]>2) continue;
			pq.push(point{to[i],d+wgt[i],t+typ[i]});
		}
	}
	return re;
}

signed main(){
	cin>>n>>m;
	while(m--){
		int u,v,w,t;cin>>u>>v>>w>>t;
		add(u,v,w,t),add(v,u,w,t);
	}
	cout<<dj1()-dj2();
	
	return 0;
}