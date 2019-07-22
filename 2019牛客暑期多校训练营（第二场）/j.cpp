
//Problem Web:https://ac.nowcoder.com/acm/contest/882#countdown
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
ll dp[20000005];
ll ans=0;
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

    cin>>n;
    dp[0]=1;
    ll sum=0;
    ll l=0,r=-1;
    ll ans=0;
    ll prer=0;
    for(int i=0;i<n;i++)
    {
        prer=r;
        scanf("%lld %lld",&l,&r);
        for(int i=prer+1;i<=r && sum>1e-7;i++)
        {
            处理 -1
        }
        sum+=-(l-1 - r+1 +1);


        for(int j=l;j<=r;j++)
        {
            sum+=1;

            答案更新 ans+=qianzhui[sum]

            前缀更新： dp[sum]++
            前缀和更新：

        }

    }
    l=1e9;
    处理最后的负数到 1e9




#ifdef use_t
}
#endif // use_t
    return 0;
}
