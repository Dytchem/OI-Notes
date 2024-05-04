#include<iostream>
using namespace std;
int main() {
    string ans [] = {
        "59375", // 双引号中替换为 A 题的答案
        "15698", // 双引号中替换为 B 题的答案
        "691677274345", // 双引号中替换为 C 题的答案
        "4046", // 双引号中替换为 D 题的答案
        "1352184317599", // 双引号中替换为 E 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}

/*

(1)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

signed main(){
	ll ans=1;
	for (int i=1;i<=2021;i+=2) ans=ans*i%100000;
	cout<<ans;
	
	return 0;
} 

(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

signed main(){
	ll ans=0;
	for (int x=1;x<=2021;++x){
		for (int y=1;x*y<=2021;++y) ++ans;
	}
	cout<<ans;
	
	return 0;
} 

(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

ll stf[2022][6];

ll f(ll x,ll n) {
	if (n==1) return 1;
	if (stf[x][n]!=INF) return stf[x][n];
	ll re=0;
	for (ll i=1;i<x;++i) re+=f(x-i,n-1);
	return stf[x][n]=re;
}

signed main(){
	memset(stf,0x3f,sizeof(stf));
	
	cout<<f(3,2)<<'\n';
	cout<<f(5,3)<<'\n';
	cout<<f(2021,5);
	
	return 0;
} 

(4)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

int cost(int x,int y){
	int re=0;
	while (x||y){
		if (x%10!=y%10) re+=x%10+y%10;
		x/=10,y/=10;
	}
	return re;
}

struct P{
	int x,w;
	bool operator < (const P& p) const{
		return w>p.w;
	}
};

bool vis[2022];


signed main(){
	const int n = 2021;
	
	priority_queue<P> q;
	q.push(P{1,0});
	
	int ans=0;
	
	while (!q.empty()){
		int now=q.top().x;
		int mny=q.top().w;
		q.pop();
		if (vis[now]) continue;
		vis[now]=true;
		ans+=mny;
		for (int i=1;i<=n;++i){
			if (vis[i]) continue;
			q.push(P{i,cost(now,i)});
		}
	}
	
	cout<<ans;
	
	return 0;
} 

(5)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int S = 20210519, P = 20000;
ll cnt[S];

inline void down(int from,int to){
	cnt[to]+=cnt[from]+1;
}

void f(int n){
	down(n,1);
	ll i=2;
	for (;i*i<n;++i){
		if (n%i==0){
			down(n,i);
			down(n,n/i);
		}
	}
	if (i*i==n) down(n,i);
}

signed main(){	
	int target = 20210509;
	for (int i=target;i>=2;--i) f(i),cout<<i<<'\n';
	
	cout<<cnt[1]+1;
	
	return 0;
}

*/