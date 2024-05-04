#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
#define Inf 0x3f3f3f3f

const int N = 1003;

char s1[N],s2[N];
int stf[N][N];

int f(int m,int n){
	if (stf[m][n]!=Inf) return stf[m][n];
	if (m==0||n==0) return stf[m][n]=0;
	int re=max(f(m-1,n),f(m,n-1));
	return stf[m][n]=max(re,f(m-1,n-1)+(s1[m]==s2[n]));
}


signed main(){
	memset(stf,0x3f,sizeof(stf));
	cin>>s1+1;
	int n=strlen(s1+1);
	for (int i=1;i<=n;++i) s2[i]=s1[n+1-i];
	
	cout<<n-f(n,n);
	
	return 0;
} 