//Problem Web:https://ac.nowcoder.com/acm/contest/885#countdown
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
double bian[3];
ll sgn(double x)
{
    if(x>eps)
        return 1;
    if(x<-eps)
        return -1;
    return 0;
}

inline double getd(double x, double e,double a)
{
    return e*x+a;
}
double dis(double x,double y,double x2,double y2)
{
    double c1=x2-x;
    double c2=y2-y;
    return sqrt(c1*c1+c2*c2);
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
    Point transXY(double B)
    {
        Point tmp;
        //double tx=x,ty=y;
        tmp.x=x*cos(B) - y* sin(B);
        tmp.y=x*sin(B) + y* cos(B);
        return tmp;
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


    double w,h,a,b,c;

    scanf("%lf%lf%lf%lf%lf",&w,&h,&bian[0],&bian[1],&bian[2]);
//    sort(bian,bian+3);
    ll fa=0;
    ll ans=0;
    if(w<h)
    {
        fa=1;
        swap(w,h);
    }
    double sum=0;
    for(int i=0;i<3;i++)
        sum+=bian[i];
    double jiaoju,changzhou,duanzhou,e;
    double x1,x2;
    double bei=1.0/3.0;
    double bei2=1-bei;
    double d,d2,l,r;

    double tar=0;
    for(int i=0;i<3;i++)
    {
        if(ans)
            break;
        jiaoju=bian[i];
        changzhou=sum-jiaoju;
        if(i)
        {
            tar=bian[0];
        }
        else
            tar=bian[1];
        duanzhou=sqrt( (changzhou*changzhou) - jiaoju*jiaoju );
        if(changzhou == 0)
        {
            printf("0 0 0 0 0 0\n");
            ans=1;
            continue;
        }
        e = jiaoju/changzhou;
        l=0,r=changzhou/2;
//        cout<<e<<" "<<" "<<tar<<" "<<changzhou<<" "<<duanzhou<<endl;
//        while(sgn(r-l)>0)
//        {
//            x1= bei*l + bei2*r;
////            x2= bei2*l + bei*r;
//            d=getd(x1,e,changzhou/2.0);
////            d2=getd(x2,e,changzhou/2.0);
//            if(d > tar)
//            {
//                r=x1;
//            }
//            else
//            {
//                l=x1;
//            }
//        }
        x1=(-tar+changzhou/2.0)/e;
        if(x1<0)
            x1=-x1;
        double y=duanzhou*sqrt(  0.25-x1*x1/changzhou/changzhou);

//        cout<<xx<<" "<<y<<endl;
        double xx=jiaoju;

//        cout<<tar<<" "<<changzhou<<" "<<jiaoju<<" "<<e<<" "<<x1<<"-"<<xx<<"-"<<y<<endl;

        x1+=jiaoju/2.0;
        double chg=1.0/300;

        Point aa(xx,0);
        Point bb(x1,y);

        double  dul=0,dur=PI;
        double mid;
        Point midd;
        Point midd2;
        double yyy,xxx,xi,yi;
        double sx,sy;
//        cout<<aa.x<<" "<<aa.y<<" +  "<<bb.x<<" "<<bb.y<<endl;
        while(dur > dul+1e-8)
        {
            if(ans)
                break;
//            cout<<dul<<" "<<dur<<endl;
            mid=0.5*(dur+dul);
            midd=aa.transXY(mid);
            midd2=bb.transXY(mid);
            yyy=max(midd.y,midd2.y);
            yyy=max(yyy,0.0);
            xxx=max(midd.x,midd2.x);
            xxx=max(xxx,0.0);
            xi=min(midd.x,midd2.x);
            xi=min(xi,0.0);
            yi=min(midd.y,midd2.y);
            yi=min(yi,0.0);
            sx=xxx-xi;
            sy=xxx-xi;
//            cout<<xxx<<" + "<<yyy<<" :"<<midd.x<<" "<<midd.y<<" "<<midd2.x<<" "<<midd2.y<<endl;
            if(yi <-eps || xi<-eps)
            {
                dur=max(dur-chg,mid);
            }
            else if( yyy>h+eps )
            {
                dur=max(dur-chg,mid);
            }
            else
            {
                dul=min(dul+chg,mid);
            }
            if( sgn(w-sx)>=0 && sgn(h-sy)>=0)
            {
//                if(midd.x<0)
//                    midd.x=0;
//                if(midd2.y<0)
//                    midd2.y=0;
//                if(midd2.x<0)
//                    midd2.x=0;
//                if(midd.y<0)
//                    midd.y=0;
//                if(midd.x>w)
//                    midd.x=w;
//                if(midd2.y>h)
//                    midd2.y=h;
//                if(midd2.x>w)
//                    midd2.x=w;
//                if(midd.y>h)
//                    midd.y=h;
                if(!fa)
                {
    //                cout<<0<<" "<<0<<" ";
                    printf("%.10f %.10f %.10f %.10f %.10f %.10f\n",-xi,-yi, midd.x-xi,midd.y-yi, midd2.x-xi,midd2.y-yi );
                }
                else
                {
                    printf("%.10f %.10f %.10f %.10f %.10f %.10f\n",-yi,-xi, midd.y-yi,midd.x-xi, midd2.y-yi,midd2.x-xi );
                }
                ans=1;
//                cout<<dis(-yi,-xi, midd.y-yi,midd.x-xi)<<" "<<dis(midd2.y-yi,midd2.x-xi, midd.y-yi,midd.x-xi)<<" "<<dis(midd2.y-yi,midd2.x-xi,-yi,-xi)<<endl;
            }
        }




    }


#ifdef use_t
}
#endif // use_t
    return 0;
}


