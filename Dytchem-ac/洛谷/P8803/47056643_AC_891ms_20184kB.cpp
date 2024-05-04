#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
#define Inf 0x3f3f3f3f

struct ticket{
	int day,wgt;
	bool operator < (const ticket& t) {
		return day<t.day;
	}
};

const int N = 1003, M = 5003;
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int n,m,k;
ticket a[N];
int stf[N][M];

int f(int num,int mny){
	if (mny<=0||num<1) return 0;
	if (stf[num][mny]!=Inf) return stf[num][mny];
	int re=f(num-1,mny);
	if (a[num].wgt<=mny) re=max(re,a[num].wgt);
	for (int i=num-1;i>=1;--i){
		if (a[num].day-a[i].day<k) continue;
		re=max(re,f(i,mny-a[num].wgt)+a[num].wgt);
		break;
	}
	return stf[num][mny]=re;
}

signed main(){
	for (int i=1;i<=12;++i) days[i]+=days[i-1];
	//cout<<days[12];
	memset(stf,0x3f,sizeof(stf));
	cin>>n>>m>>k;
	for (int i=1;i<=n;++i){
		int m,d;
		cin>>m>>d>>a[i].wgt;
		a[i].day=days[m-1]+d;
	}
	sort(a+1,a+1+n);
	return cout<<f(n,m),0;
}