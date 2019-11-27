//Problem Web:https://vjudge.net/contest/330734#problem/A
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

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
freopen("grave.in","r",stdin);
freopen("grave.out","w",stdout);

#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    ll x1,y1,x2,y2;
    ll x3,y3,x4,y4;
    ll w,h;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>w>>h;

    ll tx=x1+w,ty=y2-h;

    if(y2-y1 < h || x2-x1<w)
    {
        printf("No");
        return 0;
    }

    if(tx>x3 && ty<y4)
    {

    }
    else
    {
        printf("Yes");
        return 0;
    }
    tx=x2-w,ty=y2-h;
    if(tx<x4 && ty<y4)
    {

    }
    else
    {
        printf("Yes");
        return 0;
    }

    tx=x1+w;ty=y1+h;
    if(tx>x3 && ty>y3)
    {

    }
    else
    {
        printf("Yes");
        return 0;
    }

    tx=x2-w;
    ty=y1+h;
    if(tx<x4 && ty>y3)
    {

    }
    else
    {
        printf("Yes");
        return 0;
    }

    printf("No");
#ifdef use_t
}
#endif // use_t
    return 0;
}



