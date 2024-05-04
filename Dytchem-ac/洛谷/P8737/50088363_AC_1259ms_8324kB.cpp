#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define y1 dcsvffsfvsfce
#define int long long
using namespace std;
typedef long long ll;

const int N = 1003;
const ll P = 1e9+7;
int n,m,w;
int x1,y1,z1,x2,y2,z2; 
int ps[N],nn=0;
bool notp[N];
ll fac[N*3],invfac[N*3];
ll stg[N][N];

ll qpow(ll a,ll b){
	ll re=1;
	while (b){
		if (b&1) re=re*a%P;
		a=a*a%P;
		b>>=1;
	}
	return re;
}

ll g(int x,int i);

void init(){
	notp[0]=notp[1]=true;
	for (int i=2;i<=1000;++i){
		if (!notp[i]) ps[++nn]=i;
		for (int j=1;j<=nn;++j){
			int p=ps[j],t=i*p;
			if (t>1000) break;
			notp[t]=true;
			if (i%p==0) break;
		}
	}
	fac[0]=1,invfac[0]=1;
	for (ll i=1;i<=3000;++i){
		fac[i]=fac[i-1]*i%P;
		invfac[i]=qpow(fac[i],P-2);
	}
	
	//memset(stg,0x3f,sizeof(stg));
	stg[0][0]=1;
	for (int i=0;i<500;++i){
		for (int x=0;x<=1000;++x){
			for (int j=1;j<=nn;++j){
				int p=ps[j],y=x+p;
				if (y>1000) break;
				stg[y][i+1]=(stg[y][i+1]+stg[x][i])%P;
			}
		}
	}
}

ll g(int x,int i){
	if (i>=500) return 0;
//	if (stg[x][i]!=INF) return stg[x][i];
//	if (i==0) return stg[x][i]=(x==0);
//	if (i==1) return stg[x][i]=!notp[x];
//	ll re=0;
//	for (int y=2;y<x;++y) re+=g(y,1)*g(x-y,i-1)%P;
//	return stg[x][i]=re%P;
	return stg[x][i];
}

ll f(int x,int y,int z){
	int a[3]={x,y,z};
	sort(a,a+3);
	x=a[0],y=a[1],z=a[2];
	if (x<0) return 0;
	ll re=0;
	for (int l=0;l<=x+y;++l){
		ll a=0,b=0;
		for (int i=max(0ll,l-y);i<=min(l,x);++i){
			a+=g(x,i)*g(y,l-i)%P*invfac[i]%P*invfac[l-i]%P;
		}
		for (int k=0;k<=z;++k){
			b+=g(z,k)*fac[l+k]%P*invfac[k]%P;
		}
		re+=(a%P)*(b%P)%P;
	}
	return re%P;
}


signed main(){
	init();
	cin>>n>>m>>w;
	cin>>x1>>y1>>z1>>x2>>y2>>z2;
	
	ll ans=f(n-1,m-1,w-1)-f(x1-1,y1-1,z1-1)*f(n-x1,m-y1,w-z1)%P-f(x2-1,y2-1,z2-1)*f(n-x2,m-y2,w-z2)%P\
	+f(x1-1,y1-1,z1-1)*f(x2-x1,y2-y1,z2-z1)%P*f(n-x2,m-y2,w-z2)%P\
	+f(x2-1,y2-1,z2-1)*f(x1-x2,y1-y2,z1-z2)%P*f(n-x1,m-y1,w-z1)%P;
	
	cout<<(ans%P+P)%P;
	
	return 0;
}

/*

1000 1000 1000
1 2 3 4 5 6

*/