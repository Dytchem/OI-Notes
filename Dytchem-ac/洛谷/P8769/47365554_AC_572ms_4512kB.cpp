#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 100005;

int x,n;
int cnt[N];

struct P{
	int id;
	int a,b,c;
	bool operator < (const P& p) const{
		return a>p.a;
	}
}ps[N];

bool cmp(const P& p1,const P& p2){
	return p1.b<p2.b;
}

signed main(){
	cin>>x>>n;
	for (int i=1;i<=n;++i){
		ps[i].id=i;
		cin>>ps[i].a>>ps[i].b>>ps[i].c;
	}
	
	sort(ps+1,ps+1+n,cmp);
	
	int ans=0;
	
	priority_queue<P> pq;
	int now=n;
	int i=x;
	for (;now>0&&ps[now].b>=i;--now){
		cnt[ps[now].id]=ps[now].c;
		pq.push(ps[now]);
	}
	while (i>0&&!pq.empty()){
		const P p=pq.top();
		if (--cnt[p.id]==0) pq.pop();
		ans+=p.a;
		--i;
		for (;now>0&&ps[now].b>=i;--now){
			cnt[ps[now].id]=ps[now].c;
			pq.push(ps[now]);
		}
	}
	if (i!=0) cout<<-1;
	else cout<<ans;
}