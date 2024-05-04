#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 4000006, M = 1000006;
int A,B,C,m;

struct DATA{
	int a[N];
	int& operator ()(int i,int j,int k){
		return a[(i*B+j)*C+k];
	}
	void clear(){
		memset(a,0,sizeof(a));
	}
}H,dif,sum;

struct ATTACK{
	int al,ar,bl,br,cl,cr,h;
}atk[M];

void attk(int p){
	const ATTACK& o=atk[p];
	dif(o.al,o.bl,o.cl)+=o.h;
	dif(o.ar+1,o.bl,o.cl)-=o.h;
	dif(o.al,o.br+1,o.cl)-=o.h;
	dif(o.al,o.bl,o.cr+1)-=o.h;
	dif(o.ar+1,o.br+1,o.cl)+=o.h;
	dif(o.ar+1,o.bl,o.cr+1)+=o.h;
	dif(o.al,o.br+1,o.cr+1)+=o.h;
	dif(o.ar+1,o.br+1,o.cr+1)-=o.h;
}

int qry(int i,int j,int k){
	return sum(i,j,k)=dif(i,j,k)+sum(i-1,j,k)+sum(i,j-1,k)+sum(i,j,k-1)
	-sum(i-1,j-1,k)-sum(i-1,j,k-1)-sum(i,j-1,k-1)+sum(i-1,j-1,k-1);
}

bool check(int t){
	dif.clear();
	sum.clear();
	for (int i=1;i<=t;++i) attk(i);
	for (int i=1;i<=A;++i)
		for (int j=1;j<=B;++j)
			for (int k=1;k<=C;++k)
				if (qry(i,j,k)>H(i,j,k)) return true;
	return false;
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>A>>B>>C>>m;
	for (int i=1;i<=A;++i)
		for (int j=1;j<=B;++j)
			for (int k=1;k<=C;++k)
				cin>>H(i,j,k);
	for (int i=1;i<=m;++i)
		cin>>atk[i].al>>atk[i].ar>>atk[i].bl>>atk[i].br>>atk[i].cl>>atk[i].cr>>atk[i].h;
	
	int l=0,r=m;
	while (r-l>1){
		int mid=l+r>>1;
		if (check(mid)) r=mid;
		else l=mid;
	}
	cout<<r;
}