//Problem Web:https://vjudge.net/contest/288922#problem/E
//#include<bits/stdc++.h>
//#include<ext/rope>
#include<map>
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
struct poi
{
    double x,y;
    poi(){};
    poi(double xx, double yy)
    {
        x=(xx);
        y=(yy);
    }
}p[105];
int sg(double x)
{
    if(x<-eps)
        return -1;
    if(x>eps)
        return 1;
    return 0;
}
double f(double x)
{
    return x*x;
}
double dis(poi a,poi b)
{
    return sqrt(f(a.x-b.x)+f(a.y-b.y));
}
bool on(poi a,poi b,poi c)
{

    if(sg(dis(a,b)-dis(b,c)+dis(a,c))==0 )
        return 1;

    if(sg(dis(a,b)-dis(b,c)-dis(a,c))==0 )
        return 1;
    if(sg(-dis(a,b)-dis(b,c)+dis(a,c))==0 )
        return 1;
    else
        return 0;
}
ll t,n,m;
#define use_t 1
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
    rep(i,1,n)
    {
        cin>>p[i].x>>p[i].y;
    }
    ll fl=1;
    rep(i,1,n)
    {
        rep(j,1,n)
        {
            rep(k,1,n)
            {
                if(on(p[i],p[j],p[k])==0)
                {
                    fl=0;
                }
            }
        }
    }
    if(fl)
    {
        cout<<"True\n";
    }
    else
        cout<<"False\n";




#ifdef use_t
}
#endif // use_t
    return 0;
}
