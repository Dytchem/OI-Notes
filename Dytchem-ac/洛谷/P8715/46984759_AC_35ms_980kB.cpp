#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long

const int N = 100005;
int n;
char s[N];
int nxt[N],pos[128];


signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;++i){
		pos[s[i]]=nxt[pos[s[i]]]=i;
	}
	for (char c='a';c<='z';++c) nxt[pos[c]]=n+1,pos[c]=0;
	int ans=0;
	for (int i=1;i<=n;++i){
		ans+=(i-pos[s[i]])*(nxt[i]-i);
		pos[s[i]]=i;
	}
	cout<<ans;
	
	return 0;
}