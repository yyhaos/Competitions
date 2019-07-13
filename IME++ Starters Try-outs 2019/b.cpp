//Problem Web:https://codeforces.com/gym/225575
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
char a[1005],b[1005];
ll ca,cb;
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
#endif // use_t
    scanf("%s%s",a,b);
    ca=strlen(a);
    cb=strlen(b);

    mem(dp,0);
    for(int i=1;i<=ca;i++)
    {
        for(int j=1;j<=cb;j++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
            }
        }
    }
    cout<<dp[ca][cb];


#ifdef use_t
}
#endif // use_t
    return 0;
}



