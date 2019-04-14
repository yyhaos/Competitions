//Problem Web:http://39.97.97.11/problem.php?cid=1003&pid=2
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

ll t,n,m;
ll a[1005];
ll st[1005];
ll top=0;
ll dp[1005][1005];

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
    top=0;
#endif // use_t

    cin>>n;
    rep(i,1,n)
    {
        cin>>a[i];
    }
    mem(dp,0);
    dp[1][1]=1;
    for(int jian=1;jian<=n;jian++)
    {
        for(int tree=1;tree<=n;tree++)
        {
            dp[tree][jian]=max(1LL,dp[tree][jian]);
            for(int ba=tree-jian;ba>=1;ba-=jian)
            {
                if(a[ba]<=a[ba+jian])
                {
                    dp[tree][jian]=max(dp[tree][jian],dp[ba][jian]+1);
                }
                else
                    break;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
    {
      //  cout<<dp[i][j]<<" ";
        ans=max(ans,dp[i][j]);
    }
   // cout<<endl;
    }

    cout<<n-ans<<endl;

#ifdef use_t
}
#endif // use_t
    return 0;
}

