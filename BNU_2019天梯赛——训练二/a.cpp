//Problem Web:  https://vjudge.net/contest/288922#problem/A
//#include<bits/stdc++.h>
//#include<ext/rope>
#include<map>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair

//const double PI=acos(-1.0);
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
struct sg
{
    ll l,r;
    sg(){}
    sg(ll s,ll rr)
    {
        l=s;
        r=rr;
    }
    friend bool operator<(sg a,sg b)
    {
        return a.l<b.l;
    }
}ss[105];
ll t,n,m;
//#define use_t 1
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
    ll L;
    cin>>L>>m;
    rep(i,1,m)
    {
        cin>>ss[i].l>>ss[i].r;
    }
    sort(ss+1,ss+m+1);
    ll rr=-1;
    ll ans=0;
    rep(i,1,m)
    {
        //cout<<ss[i].l<<" "<<ss[i].r<<endl;
        if(rr==-1)
        {
            ans+=ss[i].r-ss[i].l+1;
            rr=ss[i].r+1;
        }
        else
        {
            if(ss[i].r<rr)
                continue;
            if(ss[i].l<=rr)
            {
                ans+=ss[i].r-rr+1;
                rr=ss[i].r+1;
                continue;
            }
            else if(ss[i].l>rr)
            {
                ans+=ss[i].r-ss[i].l+1;
                rr=ss[i].r+1;
            }
        }
    }
    cout<<L-ans+1;





#ifdef use_t
}
#endif // use_t
    return 0;
}
