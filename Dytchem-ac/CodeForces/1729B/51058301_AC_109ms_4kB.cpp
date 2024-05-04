#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
//#define int long long

char a[100];

signed main(){
	int t;cin>>t;while (t--){
		int n;cin>>n;
		cin>>a;
		string ans="";
		stack<int> s;
		for (int i=0;i<n;++i){
			if (a[i]=='0'){
				if (i+1<n&&a[i+1]=='0'){
					s.push(a[i]-'0');
					continue;
				}
				int b=s.top();
				s.pop();
				int a=s.top();
				s.pop();
				s.push(a*10+b);
			}
			else s.push(a[i]-'0');
			//cout<<'('<<a[i]-'0'<<")\n";
		}
		while (!s.empty()){
			//cout<<s.top()<<'\n';
			ans.push_back(char(s.top()+'a'-1));
			s.pop();
		}
		reverse(ans.begin(),ans.end());
		cout<<ans<<'\n';
	}
	
	return 0;
} 