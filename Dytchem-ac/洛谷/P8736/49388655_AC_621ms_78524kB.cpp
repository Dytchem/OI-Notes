#include <bits/stdc++.h>
using namespace std;
//#define int ll
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
#define Inf 0x3f3f3f3f

const int N = 1000006;
char a0[N];
string a[N];
pair<string,int> ps[N];
int n=0;
int b[N],ans[N],ans1[N],pre[N];

signed main(){
	cin>>a0;
	int l=strlen(a0);
	for (int i=0;i<l;){
		a[++n].push_back(a0[i]);
		for (++i;'a'<=a0[i]&&a0[i]<='z';++i) a[n].push_back(a0[i]);
	}
	//for (int i=1;i<=n;++i) cout<<a[i]<<'\n';
	for (int i=1;i<=n;++i) ps[i]=make_pair(a[i],i);
	sort(ps+1,ps+1+n);
	ps[0].first=ps[1].first;
	for (int i=1,t=1;i<=n;++i){
		if (ps[i].first==ps[i-1].first) b[ps[i].second]=t;
		else b[ps[i].second]=++t;
	}
	//for (int i=1;i<=n;++i) cout<<b[i]<<' '; cout<<'\n';
	int len=0;
	for (int i=1;i<=n;++i){
		int pos=lower_bound(ans,ans+1+len,b[i])-ans;
		pre[i]=ans1[pos-1];
		if (pos==len+1) ++len;
		ans[pos]=b[i];
		ans1[pos]=i;
		//for (int j=0;j<=len;++j) cout<<ans[j]<<' '; cout<<'\n'; 
	}
	//cout<<len;
	for (int i=ans1[len],j=len+1;i;i=pre[i]) ans[--j]=i;
	//for (int i=1;i<=len;++i) cout<<ans[i]<<' '; cout<<'\n';
	for (int i=1;i<=len;++i) cout<<a[ans[i]];
}

/*

AaBaCaEaDaYsdXdsZfsdf

ABCABCDEFABG

*/