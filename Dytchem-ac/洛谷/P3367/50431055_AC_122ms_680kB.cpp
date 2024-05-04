#include <bits/stdc++.h>
using namespace std;

const int N = 10004;
int n,m;
int fa[N];

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void hb(int x,int y){
	fa[find(x)]=find(y);
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;++i) fa[i]=i;
	while (m--){
		int z,x,y;
		cin>>z>>x>>y;
		if (z==1){
			hb(x,y);
		}
		else{
			if (find(x)==find(y)) cout<<"Y\n";
			else cout<<"N\n";
		}
	}
	
	return 0;
} 

/*

3 3
1 1 2
1 2 1
2 1 2

*/