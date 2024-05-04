#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 100005;

int n;
int hed[N],to[2*N],nxt[2*N],cur=0;
ll w[N];

inline void add(int u,int v){
	nxt[++cur]=hed[u];
	hed[u]=cur;
	to[cur]=v;
}

int fa[N];

ll ans=0;
//ll stask[N];

ll ask(int o=1){
	ll re=w[o];
	for (int i=hed[o];i;i=nxt[i]){
		int t=to[i];
		if (t==fa[o]) continue;
		fa[t]=o;
		ll a=ask(t);
		if (t>0) re+=a;
	}
	if (re<0) re=0;
	ans=max(ans,re);
	return re;
}

signed main(){
	//memset(stask,0x3f,sizeof(stask));
	
	cin>>n;
	for (int i=1;i<=n;++i) cin>>w[i];
	for (int i=1;i<n;++i) {
		int u,v; cin>>u>>v;
		add(u,v),add(v,u);
	}
	
	ask();
	
	cout<<ans;
	
	return 0;
}

/*

5
-1 2 -3 -4 -5
4 2
3 1
1 2
2 5

*/