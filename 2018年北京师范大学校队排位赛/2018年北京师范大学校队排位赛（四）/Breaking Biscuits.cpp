#include<bits/stdc++.h>
using namespace std;
double eps=1e-10;
double x[105],y[105];
double dis(double x1,double x2,double y1,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int sig(double x,double y)
{
    if(x-y>eps)
        return 1;
    else if(x-y<-eps)
        return -1;
    else
        return 0;
}
double dis2(double x,double y,double x1,double x2,double y1,double y2)
{
    if(sig(x1,x2)==0)
    {
        return fabs(x-x1);
    }
    else if(sig(x,x1)==0 && sig(y,y1)==0)
        return 0;
    else if(sig(x,x2)==0 && sig(y,y2)==0)
        return 0;
    else
    {
        double k=(y1-y2)/(x1-x2);
        double b=-x1*k+y1;
        double dis=(k*x+b-y)/(sqrt(1+k*k));
        return fabs(dis);
    }
}
double dian(double x1,double y1,double x2,double y2)
{
    return sig(x1*y2-x2*y1,0);
}
int main ()
{
    int n;
    double xx1=0,xx2=0,yy1=0,yy2=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&x[i],&y[i]);
        /*if(i>=2&&n>=3)
        if(dian(x[i-1]-x[i-2],y[i-1]-y[i-2],(x[i]-x[i-2]),(y[i]-y[i-2]))<-eps)
        {
            x[i-1]=x[i];
            y[i-1]=y[i];
            n--;
            i--;
        }
        */
    }
    double ans=5.0*199999000.0;
    double maxn1,maxn2;
    for(int i=0;i<n-1;i++)
    {
        for(int k=i+1;k<=n-1;k++)
        {
            maxn1=0;
            maxn2=0;
            for(int j=0;j<n;j++)
            {
                if(j==i || j==k)
                    continue;
                if(dian(x[k]-x[i],y[k]-y[i],x[j]-x[i],y[j]-y[i])>0)
                    maxn1=max(maxn1,dis2(x[j],y[j],x[i],x[k],y[i],y[k]));
                else
                    maxn2=max(maxn2,dis2(x[j],y[j],x[i],x[k],y[i],y[k]));
            }
            ans=min(ans,maxn1+maxn2);
        }
    }
    /*
    maxn1=-1.0;
    maxn2=-1.0;
    for(int j=0;j<n;j++)
    {
        if(j==0 || j==n-1)
            continue;
        if(dian(x[n-1]-x[0],y[n-1]-y[0],x[j]-x[0],y[j]-y[0])>=0)
            maxn1=max(maxn1,dis2(x[j],y[j],x[n-1],x[0],y[n-1],y[0]));
        if(dian(x[n-1]-x[0],y[n-1]-y[0],x[j]-x[0],y[j]-y[0])<0)
            maxn2=max(maxn2,dis2(x[j],y[j],x[n-1],x[0],y[n-1],y[0]));
    }
    ans=min(ans,maxn1+maxn2);
    */
    if(ans<0)
        ans=0.0;
    printf("%.8lf",ans);
    return 0;
}

