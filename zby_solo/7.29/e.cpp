//Problem Web:http://www.bnuoj.com/contest_problem_merge.php?cid=9518
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
double fa(ll x)
{
    return 1.0*x*x;
}
double dis(ll x1,ll x2,ll y1,ll y2)
{
    return sqrt(fa(x1-x2)+ fa(y1-y2));
}
double di (ll x1,ll x2,ll x0,ll y1,ll y2,ll y0)
{
    if(x1==x2 && y1==y2)
    {
        return dis(x1,x0,y1,y0);
    }
    double res,a,b,c;
    a=1.0*(x0-x1)*(y2-y1);
    b=1.0*(y0-y1)*(x1-x2);
    c=(a+b)*(a+b);
    a=pow(y2-y1,2);
    b=pow(x1-x2,2);
    c/=(a+b);
    res=sqrt(c);
    return res;

}
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1; else return 1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
    x = _x;y = _y;
    }
    Point operator -(const Point &b)const
    {
    return Point(x - b.x,y - b.y);
    }  //叉积
    double operator ^(const Point &b)const
    {
    return x*b.y - y*b.x;
    }  //点积
    double operator *(const Point &b)const
    {
    return x*b.x + y*b.y;
    }
};
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;e = _e;
    }
    pair<int,Point> operator &(const Line &b)const
    {
        Point res = s;
        if(sgn((s-e)^(b.s-b.e)) == 0)
        {
            if(sgn((s-b.e)^(b.s-b.e)) == 0)
                return make_pair(0,res);//重合             else return make_pair(1,res);//平行         }
            double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
            res.x += (e.x-s.x)*t;
            res.y += (e.y-s.y)*t;
            return make_pair(2,res);
        }
    }
};
double dis(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}

Point NearestPointToLineSeg(Point P,Line L)
{
    Point result;
    double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
    if(t >= 0 && t <= 1)
    {
        result.x = L.s.x + (L.e.x - L.s.x)*t;
        result.y = L.s.y + (L.e.y - L.s.y)*t;
    }
    else
    {
        if(dis(P,L.s) < dis(P,L.e))
            result = L.s;
        else result = L.e;
    }
    return result;
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
ll x1,x2,y1,y2;
ll cx,cy,r;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    cin>>cx>>cy>>r>>x1>>y1>>x2>>y2;
    Point a1,a2,a0;
    a1=Point(x1,y1);
    a2=Point(x2,y2);
    a0=Point(cx,cy);
    double dis1=dis(a1,a0);
    double dis2=dis(a2,a0);
//    double dis2=dis(cx,x2,cy,y2);
//    cout<<dis1<<" "<<dis2<<endl;
    if(dis1<r+0.0000001 && dis2<r+0.000001)
    {
        cout<<"ALL IN\n";
        continue;
    }

    Point now=NearestPointToLineSeg( a0,Line(a1,a2) );
    double dis3 = dis(now,a0);
//    cout<<dis3<<"--\n";

//    double mid=sqrt(fa(x1/2.0-cx+x2/2.0)+ fa(y1/2.0+y2/2.0-cy));
    if(dis3>r-0.00000001 )
    {
        cout<<"ALL OUT\n";
        continue;
    }

    cout<<"PART IN\n";
        continue;

#ifdef use_t
}
#endif // use_t
    return 0;
}


