//Problem Web:  https://vjudge.net/contest/239087#problem/L
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<string>
#include<map>
using namespace std;
#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
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
//ll t,n,m;
double fa(double a)
{
    return a*a;
};
struct pos
{
    double x,y;
    ll type,cnt;
    pos(){};
    pos(double xx, double yy, ll ty,ll ct)
    {
        x=xx;
        y=yy;
        type=ty;
        cnt=ct;
    }
    double dis(pos b)
    {
        return sqrt(fa(x-b.x)+fa(y-b.y));
    }
    double time(pos b)
    {
        double v=10;
        if((b.type==type) && (type!=0 )&& (((cnt-b.cnt)==1)||((b.cnt-cnt)==1)))
        {
            //cout<<cnt<<"-"<<b.cnt<<endl;
            v=40;
        }
        v*=1000;
        v/=60;
        return dis(b)/v;
    }
};
double x[205][205];
pos p[205];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
int ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
ll ii=1;
    p[201].type=p[0].type=0;
    double tx,ty;
    ll type=1;
    cin>>tx>>ty;
    p[0].x=tx;
    p[0].y=ty;
    p[0].cnt=0;
    cin>>tx>>ty;
    p[201].x=tx;
    p[201].y=ty;
    p[201].cnt=201;
    ll cnt=1;
    while(~scanf("%lf %lf",&tx,&ty))
    {
        if(tx==ty && tx==-1)
        {
            type++;
            continue;
        }
        p[cnt].x=tx;
        p[cnt].y=ty;
        p[cnt].type=type;
        p[cnt].cnt=cnt;
        cnt++;
    }
    //cnt--;
    rep(i,0,cnt)
    {
        rep(j,0,cnt)
        {
            x[i][j]=999999999999999.0;
        }
    }
    rep(i,0,cnt)
    {
        x[i][i]=0;
    }
    p[cnt]=p[201];
    //cout<<p[cnt].x<<" "<<p[cnt].y<<endl;
    rep(i,0,cnt)
    {
        rep(j,0,cnt)
        {
            x[i][j]=min(x[i][j],p[i].time(p[j]));
            x[j][i]=x[i][j];
        }
    }
    //cout<<type-1<<endl;
    rep(k,0,cnt)
    {
        rep(i,0,cnt)
        {
            rep(j,0,cnt)
            {
                if(x[i][j]>x[i][k]+x[k][j])
                {
                    x[i][j]=x[i][k]+x[k][j];
                }
            }
        }
    }
    cout<<(int)(0.5+x[0][cnt])<<endl;
    //cout<<x[0][cnt];
#ifdef use_t
}
#endif // use_t
    return 0;
}

