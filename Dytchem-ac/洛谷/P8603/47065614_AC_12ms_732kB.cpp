#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
#define Inf 0x3f3f3f3f

const int S=1003,N=102;
int val[N],ls[N],rs[N],siz[N],cur=1;

void add(int a){
	int now=1;
	while (siz[now]){
		++siz[now];
		if (a<val[now]) {
			if (!ls[now]) ls[now]=++cur;
			now=ls[now];
		}
		else {
			if (!rs[now]) rs[now]=++cur;
			now=rs[now];
		}
	}
	++siz[now];
	val[now]=a;
}

char ans[S][S];
int cnt[S];
stack<char> s; 

void dfs(int now=1,int r=1,int c=1){
	r+=siz[rs[now]];
	while (val[now]){
		s.push(val[now]%10+'0');
		val[now]/=10;
	}
	int i=c;
	for (;!s.empty();++i){
		ans[r][i]=s.top();
		s.pop();
	}
	cnt[r]=i-1;
	if (!siz[ls[now]]&&!siz[rs[now]]) return;
	ans[r][i++]='-';
	if (ls[now]){
		int j=r;
		for (int t=0;t<=1+siz[rs[ls[now]]];++t,++j) ans[j][i]='|';
		ans[--j][i+1]='-';
		dfs(ls[now],r+1,i+2);
	}
	if (rs[now]){
		int j=r;
		for (int t=0;t<=1+siz[ls[rs[now]]];++t,--j) ans[j][i]='|';
		ans[++j][i+1]='-';
		dfs(rs[now],r-siz[rs[now]],i+2);
	}
	cnt[r]+=2;
}

signed main(){
	int a;
	while (cin>>a)
		add(a);
	
	dfs();
	
	int rm=1+siz[ls[1]]+siz[rs[1]];
	for (int i=1;i<=rm;++i){
		for (int j=1;j<=cnt[i];++j){
			if (!ans[i][j]) cout<<'.';
			else cout<<ans[i][j];
		}
		cout<<'\n';
	}
	
	return 0;
}