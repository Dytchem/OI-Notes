#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const ll P = 1e9+7;

struct Node{
	ll dis,num,tail;
	Node* nxt;
};

signed main(){
	ll n;
	cin>>n;
	if (n==1) return cout<<1,0;
	else if (n==2||n==3) return cout<<2,0;
	Node* now=new Node{1,1,3,NULL};
	Node* lst=now;
	ll cur=3,Gy=2,ma=3;
	while (true){
		for (;cur<=now->tail;cur+=now->dis){
			lst=lst->nxt=new Node{Gy,now->dis,ma+=Gy*now->dis,NULL};
			if (ma>=n) goto end;
			++Gy;
		}
		Node* tmp=now;
		now=now->nxt;
		delete tmp;
	}
	
	end:
	ll head=lst->tail-lst->dis*lst->num+1;
	ll ans=(n-head)/lst->dis+cur;
	
	cout<<ans;
	
	return 0;
}

/*

100000000000
7554625

1000000000000
31347587

10000000000000
130080604

200000000000000
828504442

2000000000000000
3438257305


*/