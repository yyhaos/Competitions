//Problem Web:https://vjudge.net/contest/330737#problem/A
#include<bits/stdc++.h>
#include<ext/rope> //using __gnu_cxx
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
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

ll t,n,m;
ll dp[100005]={};

ll dfs(ll x)
{
    if(dp[x]!=0 )
        return dp[x];
    for(int i=1;i<=x-2;i++)
    {
        ll yu=x-i-2;
        if(yu==0)
        {
            if(dp[i]==0)
                return dp[x]=1;
        }
        else
        {
            if(dp[i]+dp[yu]!=1)
                return dp[x]=1;
        }
    }
    return dp[x]=0;
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;

dp[3]=1;
dp[1]=0;
dp[2]=1;

//for(int i=1;i<=100;i++)
//{
//    printf("%d ",dfs(i));
//}
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    cin>>n;
    if(n%16 == 5 || n%16==9)
        cout<<"Second\n";
    else
        cout<<"First\n";


#ifdef use_t
}
#endif // use_t
    return 0;
}


