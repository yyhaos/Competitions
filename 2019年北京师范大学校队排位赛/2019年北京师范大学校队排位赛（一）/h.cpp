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


struct point
{
    double x,y;
};

struct line
{
    point a;point b;
};

point o;
point pl[100005];
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double xmult(double x1, double y1,double x2,double y2,double x0,double y0)
{
    return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}
double my(point p,line l)
{
    point t=p;
    t.x+=l.a.y-l.b.y,t.y+=l.b.x-l.a.x;
    if(xmult(l.a,t,p)* xmult(l.b,t,p)>eps)
        return dis(p,l.a)<dis(p,l.b)? dis(p,l.a):dis(p,l.b);
    return fabs(xmult(p,l.a,l.b))/dis(l.a,l.b);
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

    cin>>o.x>>o.y;
   // cout<<o.x<<" "<<o.y<<endl;
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&pl[i].x,&pl[i].y);
    }
    double r2=0,r1=INF;
    for(int i=0;i<n;i++)
    {
        r2=max(r2,dis(pl[i],o));
       // cout<<dis(pl[i],o)<<endl;
    }

    for(int i=0;i<n;i++)
    {
        int nxt=(i+1)%n;
        line tmp;
        tmp.a=pl[i];
        tmp.b=pl[nxt];
        r1=min(r1,my(o,tmp));
    }




    //cout<<r1<<" "<<r2<<endl;
    double ans=PI*r2*r2-PI*r1*r1;
    printf("%.10f",ans);




#ifdef use_t
}
#endif // use_t
    return 0;
}
