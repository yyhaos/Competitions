//Problem Web:https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=3226
#include<bits/stdc++.h>
#include<ext/rope>
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
//#define use_t 1
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
//ll dp[1000][1000];
ll c(ll n,ll m)
{
    ll ans=1;
    if(m>n-m)
        m=n-m;
    for(ll i=m+1;i<=n;i++)
        ans=ans*i%q;
    for(ll i=1;i<=n-m;i++)
        ans=ans*ksm(i,q-2)%q;
    return ans;
}

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
    //mem(dp,0);

    cin>>n>>m;
    cout<<c(n+m*m-1,m*m-1);



#ifdef use_t
}
#endif // use_t
    return 0;
}

