//Problem Web:  http://www.bnuoj.com/contest_show.php?cid=9478#problem/D
//#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
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
//const double PI=acos(-1.0);
const double eps=1e-12;
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
int sgn(double x)
{
    if(x<-eps)
        return -1;
    if(x>eps)
        return 1;
    else
        return 0;
}
struct Point
{
    double x,y;
    Point(){}
    Point (double _x,double _y)
    {
        x=_x;
        y=_y;
    }
    Point operator + (const Point &b)const
    {
        return Point(x+b.x,y+b.y);
    }
    Point operator * (const double &b)const
    {
        return Point(x*b,y*b);
    }
    Point operator - (const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    double operator *(const Point &b)
    {
        return x*b.x+y*b.y;
    }
    void show()
    {
        cout<<"dian: "<<x<<" "<<y<<endl;
    }
};
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s=_s;
        e=_e;
    }
    pair<int , Point> operator &(const Line &b)const
    {
        Point res=s;
        if(sgn((s-e) ^ (b.s-b.e))==0)
        {
            if(sgn((s-b.e) ^ (b.s-b.e))==0 )
            {
                return mp(0,res);
            }
            else return mp(1,res);
        }
        double t=((s-b.s) ^ (b.s-b.e))/((s-e) ^ (b.s-b.e));
        res.x+=(e.x -s.x)*t;
        res.y+=(e.y-s.y)*t;
        return mp(2,res);
    }
};
double dist(Point a,Point b)
{
    return sqrt((a-b) * (a-b));
}
bool inter (Line l1,Line l2)
{
    return max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn( (l2.s-l1.e) ^ (l1.s-l1.e)) * sgn( (l2.e-l1.e) ^(l1.s-l1.e)) <=0 &&
    sgn( (l1.s-l2.e) ^ (l2.s-l2.e)) * sgn( (l1.e-l2.e) ^ (l2.s-l2.e))<=0;
}
ll t,n,m;
Point p[1000005];
Line L[1000005];
vector<double> cp;
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
    rep(i,0,n-1)
    {
        cin>>p[i].x>>p[i].y;
    }
    Point sun;
    cin>>sun.x>>sun.y;
    rep(i,0,n-1)
    {
        ll nxt=(i+1)%n;
        L[i]=Line(p[i],p[nxt]);
    }
//    L[0].s.show();
//    L[0].e.show();
    double ans=0;
    rep(i,0,n-1)
    {
       // cout<<"i:"<<i<<endl;
        int nxt=(i+1+n)%n;
        double len=dist(p[i],p[nxt]);
        cp.clear();
        rep(j,0,n-1)
        {
            pr<int,Point> tmp= L[i] & Line(sun,p[j]);
            if(tmp.first ==2 && dist(tmp.second,p[i]) / len<=1.00000001 )
            {
                cp.push_back( dist(tmp.second,p[i]) / len);
            }
        }
        sort(cp.begin(),cp.end());
        for(int j=0;j<cp.size()-1;j++)
        {
           // cout<<cp[j] <<" - "<<cp[1+j]<<endl;
            Point mid = p[i]+(p[nxt]-p[i])*(cp[j]+cp[j+1])*0.5;
            Line S=Line(mid,sun);
            double flag=1.0;
            for(int k=0;k<n;k++)
            {
                if(k==i)
                    continue;
                if(inter(S,L[k]))
                    flag=0;
            }
            ans+=flag*len*(cp[j+1]-cp[j]);
        }
    }

    printf("%.12f",ans);
    if(ii!=t)
        cout<<endl;



#ifdef use_t
}
#endif // use_t
    return 0;
}
