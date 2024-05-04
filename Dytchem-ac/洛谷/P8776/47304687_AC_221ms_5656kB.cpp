#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 100005, A = 1000006;
int n,k;
int a[N];
int L[N],R[N];
int tmp[N],len;
int bt[A];

inline void add(int p,int k){
	for (;p<A;p+=p&-p) bt[p]=max(bt[p],k);
}

inline int qry(int p){
	int re=0;
	for (;p;p-=p&-p) re=max(re,bt[p]);
	return re;
}

signed main(){
	cin>>n>>k;
	for (int i=1;i<=n;++i) cin>>a[i];
	
	tmp[0]=a[1]; len=1;
	L[1]=1;
	for (int i=2;i<=n;++i){
		int t=upper_bound(tmp,tmp+len,a[i])-tmp;
		if (t==len) tmp[len++]=a[i];
		else tmp[t]=a[i];
		L[i]=t+1;
	}
	//for (int i=1;i<=n;++i) cout<<L[i]<<' ';
	
	tmp[0]=a[n]; len=1;
	R[n]=1;
	for (int i=n-1;i>=1;--i){
		int t=upper_bound(tmp,tmp+len,a[i],greater<int>())-tmp;
		if (t==len) tmp[len++]=a[i];
		else tmp[t]=a[i];
		R[i]=t+1;
	}
	//for (int i=1;i<=n;++i) cout<<R[i]<<' ';
	
	int ans=k+1;
	
	for (int i=1;i<=k+1;++i){
		ans=max(ans,i-1+R[i]);
	}
	for (int i=k+2;i<=n;++i){
		add(a[i-k-1],L[i-k-1]);
		ans=max(ans,qry(a[i])+k+R[i]);
	}
	ans=max(ans,L[n-k]+k);
	
	cout<<ans;
	
	return 0; 
} 

/*

10 1
1 4 2 8 5 6 8 9 0 1

*/