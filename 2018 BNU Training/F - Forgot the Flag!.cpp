#include<bits/stdc++.h>
using namespace std;
double pi=acos(-1.0);
double tx,ty,xx,yy;
const double eps=1e-7;
const double PI=acos(-1.0);
int sig(double x)
{
    if(fabs(x)<eps)
        return 0;
    if(x<0)
        return -1;
    else
        return 1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x=_x;
        y=_y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator ^(const Point &b)const
    {
        return x*b.y-y*b.x;
    }
    double operator *(const Point &b)const
    {
        return x*b.x+y*b.y;
    }
    void transXY(double B)
    {
        double tx=x,ty=y;
        x=tx*cos(B)-ty*sin(B);
        y=tx*sin(B)+ty*cos(B);
    }
}Ps[500055];
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
        if(sig((s-e)^(b.s-b.e))==0)
        {
            if(sig((s-b.e)^(b.s-b.e))==0)
                return make_pair(0,res);
            else
                return make_pair(1,res);
        }
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x+=(e.x-s.x)*t;
        res.y+=(e.y-s.y)*t;
        return make_pair(2,res);
    }
};
double dist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool inter(Line l1,Line l2)
{
    return
    max(l1.s.x,l1.e.x)>=min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x)>=min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l1.e.y)>=min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y)>=min(l1.s.y,l1.e.y) &&
    sig((l2.s-l1.e)^(l1.s-l1.e))*sig((l2.e-l1.e)^(l1.s-l1.e))<=0 &&
    sig((l1.s-l2.e)^(l2.s-l2.e))*sig((l1.e-l2.e)^(l2.s-l2.e))<=0;
}
Point f_chui(Line l1,Line l2)
{
    Point ans;
    double k1=(l2.s.y-l2.e.y)/(l2.s.x-l2.e.x);
    double k2=(l1.e.y-l1.s.y)/(l1.e.x-l1.s.x);
    ans.x=(l2.e.y-l1.s.y-l2.s.x*k1+l1.s.x*k2)/(k1-k2);
    ans.y=k1*(ans.x-l1.s.x)+l1.s.y;

    return ans;
}
Point f(Point a,Line b)
{
   // printf("yi:%llf %llf ",a.x,a.y);
    Point ans;
    double k=(b.e.y-b.s.y)/(b.e.x-b.s.x);
   // printf("k = %llf ",k);
    Point tem;
    tem.x=a.x+1.0;
    tem.y=a.y+-1/k;
    Line s=Line(tem,a);
    Point chui=(s&b).second;
    Point yi=a-chui;
    yi.x=-yi.x;
    yi.y=-yi.y;
    yi.x+=chui.x;
    yi.y+=chui.y;
    //printf("yi:%llf %llf chui:%llf %llf\n",yi.x,yi.y,chui.x,chui.y);
    return yi;
}
double dis(Point P,Line L)
{
    Point result;
    double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
    result.x = L.s.x + (L.e.x-L.s.x)*t;
    result.y = L.s.y + (L.e.y-L.s.y)*t;
    return dist(result ,P);
}
int main ()
{
    freopen("flags.in","r",stdin);
    //freopen("standard output","w",stdout);
    int t;
    Point ans_p;
    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {
        printf("Case %d:\n",ii);
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            double temx,temy;
            double ans=0;
            double r,k;
            scanf("%lf%lf",&temx,&temy);
            Ps[i].x=temx;
            Ps[i].y=temy;
        }
        int q;
        scanf("%d",&q);
        //printf("q==%d\n",q);
        for(int j=1;j<=q;j++)
        {
            double ans=1e13;
            scanf("%lf%lf%lf%lf",&xx,&yy,&tx,&ty);
            for(int th=1;th<=n;th++)
            {
           //     printf("th=%d\n",th);
                Line te;
                Point st=Point(xx,yy);
                Point tr=Point(tx,ty);
                if(th==n)
                {
                    te.e=Ps[1];
                    te.s=Ps[n];
                }
                else
                {
                    te.e=Ps[th];
                    te.s=Ps[th+1];
                }
                Point le=te.e;
                Point ri=te.s;
                Point midl;
                Point midr;

                midl.x=(le.x*2.0+ri.x)/3.0;
                midl.y=(le.y*2.0+ri.y)/3.0;
                midr.x=(le.x+2.0*ri.x)/3.0;
                midr.y=(le.y+2.0*ri.y)/3.0;
                while(fabs(midl.x-midr.x)+fabs(midl.y-midr.y)>eps)
                {
                    double ll=dist(midl,st)+dist(midl,tr);
                    double lr=dist(midr,st)+dist(midr,tr);
                    if(ll<lr)
                    {
                        ri=midr;
                        midl.x=(le.x*2+ri.x)/3.0;
                        midl.y=(le.y*2+ri.y)/3.0;
                        midr.x=(le.x+2*ri.x)/3.0;
                        midr.y=(le.y+2*ri.y)/3.0;
                    }
                    else
                    {
                        le=midl;
                        midl.x=(le.x*2+ri.x)/3.0;
                        midl.y=(le.y*2+ri.y)/3.0;
                        midr.x=(le.x+2*ri.x)/3.0;
                        midr.y=(le.y+2*ri.y)/3.0;
                    }
                }
                double lt=dist(midr,st)+dist(midr,tr);
                if(ans>lt)
                {
                    ans=lt;
                    ans_p=midr;
                }
                /*
                if(sig(dis(st,te))==0)
                {
                    ans_p=st;
                    ans=dist(st,tr);
                    //printf("%lf %lf %lf\n",ans,ans_p.x,ans_p.y);
                    //break;
                }
                if(sig(dis(tr,te))==0)
                {
                    ans_p=tr;
                    ans=dist(tr,st);
                    //printf("%lf %lf %lf\n",ans,ans_p.x,ans_p.y);
                    //break;
                }
                Point dui;

                if(sig(te.e.x-te.s.x)==0)
                {
                    dui.x=2*te.e.x-tx;
                    dui.y=ty;
                }
                else
                {
                    Point ss=Point(tx,ty);
                    dui=f(ss,te);
                }
                Line te2=Line(st,dui);
                if(inter(te,te2))
                {
                    if(ans>dist(dui,st))
                    {
                        ans=dist(dui,st);
                        int tt;
                        ans_p=(te&te2).second;
                    }
                }
                else
                {
                    if(ans>dist(st,te.s)+dist(dui,te.s))
                    {
                        ans=dist(st,te.s)+dist(dui,te.s);
                        ans_p=te.s;
                    }
                    if(ans>dist(st,te.e)+dist(dui,te.e))
                    {
                        ans=dist(st,te.e)+dist(dui,te.e);
                        ans_p=te.e;
                    }
                }
                */
            }
            //printf("Case %d:\n",j);
            printf("%.8lf %.8lf %.8lf\n",ans,ans_p.x,ans_p.y);
        }
    }

    return 0;
}
