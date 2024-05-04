#include <bits/stdc++.h>
//#define int long long

using namespace std;
typedef long long ll;
typedef __int128 lll;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

stack<int> s;

inline void add0(int x){
    if (!s.empty()&&s.top() >= 0){
        int t = s.top();
        s.pop();
        s.push(t + x);
    }
    else{
        s.push(x);
    }
}

inline void add(char c)
{
    switch (c)
    {
    case 'x':
    {
        add0(1);
        break;
    }
    case '(':
    {
        s.push(-1);
        s.push(0);
        break;
    }
    case ')':
    {
        int a = s.top();
        s.pop();
        while (s.top()==-2){
        	s.pop();
       		int b = s.top();
        	s.pop();
        	a=max(a, b);	
		}
        s.pop();
        add0(a);
        break;
    }
    case '|':
    {
        s.push(-2);
        break;
    }
    }
}

signed main()
{
    add('(');
    char c;
    while (scanf("%c", &c) != EOF)
    {
        if (c == '\n')
            break;
        add(c);
        //cout<<s.top()<<'\n';
    }
    add(')');
    cout << s.top();
    return 0;
}