#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
inline double sqr(double x)
{
    return x*x;
}
int cmp (double x)
{
    if(x>eps)
        return 1;
    else if(x<-eps)
        return -1;
    else

        return 0;
}
struct point
{
    double x,y;
    point(){}
    point(double a,double b):x(a),y(b){}
    void input(){scanf("lf%lf",&x,&y);}
    friend point operator +(const point &a,const point &b)
    {
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator -(const point &a,const point &b)
    {
        return point(a.x-b.x,a.y-b.y);
    }

    friend point operator *(const point &a,const double &b)
    {
        return point(a.x*b,a.y*b);
    }
    friend point operator *(const double &a,const point &b)
    {
        return point(a*b.x,a*b.y);
    }
    friend point operator /(const point &a,const double &b)
    {
        return point(a.x/b,a.y/b);
    }
    double norm()
    {
        return sqrt(sqr(x)+sqr(y));
    }
};
double det(const point &a,const point &b)
{
    return a.x*b.y-a.y*b.x;
}
double dot(const point &a,const point &b)
{
    return a.x*b.x+a.y*b.y;
}
double dist(const point &a, const point &b)
{
    return (a-b).norm();
}
point rotate_point(const point &p,double A)
{
    double tx=p.x,ty=p.y;
    return point(tx*cos(A)-ty*sin(A),tx*sin(A)+ty*cos(A));
}
point rotate(const point &p,double cost , double sint)
{
    double x=p.x,y=p.y;
    return point(x*cost-y*sint,x*sint+y*cost);
}
pair<point ,point> crosspoint (point ap,double ar,point bp,double br)
{
    double d=(ap-bp).norm();
    double cost=(ar*ar+d*d-br*br)/(2*ar*d);
    double sint=sqrt(1.0-cost*cost);
    point v=(bp-ap)/(bp-ap).norm()*ar;
    return make_pair(ap+rotate(v,cost,-sint),ap+rotate(v,cost,sint));
}
double C(double R)
{
    return pi*2*R;
}
int main ()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        double R;
        scanf("%d%lf",&n,&R);
        point o=point(0,0);
        double ans=C(R);
        while(n--)
        {
            //printf("%lf\n",ans);
            double x,y,r;
            scanf("%lf%lf%lf",&x,&y,&r);
            point tem=point(x,y);
            double dis=(tem-o).norm();
            if(cmp(dis+r-R)<0 || cmp(dis-r-R)>0)
                continue;
            else if(cmp(dis+r-R)==0)
                ans+=C(r);
            else if(cmp(dis-r-R)==0)
                continue;
            else
            {
                point a1,a2;
                a1=crosspoint(tem,r,o,R).first;
                a2=crosspoint(tem,r,o,R).second;
                double L=(a1-a2).norm()/2.0;
                double c1=asin(L/r)*2;
                double c2=asin(L/R)*2;
                double d1=sqrt(R*R-L*L);
                double d2=sqrt(r*r-L*L);
                if(cmp(d1+d2-dis)!=0)
                {
                    if(cmp(d1-d2)==-1)
                    {
                        c2=2*pi-c2;
                    }
                    else
                    {
                        c1=2*pi-c1;
                    }
                }
                ans+=c1/(2*pi)*C(r);
                //ans+=C(r);

                ans-=C(R)*c2/(2*pi);
            }
        }
        printf("%.16f\n",ans);
    }
    return 0;
}
