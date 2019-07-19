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

void myget(ll t,ll a[])
{
    a[0]=1;
    while(t)
    {
        a[a[0]++]=t%2;
        t/=2;
    }
}

ll t,n,m;
ll a[1000],b[1000];
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
    scanf("%lld",&n);
    myget(n,a);
    myget(n-1,b);
    ll ans=0;
  //  cout<<a[1];
    for(int i=1;i<a[0];i++)
    {
        if(a[i]!=b[i])
            ans++;
    }
    printf("%lld\n",ans);




#ifdef use_t
}
#endif // use_t
    return 0;
}

