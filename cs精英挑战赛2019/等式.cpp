
//Problem Web:https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=3237
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

ll f[300005];
ll da[500005][2];
ll fa(ll x)
{
    if(f[x]==x)
        return x;
    else
        return f[x]=fa(f[x]);
}
void un(ll x,ll y)
{
    f[fa(x)]=fa(y);
    fa(x);
    fa(y);
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
    for(int i=1;i<=n;i++)
        f[i]=i;
    ll cnt=0;
    ll x,y,e;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&x,&y,&e);
        if(e==1)
        {
            un(x,y);
        }
        else
        {
            da[cnt][0]=x;
            da[cnt++][1]=y;
        }
    }
    ll faa=1;
    for(int i=0;i<cnt;i++)
    {
      //  cout<<da[i][0]<<" "<<da[i][1]<<endl;
        if(fa(da[i][0]) == fa(da[i][1]))
            faa=0;
    }
    if(faa)
        printf("Yes\n");
    else
        printf("No\n");




#ifdef use_t
}
#endif // use_t
    return 0;
}
