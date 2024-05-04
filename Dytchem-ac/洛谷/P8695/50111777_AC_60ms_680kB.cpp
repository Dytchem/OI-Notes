#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1003;
int n;
int x[N],y[N],v[N],d[N];
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int cnt[2];
map<int,int> mp[2];

inline void solve(int x,int v,int c){ // 解方程：x+vt=0 
	if (v==0){
		if (x==0) cnt[c]++;
	}
	else{
		if (x%v==0&&x/v<=0) mp[c][-x/v]++;
	}
}

signed main(){
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>x[i]>>y[i]>>v[i];
		char dd; cin>>dd;
		switch (dd){
			case 'R':d[i]=0;break;
			case 'U':d[i]=1;break;
			case 'L':d[i]=2;break;
			case 'D':d[i]=3;break;
		}
		
	}
	int ans=0;
	for (int i=1;i<=n;++i){
		cnt[0]=cnt[1]=0;
		mp[0].clear(),mp[1].clear();
		for (int j=1;j<=n;++j){
			int x1=x[j]-x[i],vx=v[j]*dx[d[j]]-v[i]*dx[d[i]];
			int y1=y[j]-y[i],vy=v[j]*dy[d[j]]-v[i]*dy[d[i]];
			// 解方程：x1+vx*t=0，y1+vy*t=0
			solve(x1,vx,0);
			solve(y1,vy,1);
		}
		int ma=0;
		for (map<int,int>::iterator it=mp[0].begin();it!=mp[0].end();++it){
			ma=max(ma,it->second);
		}
		ans=max(ans,cnt[0]+ma);
		ma=0;
		for (map<int,int>::iterator it=mp[1].begin();it!=mp[1].end();++it){
			ma=max(ma,it->second);
		}
		ans=max(ans,cnt[1]+ma);
	}
	cout<<ans;
	
	return 0;
}

/*

4
1 0 1 R
0 1 1 U
-1 0 1 L
0 -1 1 D
*/