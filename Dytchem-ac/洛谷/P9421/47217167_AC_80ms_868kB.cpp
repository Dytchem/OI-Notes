#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 100005;
int n,cnt[N];

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i){
		int a; cin>>a;
		cnt[a]++;
	}
	int lst=0,ans=0;
	for (int i=1;i<=n;++i){
		if (cnt[i]==0) continue;
		else if (cnt[i]==1) ++lst;
		else if (cnt[i]>2) lst-=cnt[i]-2,ans+=cnt[i]-2;
	}
	if (lst>=0) cout<<ans+lst/2;
	else cout<<ans;
	
	return 0;
}

/*

20
1 2 2 3 3 4 4 5 5 5 5 5 5 5 5 5 8 8 8 8

*/