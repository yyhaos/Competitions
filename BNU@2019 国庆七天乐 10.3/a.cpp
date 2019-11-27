//Problem Web:
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
ll w[10]={6,2,5,5,4,5,6,3,7,6};
ll dp[10][1000005];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("auxiliary.in","r",stdin);
    freopen("auxiliary.out","w",stdout);
#endif

#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    cin>>n;
//    for(int i=0;i<=9;i++)
//    {
//        for(int j=0;j<=n;j++)
//        {
//            dp[i][j]=-1;
//        }
//    }
//    for(int i=0;i<=9;i++)
//    {
//        for(int j=0;j<=n;j++)
//        {
//
//            if(j==0)
//            {
//                dp[i][j]=0;
//            }
//            else
//            {
//                if(i)
//                    dp[i][j]=dp[i-1][j];
//                if(j>=w[i])
//                {
//                    if(dp[i][j-w[i]]!=-1)
//                    {
//                        if(dp[i][j]==-1)
//                        {
//                            dp[i][j]=i+dp[i][j-w[i]];
//                        }
//                        else
//                        {
//                            dp[i][j]=max(dp[i][j],i+dp[i][j-w[i]]);
//                        }
//                    }
//                }
//            }
//
////            cout<<dp[i][j]<<" ";
//        }
////        cout<<endl;
//    }
//ll ans1=0;
//    for(int i=0;i<=9;i++)
//    {
////        cout<<dp[i][n]<< ' ';
//        ans1=max(ans1,dp[i][n]);
//    }
//    cout<<ans1<<endl;
//
ll ans;
    if(n%3==2)
    {
        ans=n/3*7+1;
    }
    else if(n%3==1)
    {
        ans=n/3*7-7+4;
    }
    else ans=n/3*7;
    cout<<ans;


#ifdef use_t
}
#endif // use_t
    return 0;
}

