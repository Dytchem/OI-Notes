#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N=502,K=502,P=123456;

int stf[N][K];

signed main(){
	stf[1][0]=1;
	
	for (int n=2;n<N-1;++n){
		stf[n][0]=2;
		for (int k=0;k<K-2;++k){
			stf[n+1][k]=(stf[n+1][k]+stf[n][k]*(k+1))%P;
			stf[n+1][k+1]=(stf[n+1][k+1]+stf[n][k]*2)%P;
			stf[n+1][k+2]=(stf[n+1][k+2]+stf[n][k]*(n-k-2))%P;
		}
	}
	
	int n,k;
	cin>>n>>k;
	
	cout<<stf[n][k-1];
	
	return 0;
}