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
ll si[100005];
ll p[100005];
vector <ll> M[100005];
ll fa[100005];
double dp[100005];
ll getsi(ll th)
{
    si[th]=1;
    ll s=M[th].size();
    for(int i=0;i<s;i++)
    {
        ll nxt=M[th][i];
        si[th]+=getsi(nxt);
    }
    return si[th];
}
void dfs(ll th)
{
    ll s=M[th].size();
    ll geng=si[th]-1;
    double st=dp[th]+1;
   // cout<<th<<" "<<st<<endl;
    for(int i=0;i<s;i++)
    {
        ll nxt=M[th][i];
        dp[nxt]=st+1.0*(geng-si[nxt])/2.0;
    }
    for(int i=0;i<s;i++)
    {
        ll nxt=M[th][i];
        dfs(nxt);
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
    for(int i=2;i<=n;i++)
    {
        scanf("%lld",&p[i]);
        M[p[i]].push_back(i);
        fa[i]=p[i];
     //   si[i]=1;
    }
    getsi(1);

    dp[1]=1;
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        if(i!=1)
            printf(" ");
        printf("%f",dp[i]);
    }

#ifdef use_t
}
#endif // use_t
    return 0;
}
