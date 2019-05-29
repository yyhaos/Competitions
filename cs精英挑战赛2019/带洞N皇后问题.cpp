//Problem Web:
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
ll M[12][12];
ll u[5][52];
ll offset=12;
ll cnt=0;
void dfs(ll th)
{
    if(th==n+1)
        cnt++;
    rep(i,1,n)
    {
        if(u[0][i]==0 && u[1][i+th]==0 && u[2][i-th+offset] == 0 && M[th][i]==0)
        {
u[0][i]=1 , u[1][i+th]=1 , u[2][i-th+offset] = 1;
            dfs(th+1);

u[0][i]= u[1][i+th]= u[2][i-th+offset] = 0;
        }
    }
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
    cin>>n;
    cnt=0;
    rep(i,1,n)
    rep(j,1,n)
    {
        scanf("%lld",&M[i][j]);
    }
    mem(u,0);
    dfs( 1);
    cout<<cnt;




#ifdef use_t
}
#endif // use_t
    return 0;
}

