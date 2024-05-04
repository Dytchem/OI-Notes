#include<iostream>
using namespace std;
string ans [] = {
        "490", // 双引号中替换为 A 题的答案
        "BYQ", // 双引号中替换为 B 题的答案
        "4659", // 双引号中替换为 C 题的答案
        "40785", // 双引号中替换为 D 题的答案
        "DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRURRUURRDDDDRDRRRRRRDRRURRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDDRRRRRDDRRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR", // 双引号中替换为 E 题的答案
};
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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
//#define int long long
#define Inf 0x3f3f3f3f

int a[21][6];

signed main(){
	freopen("a.in","r",stdin);
	
	for (int i=1;i<=20;++i){
		for (int j=0;j<=5;++j) cin>>a[i][j];
	}
	
	int ans=0;
	for (int i=1;i<=20;++i){
		for (int j=1;j<=20;++j){
			if (j==i) continue;
			for (int k=1;k<=20;++k){
				if (k==i||k==j) continue;
				for (int l=1;l<=20;++l){
					if (l==i||l==j||l==k) continue;
					for (int m=1;m<=20;++m){
						if (m==i||m==j||m==k||m==l) continue;
						ans=max(ans,a[i][1]+a[j][2]+a[k][3]+a[l][4]+a[m][5]);
					}
				}
			}
		}
	}
	
	cout<<ans;
}

(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
#define Inf 0x3f3f3f3f

signed main(){
	freopen("a.in","r",stdin);
	
	int x=2019;
	string s;
	while (x){
		s.push_back(x%26-1+'A');
		x/=26;
	}
	reverse(s.begin(),s.end());
	cout<<s;
}

(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
#define Inf 0x3f3f3f3f

signed main(){
	int a[4]={1,1,1};
	for (int i=4;i<=20190324;++i){
		a[3]=(a[0]+a[1]+a[2])%10000;
		a[0]=a[1],a[1]=a[2],a[2]=a[3];
	}
	cout<<a[2];
}

(4)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
#define Inf 0x3f3f3f3f

bool check(int x){
	while (x){
		if (x%10==2||x%10==4) return true;
		x/=10;
	}
	return false;
}


signed main(){
	int a=2019;
	
	ll ans=0;
	for (int i=1;i<=a;++i){
		if (check(i)) continue;
		for (int j=i+1;j<=a-i-1;++j){
			if (check(j)) continue;
			int k=a-i-j;
			if (k<=j||check(k)) continue;
			++ans;
		}
	}
	cout<<ans;
}

(5)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
#define Inf 0x3f3f3f3f

const int n=30,m=50;
char s[n+5][m+5];
const char d[]={'D','L','R','U'},dx[]={1,0,0,-1},dy[]={0,-1,1,0};
struct P{
	int x,y;
};

P pre[n+5][m+5];
char dd[n+5][m+5];

bool vis[n+5][m+5];

signed main(){
	freopen("a.in","r",stdin);
	for (int i=1;i<=n;++i) scanf("%s",s[i]+1);
	for (int i=1;i<=n;++i) s[i][0]=s[i][m+1]='1';
	for (int j=1;j<=m;++j) s[0][j]=s[n+1][j]='1';
	
	
	queue<P> q;
	q.push(P{1,1});
	vis[1][1]=true;
	P now;
	while (true){
		P p=q.front();
		q.pop();
		for (int i=0;i<4;++i){
			int x=p.x+dx[i],y=p.y+dy[i];
			if (s[x][y]=='1'||vis[x][y]) continue;
			vis[x][y]=true;
			pre[x][y]=p;
			dd[x][y]=d[i];
			q.push(now=P{x,y});
			if (x==n&&y==m) goto end;
		}
	}
	end:
	deque<char> ans;
	
	while (dd[now.x][now.y]){
		ans.push_front(dd[now.x][now.y]);
		now=pre[now.x][now.y];
	}
	
	for (int i=0;i<ans.size();++i) cout<<ans[i];
}


*/