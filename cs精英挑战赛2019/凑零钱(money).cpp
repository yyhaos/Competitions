//Problem Web:https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=3227
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
ll v;
ll w[35];
ll dp[2][1000];
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
    cin>>n>>v;

    mem(dp,0);
    rep(i,1,n)
        scanf("%lld",&w[i]);
    //rep(i,0,n)
    dp[0][0]=1;
    dp[1][0]=1;
    ll tn,tx;
    for(int j=1;j<=n;j++)
    {
        tn=j%2;
        tx=1-tn;
        //cout<<dp[i]<<" "<<i<<endl;
        for(int i=1;i<=v;i++)
        {
            dp[tn][i]=dp[tx][i];
            if(w[j]<=i)
                dp[tn][i]+=dp[tx][i-w[j]];

          //  cout<<dp[tn][i]<<" "<<dp[tx][i]<<" "<<i<<endl;
        }
        for(int i=1;i<=v;i++)
        {
            //if(w[j]<=i)

           // cout<<dp[tn][i]<<" "<<dp[tx][i]<<" "<<i<<endl;
        }

    }

    cout<<dp[tn][v];
//    cout<<dp[tx][v];





#ifdef use_t
}
#endif // use_t
    return 0;
}

