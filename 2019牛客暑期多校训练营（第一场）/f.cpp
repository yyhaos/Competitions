//Problem Web:https://ac.nowcoder.com/acm/contest/881/E
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
ll k[10005];
ll C(ll m,ll n)
{
    return k[m]*ksm(k[n],q-2)%q*ksm(k[m-n],q-2)%q;
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
ll x1,x2,x3,y1,y2,y3;

    double ave;
    double ssum=0;
    double s=sqrt(3)/24.0;
    ll cnt=1000000;
    ll maxn=1000000;
    ll fen=0.25;
    for(int i=0;i<cnt;i++)
    {
        ll tx=rand();
        ll ty=rand();
        tx%=maxn;
        ty%=maxn;
        double y=1.0*ty/maxn;
        double x=1.0*tx/maxn;
//cout<<x<<" "<<y<<endl;
        if(y<0.25)
        {
            if(x<y/(0.25+0.000000000001))
            {
                ssum+=1.0/2.0*(y*sqrt(3)/3.0+sqrt(3)/6.0);
            }
            else
            {
                continue;
            }
        }
        else
        {
            if(x<(1.0-y)/0.75)
                ssum+=1.0/2.0*(y*sqrt(3)/3.0+sqrt(3)/6.0);

        }
    }
    cout<<1.0*ssum/s/cnt<<" "<<36.0*ssum/s/cnt<<endl;

    while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
    {
        ll n=18;

        double a,b,c,p,s;
        a=sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        b=sqrt( (x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
        c=sqrt( (x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        p=(a+b+c)/2;
        s=sqrt(p*(p-a)*(p-b)*(p-c));
       // cout<<s<<endl;
        ll S=(ll)(s*n+0.1);

        cout<<S<<"\n";
    }

    //rand()%100;



#ifdef use_t
}
#endif // use_t
    return 0;
}



