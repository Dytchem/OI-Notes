#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 41, M = 21;
int n,m,k;
double pi[N],pij[N][M],p[M];
bool have[M];

struct P{
	int id;
	double p;
	bool operator<(const P& pi) const{
		if (p!=pi.p) return p>pi.p;
		else return id<pi.id;
	}
}ps[N];

signed main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%lf",&pi[i]),pi[i]/=100,p[i]=1;
	for (int i=1;i<=n;++i) for (int j=1;j<=m;++j) scanf("%lf",&pij[i][j]),pij[i][j]/=100;
	scanf("%d",&k);
	for (int i=1;i<=k;++i){
		int ai; scanf("%d",&ai);
		have[ai]=true;
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			p[i]*=have[j]?pij[i][j]:(1-pij[i][j]);
		}
	}
	double sum=0;
	for (int i=1;i<=n;++i){
		ps[i]={i,pi[i]*p[i]};
		sum+=ps[i].p;
	}
	sort(ps+1,ps+1+n);
	for (int i=1;i<=n;++i){
		printf("%d %.2lf\n",ps[i].id,100*ps[i].p/sum);
	}
	
	return 0;
}