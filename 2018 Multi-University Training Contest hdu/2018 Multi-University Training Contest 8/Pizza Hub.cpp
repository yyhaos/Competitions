#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double PI=acos(-1.0)/2.0;
struct Point
{
    ll x,y;
}p[5];
    Point operator-(Point a,Point b)
    {
        return (Point){a.x-b.x,a.y-b.y};
    }
    double dis(Point a,Point b)
    {
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
    ll operator*(Point a,Point b)
    {
        return a.x*b.x+a.y*b.y;
    }
    ll operator^(Point a,Point b)
    {
        return a.x*b.y-a.y*b.x;
    }
double ans;
ll w;
void c(Point a,Point b)
{

    if(a*b<0)return;
    if(a*a<=w*w)
    {
        ll area=a^b;
        if(area<0)
            area*=-1;
        if((a*b)*(a*b)<=w*w*(a*a))
        {
            ans=min(ans,area/sqrt(a*a));
            //printf("%lf %lld %lld - %lld %lld\n",ans,a.x,a.y,b.x,b.y);
        }
    }
    else
    {
        double tem=atan(sqrt(a*a-w*w)/w);
        double ab=acos(a*b/sqrt(a*a)/sqrt(b*b));
   // printf("%lf %lf\n",tem,ab);
        if((a^b)>=0)
        {
            if(ab+tem>PI+1e-9)      //±ØÐë+1e-9
                return;
            if(sqrt(b*b)*cos(tem+ab)>w)
                return;
            double h=max(sqrt(a*a-w*w),sqrt(b*b)*sin(tem+ab));
            ans=min(ans,h);
    // printf("1-%lf %lld %lld - %lld %lld\n",ans,a.x,a.y,b.x,b.y);
        }
        else
        {
            if(tem-ab<0)
                return;
            if(sqrt(b*b)*cos(tem-ab)>w)
                return;
            double h=sqrt(a*a-w*w);
            ans=min(ans,h);
    //printf("2-%lf %lld %lld - %lld %lld\n",ans,a.x,a.y,b.x,b.y);
        }
    }
}

int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=3;i++)
        {
            scanf("%lld%lld",&p[i].x,&p[i].y);
        }
        scanf("%lld",&w);
        ans=9999999999999.0;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                for(int k=1;k<=3;k++)
                if(i!=j && i!=k && k!=j)
                    c(p[j]-p[i],p[k]-p[i]);
            }
        }
        for(int i=1;i<=3;i++)p[i].y=-p[i].y;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                for(int k=1;k<=3;k++)
                if(i!=j && i!=k && k!=j)
                    c(p[j]-p[i],p[k]-p[i]);
            }
        }
        if(ans>9999999999)
        {
            printf("impossible\n");
            continue;
        }
        printf("%.9lf\n",ans);
    }

    return 0;
}
