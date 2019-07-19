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
ll tt[1000005];
ll get(ll h,ll m,ll s)
{
    h%=12;
    return 60*60*h+m*60+s;
}
ll man=12*60*60;
ll __(ll x)
{
    if(x<0)
        return x+man;
    if(x>=man)
        return x%man;
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
    cin>>n;
    ll h,m,s;
    ll now=0;
    cin>>h>>m>>s;
    now=get(h,m,s);
    double tn=6;
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld%lld",&h,&m,&s);
        tt[i]=get(h,m,s)-now;
    }
    sort(tt,tt+n);


//    for(int i=0;i<n;i++)
//    {
//        cout<<"tt:"<<" "<<tt[i]<<endl;
//    }

    ll ans=INF;
//    ll zheng=upper_bound(tt,tt+n,0LL);

    if(n==1)
    {
        printf("%.2f",min(abs(tt[0]),man-abs(tt[0]))*6.0);
        return 0;
    }
    for(int st=0;st<n;st++)
    {
        ll tmp=abs(tt[st]);
        tmp=min(tmp,abs(man-tt[st] ));
        ll tao=tt[st]-tt[(st-1+n)%n];
        if(tao<0)
            tao+=man;
// cout<<"you1  "<<tmp<<" "<<man-tao<<endl;
        tmp+=man-tao;
// cout<<"you  "<<tmp<<" "<<man-tao<<endl;



        ans=min(ans,tmp);
    }

    for(int st=0;st<n;st++)
    {
        ll tmp=abs(tt[st]);
        tmp=min(tmp,abs(man-tt[st] ));
        ll tao=-tt[st]+tt[(st+1+n)%n];
        if(tao<0)
            tao+=man;

        tmp+=man-tao;
//        cout<<"zuo  "<<tmp<<endl;



        ans=min(ans,tmp);
    }
//    printf("%lld\n",ans);
    printf("%.2f\n",ans*6.0);


#ifdef use_t
}
#endif // use_t
    return 0;
}


