//Problem Web:https://ac.nowcoder.com/acm/contest/887#question
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
const ll q=1e18;
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
ll f(ll x)
{
    ll zong=0;
    ll tmp=x;
    while(tmp)
    {
        zong++;
        tmp/=10;
    }
    ll ans=0;
    for(int i=0;i<zong;i++)
    {
        ll th= x/ksm(10,i) %10;
        ans+=th*ksm(10,zong-i -1 );
    }
    return ans;
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
//ll k=(1<<31)-1;
//cout<<k<<endl;
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    ll a,b;
    cin>>a>>b;
    cout<<f(f(a)+f(b))<<"\n";





#ifdef use_t
}
#endif // use_t
    return 0;
}



