#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f

signed main(){
	char s[20];
	scanf("%s",s+1);
	int ans=0;
	int n=strlen(s+1);
	int p=1;
	for (int i=n,t=1;i>0;--i,++t){
		int cnt=0;
		for (int j=i+1;j<=n;++j) cnt+=s[i]>s[j];
		ans+=cnt*p;
		p*=t;
	}
	cout<<ans;
}