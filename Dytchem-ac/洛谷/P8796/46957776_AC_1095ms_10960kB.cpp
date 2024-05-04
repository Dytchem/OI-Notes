#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N=100005;
int n;
char s[N];

char a[N<<2][26];
bool laz[N<<2];

//void build(int l=1,int r=n,int p=1){}

inline void init(){
	for (int i=0;i<(N<<2);++i){
		for (char c=0;c<26;++c) a[i][c]=c;
	}
}

inline void down(int p){
	if (!laz[p]) return;
	laz[p]=false;
	int ls=p<<1;
	laz[ls]=laz[ls|1]=true;
	for (char c=0;c<26;++c) a[ls][c]=a[p][a[ls][c]],a[ls|1][c]=a[p][a[ls|1][c]];
	for (char c=0;c<26;++c) a[p][c]=c;
}

void change(char u,char v,int s,int t,int l=1,int r=n,int p=1){
	if (s==l&&t==r){
		for (char c=0;c<26;++c){
			if (a[p][c]==u) a[p][c]=v;
		}
		laz[p]=true;
		return;
	}
	down(p);
	int mid=l+r>>1,ls=p<<1;
	if (s<=mid) change(u,v,s,min(mid,t),l,mid,ls);
	if (t>mid) change(u,v,max(mid+1,s),t,mid+1,r,ls|1);
}

void work(int l=1,int r=n,int p=1){
	if (l==r){
		s[l]=a[p][s[l]-'a']+'a';
		return;
	}
	down(p);
	int mid=l+r>>1,ls=p<<1;
	work(l,mid,ls);
	work(mid+1,r,ls|1);
}

signed main(){
	init();
	scanf("%s",s+1);
	n=strlen(s+1);
	int m;
	cin>>m;
	while(m--){
		int l,r;
		char x,y;
		cin>>l>>r>>x>>y;
		change(x-'a',y-'a',l,r);
	}
	work();
	puts(s+1);
}

/*

abcaaea
1
1 7 c e

*/