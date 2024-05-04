#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 300005, A = 1000006;
int a0[N];
int cnt[A];

signed main(){
	for (int i=1,a=1,b=1;a<A;++i){
		a0[i]=a;
		a+=b;
		swap(a,b);
	}
	
	int n;
	cin>>n;
	for (int i=1;i<=n;++i){
		int a;
		cin>>a;
		if (a0[i]==0) break;
		if (a%a0[i]==0) ++cnt[a/a0[i]];
	}
	
	int m = *max_element(cnt,cnt+A);
	
	cout << n-m;
	
	return 0;
}

/*

10
1 1 2 3 5 8 13 21 34 55

10
1 1 2 4 5 8 13 21 34 56

*/