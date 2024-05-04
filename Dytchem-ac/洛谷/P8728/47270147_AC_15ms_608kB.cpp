#include<iostream>
using namespace std;
int main() {
    string ans [] = {
        "563", // 双引号中替换为 A 题的答案
        "20312088", // 双引号中替换为 B 题的答案
        "39001250856960000", // 双引号中替换为 C 题的答案
        "3616159", // 双引号中替换为 D 题的答案
        "552", // 双引号中替换为 E 题的答案
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

bool have(int x){
	while (x){
		if (x%10==2) return true;
		x/=10;
	}
	return false;
} 

int main(){
	int ans=0;
	for (int i=1;i<=2020;++i){
		if (have(i)) ++ans;
	}
	cout<<ans;
}

(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 7100;
bool vis[N][N];
const int x[]={3000,5020,3011,5000},y[]={3000,3011,3014,5000};

int main(){
	for (int t=0;t<4;++t){
		for (int i=-2020;i<=2020;++i){
			int s=2020-abs(i);
			for (int j=-s;j<=s;++j){
				int m=x[t]+i,n=y[t]+j;
				if (m<0||n<0) continue;
				vis[m][n]=true;
			}
		}
	}
	int ans;
	for (int i=0;i<N;++i){
		for (int j=0;j<N;++j){
			if (vis[i][j]) ++ans;
		}
	}
	cout<<ans;
}

(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 102;

bool vis[N];
int ps[N],cur=0;
int cnt[N];

inline void init(){
	for (int i=2;i<N;++i){
		if (!vis[i]) ps[++cur]=i;
		for (int j=1;j<=cur&&i*ps[j]<N;++j){
			vis[i*ps[j]]=true;
			if (i%ps[j]==0) break;
		}
	}
}

int main(){
	init();
	for (int x=1;x<=100;++x){
		int y=x;
		for (int i=1;i<=cur;++i){
			int p=ps[i];
			if (y%p) continue;
			do y/=p,++cnt[p]; while(y%p==0);
		}
	}
	ll ans=1;
	for (int i=1;i<=cur;++i) ans*=cnt[ps[i]]+1;
	cout<<ans;
}

(4)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 202;
int n;
char s[N]=" tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhewl";
ll dp[N];

int main(){
	//cin>>s+1;
	n=strlen(s+1);
	for (int i=1;i<=n;++i){
		dp[i]=1;
		for (int j=1;j<i;++j){
			if (s[j]<s[i]) dp[i]+=dp[j];
			else if (s[j]==s[i]) dp[i]-=dp[j];
		}
	}
	ll ans=0;
	for (int i=1;i<=n;++i) ans+=dp[i];
	cout<<ans; 
}

(5)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
//#define int long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

const int N = 6;
bool vis[N][N];
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

ll ans=0;
void dfs(int x,int y,int cnt){
	if (cnt==16){
		++ans;
		return;
	}
	vis[x][y]=true;
	for (int i=0;i<4;++i){
		int x1=x+dx[i],y1=y+dy[i];
		if (vis[x1][y1]) continue;
		dfs(x1,y1,cnt+1);
	}
	vis[x][y]=false;
}

int main(){
	for (int i=1;i<=4;++i) vis[0][i]=vis[5][i]=vis[i][0]=vis[i][5]=true;
	for (int i=1;i<=4;++i){
		for (int j=1;j<=4;++j){
			dfs(i,j,1);
		}
	}
	cout<<ans;
}

*/