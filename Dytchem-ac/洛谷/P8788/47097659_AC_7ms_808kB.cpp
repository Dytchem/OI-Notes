#include<iostream>
using namespace std;
int main() {
    string ans [] = {
        "1286583532342313400", // 双引号中替换为 A 题的答案
        "106148357572143", // 双引号中替换为 B 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}


/*

(1)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

signed main(){
	lll p=1;
	for (int i=15;i<=28;++i) p*=i;
	lll ans=p;
	for (int i=1;i<=14;++i){
		p/=-i;
		ans+=p;
	}
	cout<<(ll)ans;
	
	return 0;
}

(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

inline ll pos(string s){
	ll re=0;
	for (ll i=17,p=1,n=1;i>=1;--i,++n){
		ll cnt=0;
		for (ll j=i+1;j<=17;++j) cnt+=s[i]>s[j];
		re+=cnt*p;
		p*=n;
	}
	return re;
}

signed main(){
	//cout<<pos(" abcdefghijklnpqro");
	
	ll a=pos(" aejcldbhpiogfqnkr");
	ll b=pos(" ncfjboqiealhkrpgd");
	
	ll p=1;
	for (ll i=1;i<=17;++i) p*=i;
	--p;
	
	if (a>b) swap(a,b); 
	
	cout<<min(abs(a-b),a+p-b+1);
	
	return 0;
}


*/ 