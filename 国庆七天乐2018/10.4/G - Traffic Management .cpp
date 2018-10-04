#include<bits/stdc++.h>
using namespace std;
struct car
{
    double x,v;
}c[100005];
bool cmp(car a,car b)
{
    return a.x<b.x;
}
int main ()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&c[i].x,&c[i].v);
        //printf("%f %f\n",c[i].x,c[i].v);
    }
    sort(c,c+n,cmp);
    int head=n-1;
    double hv=c[head].v;
    double hx=c[head].x;
    double ans=0;
    for(int i=n-2;i>=0;i--)
    {
        //printf("%d %d %f %f %f %f\n",i,head,hx,hv,c[i].x,c[i].v);
        if(c[i].v>hv)
        {
            ans=max((hx-c[i].x)/(c[i].v-hv),ans);
        }
        else
        {
            hv=c[i].v;
            head=i;
            hx=c[head].x;
        }
    }
    printf("%f",ans);
    return 0;

}
