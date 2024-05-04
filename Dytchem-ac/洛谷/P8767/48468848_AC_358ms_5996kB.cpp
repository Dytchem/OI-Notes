#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define Inf 0x3f3f3f3f
typedef long long ll;

const ll P = 998244353, N = 100005, K = 1000000009;
ll n,m,k;

map<ll,ll> mp;
ll S=0,X=0;

inline void add(ll y,ll num=1){
	if (num==0) return;
	mp[y-X]=(mp[y-X]+num)%P;
	n=(n+num)%P;
	S=(S+y*num)%P;
	
}

inline void del(map<ll,ll>::iterator it){
	n=(n-it->second)%P;
	S=(S-(it->first+X)*it->second)%P;
	S=(S+P)%P;
	mp.erase(it);
}

inline void inc(ll x){
	X+=x;
	S=(S+n*x)%P;
	map<ll,ll>::iterator it=mp.lower_bound(k-X);
	ll cnt=0;
	while (it!=mp.end()){
		cnt+=it->second;
		add(1,(it->first-k+X)*it->second);
		del(it++);
	}
	n%=P;
	add(k,cnt);
}

inline void dec(ll x){
	X-=x;
	S=(S-n*x)%P;
	map<ll,ll>::iterator it=mp.upper_bound(-X),tmp=it;
	while (it!=mp.begin()){
		--tmp;
		del(tmp);
		tmp=it;
	}
	n%=P;
	S=(S%P+P)%P;
}

signed main(){
	cin>>n>>m>>k;
	for (int i=0;i<n;++i){
		ll a;cin>>a;
		mp[a]++;
		S+=a;
	}
	while (m--){
		ll x,y;cin>>x>>y;
		if (x>0) inc(x);
		else if (x<0) dec(-x);
		if (y>0) add(y);
		
		cout<<(S%P+P)%P<<'\n';
	}
}

/*

1 3 5
1
5 5
5 5
5 5

*/