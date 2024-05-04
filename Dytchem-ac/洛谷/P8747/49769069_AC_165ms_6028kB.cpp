#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n,m;
int sum0[N<<3],sum1[N<<3];
bool all0[N<<3],all1[N<<3]; // 0代表降序，1代表升序，sum代表总和 

void init(int l=1,int r=n,int p=1){
	if (l==r) sum0[p]=0,sum1[p]=1;
	else{
		int mid=l+r>>1,ps=p<<1;
		init(l,mid,ps);
		init(mid+1,r,ps|1);
		sum0[p]=sum0[ps]+sum0[ps|1];
		sum1[p]=sum1[ps]+sum1[ps|1];
	}
}

void pd(int p){
	if (all0[p]){
		sum0[p]+=sum1[p];
		sum1[p]=0;
		all0[p]=false;
		all0[p<<1]=all0[p<<1|1]=true;
		all1[p<<1]=all1[p<<1|1]=false;
	}
	else if (all1[p]){
		sum1[p]+=sum0[p];
		sum0[p]=0;
		all1[p]=false;
		all1[p<<1]=all1[p<<1|1]=true;
		all0[p<<1]=all0[p<<1|1]=false;
	}
}

int chg1(int num,int l=1,int r=n,int p=1){ //把最小的num个1（升序）改为0，返回还需改的剩余数 
	if (num==0) return 0;
	pd(p);
	if (num>=sum1[p]){
		all0[p]=true;
		return num-sum1[p];
	}
	sum1[p]-=num;
	sum0[p]+=num;
	int mid=l+r>>1,ps=p<<1;
	chg1(chg1(num,l,mid,ps),mid+1,r,ps|1);
	return 0;
}

int chg2(int num,int l=1,int r=n,int p=1){ //把最小的num个0（降序）改为1，返回还需改的剩余数 
	if (num==0) return 0; 
	pd(p);
	if (num>=sum0[p]){
		all1[p]=true;
		return num-sum0[p];
	}
	sum0[p]-=num;
	sum1[p]+=num;
	int mid=l+r>>1,ps=p<<1;
	chg2(chg2(num,l,mid,ps),mid+1,r,ps|1);
	return 0;
}

int a[N],pos=0;

void upd(int l=1,int r=n,int p=1){
	pd(p);
	if (l==r){
		a[++pos]=sum1[p];
		return;
	}
	int mid=l+r>>1,ps=p<<1;
	upd(l,mid,ps);
	upd(mid+1,r,ps|1);
}

signed main(){
	cin>>n>>m;
	init();
	int mid=1;
	while (m--){
		int p,q;
		cin>>p>>q;
		if (p==0){
			if (q>=mid){
				chg1(q-mid+1);
				mid=q+1;
			}
		}
		else{
			if (q<mid){
				chg2(mid-q);
				mid=q;
			}
		}
	}
	upd();
	for (int i=n;i>=1;--i){
		if (!a[i]) cout<<i<<' ';
	}
	for (int i=1;i<=n;++i){
		if (a[i]) cout<<i<<' ';
	}
	
	return 0;
}

/*

3 1
0 2

*/