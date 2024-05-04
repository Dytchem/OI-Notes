#include <bits/stdc++.h>
using namespace std;
//#define int ll
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
#define Inf 0x3f3f3f3f

const int N = 25;
int n;
map<string,int> stf;

int f(string s){
	if (stf.find(s)!=stf.end()) return stf[s];
	int cnt=0;
	bool flag=false;
	for (int i=0;i<n;++i){
		if (s[i]!='*') continue;
		++cnt;
		string ss=s;
		
		ss[i]='L';
		for (int j=max(0,i-2);j<=i;++j){
			if (ss.substr(j,3)=="LOL") return stf[s]=1;
		}
		int ff=f(ss);
		if (ff==-1) return stf[s]=1;
		if (ff==0) flag=true;
		
		ss[i]='O';
		for (int j=max(0,i-2);j<=i;++j){
			if (ss.substr(j,3)=="LOL") return stf[s]=1;
		}
		ff=f(ss);
		if (ff==-1) return stf[s]=1;
		if (ff==0) flag=true;
	}
	if (cnt==0||flag) return stf[s]=0;
	return stf[s]=-1;
}

signed main(){
	int t;cin>>t;
	while (t--){
		string s;cin>>s;
		n=s.size();
		cout<<f(s)<<'\n';
	}
}