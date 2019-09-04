//Problem Web:https://codeforces.com/gym/101982/attachments
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
double fa(ll x)
{
    return 1.0*x*x;
}
double  dis(ll x,ll y,ll x1,ll y1)
{
        return sqrt( fa(x-x1) + fa(y-y1) );
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

    ll x,y,x1,y1,x2,y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    double ans=INF;
    if(y<=y2 && y>=y1)

    ans=min(ans, fabs(x-x1) );
    if(y<=y2 && y>=y1)
    ans=min(ans, fabs(x-x2) );
    if(x<=x2 && x>=x1)
    ans=min(ans, fabs(y-y1) );
    if(x<=x2 && x>=x1)
    ans=min(ans, fabs(y-y2) );

    ans=min(ans,dis(x,y,x1,y1));
    ans=min(ans,dis(x,y,x1,y2));
    ans=min(ans,dis(x,y,x2,y1));
    ans=min(ans,dis(x,y,x2,y2));


    printf("%.3f",ans);


#ifdef use_t
}
#endif // use_t
    return 0;
}


