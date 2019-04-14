//Problem Web:http://39.97.97.11/problem.php?cid=1003&pid=5
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1000;
const ll q=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a%q;
        a=a*a%q;
        b/=2LL;
    }
    return ans;
}
ll used[100005];
ll t,n,m;
map <string, int> na;

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    mem(used,0);
    na.clear();
    ll th=1;
    ll ans=0;
    queue<int > qu;
    cin>>n;
    string ty,name;
    while(n--)
    {
        cin>>ty>>name;
        if(na[name]==0)
        {
            na[name]=th++;
        }
        if(ty[0]=='i')
            qu.push(na[name]);
        else
        {
            if(!qu.empty() && qu.front() == na[name])
            {
                ans++;
                qu.pop();
                while(!qu.empty() && used[qu.front()] == 1)
                    qu.pop();
            }
            used[na[name]]=1;
        }
    }
cout<<ans<<endl;


#ifdef use_t
}
#endif // use_t
    return 0;
}

