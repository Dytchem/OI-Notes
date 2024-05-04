#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N=1003,M=10004;

int n,m;
int c[N],hed[N],to[M<<1],nxt[M<<1],cc[M<<1],cur=0;

inline void add(int u,int v,int c){
	nxt[++cur]=hed[u];
	hed[u]=cur;
	to[cur]=v;
	cc[cur]=c;
}

struct P{
	int id,w;
	bool operator <(const P& p)const{return w>p.w;}
};

bool vis[N];

inline void solve(){
	priority_queue<P> q;
	q.push(P{1,0});
	while (true){
		P p=q.top();
		q.pop();
		if (vis[p.id]) continue;
		if (p.id==n){
			cout<<p.w;
			return;
		}
		vis[p.id]=true;
		for (int i=hed[p.id];i;i=nxt[i]){
			int o=to[i];
			if (vis[o]) continue;
			if (o==n){
				q.push(P{o,p.w+cc[i]});
			}
			else{
				q.push(P{o,p.w+cc[i]+c[o]});
			}
			
		}
	}
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;++i) cin>>c[i];
	for (int i=1;i<=m;++i) {
		int u,v,c;
		cin>>u>>v>>c;
		add(u,v,c),add(v,u,c);
	}
	solve();
	
	return 0;
}