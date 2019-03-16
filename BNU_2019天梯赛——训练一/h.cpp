//Problem Web:https://vjudge.net/contest/288637#problem/H
//#include<bits/stdc++.h>
//#include<ext/rope>
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
    ll tt=0;
ll a[100];
ll DP[105][105];
ll dp(int n,int m,int now)
{
    if(DP[n][m]!=-1)
        return DP[n][m];

    if(n==tt)
        return 0;
    //cout<<n<<" "<<a[n]<<" "<<m<<endl;
    ll tmp=a[n]*now+dp(n+1,m,now*10);
    if(m>0)
    {
        tmp=min(tmp,dp(n+1,m-1,now));
    }
    return DP[n][m]=tmp;
    //return 1;
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
ll cnt[100];

for(ii=1;ii<=t;ii++)
{
    for(int j=0;j<=10;j++)
        cnt[j]=0;
#endif // use_t
    cin>>n>>m;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<=104;j++)
        {
            DP[i][j]=-1;
        }
    }
    tt=0;

    while(n)
    {
       // cout<<n<<endl;
        a[tt]=n%10;
        //cout<<a[tt];
        n/=10;
        tt++;
    }
    //cout<<tt<<endl;
    cout<<dp(0,m,1)<<endl;



#ifdef use_t
}
#endif // use_t
    return 0;
}
