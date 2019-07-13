//Problem Web:https://codeforces.com/gym/101810/countdown
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
ll a[1005];
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
    ll x;
    cin>>x>>n;
    mem(a,0);
    if(n==1)
    {
        cout<<x<<endl;
        continue;
    }
    if(n==2)
    {
        cout<<(x+1)/2<<" "<<x/2<<endl;
        continue;
    }
    ll ans=x/(2*n-2);
    x=x%(2*n-2);
    for(int i=1;i<=n;i++)
    {
        a[i]=2*ans;
    }
    a[1]-=ans;
    a[n]-=ans;
    for(int i=1;i<=x && i<=n;i++)
    {
        a[i]++;
    }
    x-=n;
    for(int i=1;i<=x;i++)
    {
        a[n-i]++;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%lld",a[i]);
        if(i!=n)
            printf(" ");
    }
    printf("\n");


#ifdef use_t
}
#endif // use_t
    return 0;
}
