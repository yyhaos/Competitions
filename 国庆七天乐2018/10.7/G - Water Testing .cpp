#include<bits/stdc++.h>
using namespace std;
struct Point
{
    double x,y;
    Point (){}
    Point (double _x,double _y)
    {
        x=_x;
        y=_y;
    }
    Point operator - (const Point &b)
    const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator ^ (const Point &b)
    const
    {
        return (x*b.y - y*b.x);
    }
    double operator * (const Point &b)
    const
    {
        return (x*b.x + y*b.y);
    }
};
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
double CalcArea(Point p[],int n)
{
    double res=0;
    for(int i=0;i<n;i++)
    {
        res+=(p[i]^p[(i+1)%n]);
    }
    return fabs(res/2.0);
}
Point a[100005];
double cont(Point a,Point b)
{
    if(a.x==b.x)
    {
        return fabs(a.y-b.y);
    }
    else
    {
        int dx=fabs(a.x-b.x);
        int dy=fabs(a.y-b.y);
        int g=gcd(dx,dy);
        if(dy==0)
            return double(dx);
        return double(g);
    }
}
int main ()
{
    //freopen("test.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&a[i].x,&a[i].y);
    }
    double area=CalcArea(a,n);
    //int ar=area;
    //cout<<area<<endl;
    double d=0;
    for(int i=0;i<n;i++)
    {
        d+=cont(a[i],a[(i+1)%n]);
    }
    long long ans=(area+1.00005-d/2.0);
    cout<<ans<<endl;
    return 0;
}
