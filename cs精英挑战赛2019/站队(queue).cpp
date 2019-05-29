//Problem Web:https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=3228
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
ll dp[1005][1005];
ll C[1005][1005];
ll A[1005];
ll a(ll x)
{
    if(x<0)
        return 0;
    if(A[x]!=-1)
        return A[x];
    if(x<=1)
        return A[x]=1;
    return A[x]=x*a(x-1)%q;
}
ll c(ll n,ll m)
{
    if(m>n-m)
        m=n-m;
    if(n<0 || m<0)
        return 0;
    if(C[n][m]!=-1)
        return C[n][m];
   // cout<<"c"<<n<<" "<<m<<endl;

    ll ans=0;
    if(m==0)
        ans=1;
    else
        ans=c(n-1,m)+c(n-1,m-1);
    return C[n][m]=ans%q;
}
ll dfs(ll n,ll m)
{
    if(n==m && m!=0)
        return 1;
    if(n<m)
        return 0;
    if(n<0 || m<0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    ll ans=0;
    if(n==0 || m==0)
        ans=0;
    else if(m==1)
        ans=a(n-1);
    else
    {
        for(int i=m;i<=n;i++)//枚举最大的那个的位置
        {
            ans+=dfs(i-1,m-1) * c(n-1,n-i)%q *a(n-i) %q;
            ans%=q;
          //  cout<<n<<" "<<m<<"++"<<dfs(i-1,m-1) * c(n-1,n-i)%q *a(n-i) %q<<endl;
          //  cout<<n<<"-"<<m<<" 枚举"<<i<<"位 "<<ans<<" dp"<<dp[i-1][m-1]<<" c"<<c(n-1,n-i)%q *a(n-i) %q<<endl;
        }
    }
   // dp[n][m]=ans%q;
  //   cout<<n<<"-"<<m<<" dp"<<dp[n][m]<<endl;

    return dp[n][m]=ans%q;
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
    cin>>n>>m;
    rep(i,0,1000)
    rep(j,0,1000)
        dp[i][j]=C[i][j]=A[i]=-1;
    cout<<dfs(n,m);
    rep(i,1,10)
    rep(j,1,i)
    {
        cout<<i<<" "<<j<<"="<<dfs(i,j)<<endl;
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}

