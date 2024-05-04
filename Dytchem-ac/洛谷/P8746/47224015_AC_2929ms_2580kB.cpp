#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

template <typename T>
inline T& read(T& a){
	a=0;
	char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
	return a;
}

const int N = 102, M = 51;
int n,m,a[N],sum[N];
int stf[N][N][M];

inline int S(const int l,const int r){
	return sum[r]-sum[l-1];
} 

int mi;
inline int f(int end1=0,int end2=0,const int now=1){
	if (end1>end2) swap(end1,end2);
	if (stf[end1][end2][now]!=Inf) return stf[end1][end2][now];
	if (now==m){
		for (int i=min(n,end2+1);i>=end1+1;--i){
			int s=S(i,n);
			if (s<mi) continue;
			return stf[end1][end2][now]=s;
		}
		return stf[end1][end2][now]=Inf-1;
	}
	
	int re=Inf-1;
	// 转移
	const int maxi=min(n,end2+1);
	for (int i=maxi;i>=end1+2;--i){
		re=min(re,f(i-1,end2,now));
	}
	// 本原
	for (int i=end1+1,j=end2;j<=n;++j){ // here 
		int s=S(i,j);
		if (s<mi) continue;
		if (s>=re) break;
		re=min(re,max(s,f(j,end2,now+1)));
	}
	return stf[end1][end2][now]=re;
}

signed main(){
	read(n),read(m);
	for (int i=1;i<=n;++i) sum[i]=sum[i-1]+read(a[i]);
	int maxmi=2*sum[n]/m,ans=Inf;
	for (mi=1;mi<=maxmi;++mi){
		memset(stf,0x3f,sizeof(stf));
		int ma=f();
		ans=min(ans,ma-mi);
		if (ans==0) break;
	}
	cout<<ans;
	return 0;
}

/*

10 5
1 2 2 1 1 2 2 1 1 2

*/