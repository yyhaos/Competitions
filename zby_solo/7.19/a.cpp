//Problem Web:https://vjudge.net/contest/312476#overview
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
ll cnt(ll a,ll c,ll p,ll m)
{
    if(a==-1 || c==-1)
        return 0;
    ll ta=(1+a)/p;
    a=(a+1)%p;
    ll tc=(1+c)/p;
    c=(c+1)%p;

    ll ans=ta*(p)*tc;
//    cout<<"ans1:"<<ans<<" ac:"<<a<<" "<<c<<endl;
    ans+=ta*c+tc*a;
//    cout<<"ans2:"<<ans<<endl;
//    if(a+c>m)
//    {
//        ans+=a+c-p;
//    }

    // a+c==m
    ll amax=a-1;
    ll cmax=c-1;

    if(amax < 0 || cmax<0)
    {

    }
    else
    {
        // a+c==m

        ll adui=m-amax;
//        cout<<amax<<" "<<cmax<<" adui  "<<adui<<endl;
        if(adui<0)
            adui=0;
        if(min(m,cmax)-adui+1>0)
            ans+=min(m,cmax)-adui+1;

        // a+c==m+p
        adui=p+m-amax;
        if(adui<0)
            adui=0;
//        cout<<amax<<" "<<cmax<<" adui2 "<<adui<<endl;
        if(min(m+p,cmax)-adui+1>0)
            ans+=min(m+p,cmax)-adui+1;

    }

//    cout<<"ans3:"<<ans<<endl;
    return ans;
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

    ll a,b,c,d,p,m;
    cin>>a>>b>>c>>d>>p>>m;
    ll fenmu=(b-a+1)*(d-c+1);
    ll fenzi=0;
    ll ac=cnt(a-1,c-1,p,m);
    ll bc=cnt(b,c-1,p,m);
    ll ad=cnt(a-1,d,p,m);
    ll bd=cnt(b,d,p,m);
    fenzi=bd+ac-ad-bc;
    ll gc=__gcd(fenzi,fenmu);
//    cout<<"ac:"<<ac<<" "<<endl;
//    cout<<"bc:"<<bc<<" "<<endl;
//    cout<<"ad:"<<ad<<" "<<endl;
//    cout<<"bd:"<<bd<<" "<<endl;
cout<<"Case #"<<ii<<": ";
//    cout<<fenzi<<" "<<fenmu<<" "<<__gcd(fenzi,fenmu)<<endl;
    cout<<fenzi/gc<<'/'<<fenmu/gc<<endl;
//    cout<<bd+ac-ad-bc<<" = "<<fenmu<<endl;




#ifdef use_t
}
#endif // use_t
    return 0;
}
