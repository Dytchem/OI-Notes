#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
#define Inf 0x3f3f3f3f

const int N = 100005;

int n,k;
int p[N],m[N];
int cnt[11][N];

inline int solve_p(int x){
	int re=0;
	while (x){
		re++;
		x/=10;
	}
	return re;
}

signed main(){
	cin>>n>>k;
	for (int i=1;i<=n;++i){
		int a;
		cin>>a;
		p[i]=solve_p(a);
		m[i]=a%=k;
		for (int j=1;j<11;++j){
			a=(a*10)%k;
			cnt[j][a]++;
		}
	}
	ll ans=0;
	for (int i=1;i<=n;++i){
		ans+=cnt[p[i]][(k-m[i])%k];
		ll t=m[i];
		for (int j=0;j<p[i];++j) t*=10;
		if ((m[i]+t)%k==0) ans--;
	}
	
	cout<<ans;
	
	return 0;
}

/*

10 10
10 10 10 10 10 10 10 10 10 10

*/