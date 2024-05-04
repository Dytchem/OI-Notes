#include<iostream>
using namespace std;
int main() {
    string ans [] = {
        "1903", // 双引号中替换为 A 题的答案
        "977", // 双引号中替换为 B 题的答案
        "2653631372", // 双引号中替换为 C 题的答案
        "12988816", // 双引号中替换为 D 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}

/*1
#include <bits/stdc++.h>
using namespace std;

const int N = 20210605;

int ps[N+1],n=0;
bool vis[N+1]={1,1};

void init(){
	for (int i=2;i<=N;++i){
		if (!vis[i]) ps[++n]=i;
		for (int j=1;j<=n;++j){
			int p=ps[j],t=i*p;
			if (t>N) break;
			vis[t]=true;
			if (i%p==0) break;
		}
	}
}

bool check(int x){
	if (vis[x]) return false;
	while (x){
		int t=x%10;
		x/=10;
		if (vis[t]) return false;
	}
	return true;
}


signed main(){
	init();
	
	int ans=0;
	for (int i=1;i<=N;++i){
		ans+=check(i);
	}
	cout<<ans;
	
	return 0;
} 
*/

/*2
#include <bits/stdc++.h>
using namespace std;

bool isLeap[3000];
int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int f(int x){
	int re=0;
	while (x){
		re+=x%10;
		x/=10;
	}
	return re;
}

signed main(){
	isLeap[2004]=isLeap[2008]=isLeap[2012]=isLeap[2016]=isLeap[2020]=true;
	
	int ans=0;
	for (int y=2001;y<=2021;++y){
		int a=f(y);
		for (int m=1;m<=12;++m){
			int b=f(m);
			if (m==2){
				for (int d=1;d<=mon[m]+isLeap[y];++d){
					int x=a+b+f(d);
					int sq=(int)sqrt(x);
					if (sq*sq==x) ans++;
				}
			}
			else{
				for (int d=1;d<=mon[m];++d){
					int x=a+b+f(d);
					int sq=(int)sqrt(x);
					if (sq*sq==x) ans++;
				}
			}
		}
	}
	cout<<ans;
	
	return 0;
}
*/

/*3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f

ll stW[3000];


ll W(int x){
	if (stW[x]!=INF) return stW[x];
	ll re=INF+1;
	for (ll i=0;i<=x-1;++i){
		ll t=1+2*W(i)+3*W(x-1-i)+i*i*(x-1-i);
		if (t<0) continue;
		re=min(re,t);
	}
	return stW[x]=re;
}

signed main(){
	memset(stW,0x3f,sizeof(stW));
	stW[0]=0;
	
	cout<<W(2021);
	
	return 0;
}
*/

/*4
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f

int dp[8][1<<8];

bool ck(int x){
	for (int i=0;i<8;++i){
		int a=x%2;
		x/=2;
		if (a==0){
			int b=x%2;
			x/=2;
			++i;
			if (i==8||b!=0) return false;
		} 
	}
	return true;
}

signed main(){
	for (int i=0;i<(1<<8);++i){
		dp[0][i]=ck(i);
	}
	for (int i=1;i<=7;++i){
		for (int j=0;j<(1<<8);++j){
			for (int k=0;k<(1<<8);++k){
				if ((j&k)==0&&ck(j|k)) dp[i][j]+=dp[i-1][k];
			}
		}
	}
	cout<<dp[7][0];
	
	return 0;
}
*/