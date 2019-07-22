
#include<bits/stdc++.h>
using namespace std;
double pi=3.1415926535;
int main ()
{
    freopen("glorious.in","r",stdin);
    //freopen("standard output","w",stdout);

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        double ans=0;
        double r,k;
        int n;
        scanf("%d%lf%lf",&n,&r,&k);
        double ar=2*pi/(1.0*k);
        r=2.0*r*tan(ar/2.0);
        //printf("%lf %lf\n",ar*180/pi,r);

        //printf("%lf",ar);
        double S=1.0*k*(r/2.0)/tan(ar/2.0)*r/2.0;
        //printf("%lf %lf\n",S);
        double rr=(r/2.0)/tan(ar/2.0);
        double s=rr*rr*pi;
        //printf("%lf %lf\n",S,s);
        double tem=S-s;
        double tt=tan(ar/2.0)*2.0*(r/2.0)/sin(ar/2.0)/r;
        for(int ii=1;ii<=n;ii++)
        {
            ans+=tem;
            tem*=tt*tt;
        }
        printf("Case %d: %.5lf\n",i,ans);
    }
    return 0;
}
