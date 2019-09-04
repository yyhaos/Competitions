//Problem Web:https://ac.nowcoder.com/acm/contest/889#countdown
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
const ll q=1000000000LL;
const double qq=1000000000.0;
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

double fia[10005];
double fib[10005];

double cf(double a, double b)
{
    if(a*b>qq)
    {
//        cout<<a*b<<" "<<(ll)(a*b/qq)<<endl;
        return a*b-((ll)(a*b/qq))*qq;
    }
    else if(a*b<0)
    {
        return qq+a*b+(ll)(-a*b/qq)*qq;
    }
    return a*b;
}
double myksm(double a, ll th)
{
    double ans=1;
    while(th)
    {
        if(th&1)
        {
            ans=cf(ans,a);
        }
        a=cf(a,a);
        th/=2;
    }
    return ans;
}
double getfib(ll th)
{
    double a=myksm((1.0+sqrt(5.0))/2.0,th );
    double b=myksm((1.0-sqrt(5.0))/2.0,th );
    return myksm(1.0/sqrt(5.0)*myksm(a-b+qq,1),1);
}
ll trans(double x)
{
    return (ll)(cf(1,x));
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
//cout<<cf(1000020,1000020);
    cin>>n>>m;
    cout<<getfib(1)<<endl;
    cout<<getfib(2)<<endl;
    cout<<getfib(3)<<endl;
    double y=getfib(m);
    ll ty=trans(y);

    cout<<y<<" "<<ty<<endl;
    double yn=getfib(m*n);
    ll tyn=trans(yn);

    cout<<yn<<" "<<tyn<<endl;
//    double fz=myksm(cf(1,1.0-y),q-2);
    ll ans=trans( y*(yn-1)/(1-y) );
//    ll ans= ty*(tyn-1)%q * ksm(ty-1,q-2)%q;
    cout<<ans;





#ifdef use_t
}
#endif // use_t
    return 0;
}


