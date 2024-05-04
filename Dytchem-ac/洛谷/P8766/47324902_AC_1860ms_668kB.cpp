#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

ll st[35][10][10];
ll tmp[31][4][2][2];
int T;

int n;
ll dfs(int now=30,int flag=0,bool full=true,bool have=false){
	if (now<0) return flag==2&&have;
	if (tmp[now][flag][full][have]!=INF) return tmp[now][flag][full][have];
	if (!full){
		if (st[now][flag][have]!=INF) return st[now][flag][have];
		ll re=0;
		if (flag==0){
			if (have) re+=dfs(now-1,0,false,true)*2;
			else re+=dfs(now-1,0,false,have)+dfs(now-1,0,false,true);
			re+=dfs(now-1,1,false,have); // a=1,b=0
		}
		else if (flag==1){
			//re+=dfs(now-1,1,false,have); // a=0,b=0
			if (have) re+=dfs(now-1,2,false,have); // a=0,b=1
			if (have) re+=dfs(now-1,1,false,true)*3;
			else re+=dfs(now-1,1,false,true)+dfs(now-1,1,false,have)*2;
		}
		else{
			//re+=dfs(now-1,2,false,true); // a=0,b=0
			//re+=dfs(now-1,2,false,true); // a=0,b=1
			//re+=dfs(now-1,2,false,true); // a=1,b=0
			re+=dfs(now-1,2,false,true)*4; // a=1,b=1
		}
		return st[now][flag][have]=re;
	}
	
	ll re=0;
	if (flag==0){
		if ((n>>now)&1){
			re+=dfs(now-1,0,false,have); // a=0,b=0
			re+=dfs(now-1,1,true,have); // a=1,b=0
			re+=dfs(now-1,0,true,true); // a=1,b=1
		}
		else{
			re+=dfs(now-1,0,true,have); // a=0,b=0
		}
	}
	else if (flag==1){
		if ((n>>now)&1){
			re+=dfs(now-1,1,false,have); // a=0,b=0
			if (have) re+=dfs(now-1,2,false,have); // a=0,b=1
			re+=dfs(now-1,1,true,have); // a=1,b=0
			re+=dfs(now-1,1,true,true); // a=1,b=1
		}
		else{
			re+=dfs(now-1,1,true,have); // a=0,b=0;
			if (have) re+=dfs(now-1,2,true,have); // a=0,b=1
		}
	}
	else{
		if ((n>>now)&1){
			//re+=dfs(now-1,2,false,true); // a=0,b=0
			re+=dfs(now-1,2,false,true)*2; // a=0,b=1
			//re+=dfs(now-1,2,true,true); // a=1,b=0
			re+=dfs(now-1,2,true,true)*2; // a=1,b=1
		}
		else{
			//re+=dfs(now-1,2,true,true); // a=0,b=0
			re+=dfs(now-1,2,true,true)*2; // a=0,b=1
		}
	}
	
	return tmp[now][flag][full][have]=re;
}


signed main(){
	memset(st,0x3f,sizeof(st));
	cin>>T;
	while (T--){
	memset(tmp,0x3f,sizeof(tmp));
		cin>>n;
		cout<<dfs()*3<<'\n';
	}
	
	return 0;
} 