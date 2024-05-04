#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
#define Inf 0x3f3f3f3f

const int N = 100005, H = 1000006;

int n,hm=0;
int h[N];
ll t[N];

int cnt[H<<2];

void add(int k,int l=0,int r=hm,int p=1){
	++cnt[p];
	if (l==k&&k==r)
		return;
	int mid=l+r>>1,ls=p<<1;
	if (k<=mid) add(k,l,mid,ls);
	else add(k,mid+1,r,ls|1);
}

int qry1(int mi,int l=0,int r=hm,int p=1){
	if (l>mi) return cnt[p];
	if (r<=mi) return 0;
	int mid=l+r>>1,ls=p<<1;
	return qry1(mi,l,mid,ls)+qry1(mi,mid+1,r,ls|1);
}

int qry2(int ma,int l=0,int r=hm,int p=1){
	if (r<ma) return cnt[p];
	if (l>=ma) return 0;
	int mid=l+r>>1,ls=p<<1;
	return qry2(ma,l,mid,ls)+qry2(ma,mid+1,r,ls|1);
}


signed main(){
	//freopen("a.in","r",stdin);
	cin>>n;
	for (int i=1;i<=n;++i) {
		cin>>h[i];
		hm=max(hm,h[i]);
	}
	for (int i=1;i<=n;++i){
		t[i]+=qry1(h[i]);
		add(h[i]);
	}
	memset(cnt,0,sizeof(cnt));
	for (int i=n;i>=1;--i){
		t[i]+=qry2(h[i]);
		add(h[i]);
	}
	ll ans=0;
	for (int i=1;i<=n;++i) ans+=t[i]*(t[i]+1)/2;
	cout<<ans;
	
	return 0;
}

/*

10
10 9 8 7 6 5 4 3 2 1

10
5 7 8 4 6 1 3 9 2 10

*/