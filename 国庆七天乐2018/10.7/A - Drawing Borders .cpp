#include<bits/stdc++.h>
using namespace std;
struct point
{
    double x,y;
    int type;
}p[30005];
bool eq(double x, double y)
{
    if(x<y)
    {
        double t=x;
        x=y;
        y=t;
    }
    if(x-y<=0.00001)
        return true;
    else
        return false;
}
bool cmp(point a, point b)
{
    if(a.x!=b.x)
    {
        return a.x<b.x;
    }
    else
    {
        return a.y<b.y;
    }
}
point ans[30005];
int main ()
{
  //  freopen("test.txt","r",stdin);
    int n;
    scanf("%d",&n);
   // printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf %lf %d\n",&p[i].x,&p[i].y,&p[i].type);
    }
    int cnt=0,th=0;
    double cha=0.01;
    sort(p,p+n,cmp);

    double pre_x=-3001,pre_y=-3000.5;
    for(int i=0;i<n;i++)
    {
        double tx=p[i].x;
        double ty=p[i].y;
        int type=p[i].type;
        if(eq(pre_x,tx)==false)
        {
            ans[cnt].x=pre_x-cha;
            ans[cnt++].y=3000.5;
            ans[cnt].x=tx-40*cha;
            ans[cnt++].y=3000.5;
            ans[cnt].x=tx-40*cha;
            ans[cnt++].y=-3000.5;
            ans[cnt].x=tx-cha;
            ans[cnt++].y=-3000.5;
        }
        pre_x=tx;
        switch(type)
        {
            case 1: ans[cnt].x=tx-3*cha;
                    ans[cnt++].y=ty;
                    break;
            case 2: ans[cnt].x=tx-cha;
                    ans[cnt++].y=ty;
                    break;
            case 3: ans[cnt].x=tx+cha;
                    ans[cnt++].y=ty;
                    break;
        }
    }
   // ans[cnt].x=1111111111;
   // ans[cnt++].y=111111111;
    ans[cnt].x=pre_x-cha;
    ans[cnt++].y=3000.5;


  //  ans[cnt].x=3000-cha;
  //  ans[cnt++].y =3000.5;
    ans[cnt].x=3000.6;
    ans[cnt++].y=3000.5;
    ans[cnt].x=3000.6;
    ans[cnt++].y=-3001;
    ans[cnt].x=-3001;
    ans[cnt++].y=-3001;

    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
    {
        //printf("%d: ",i);
        printf("%f %f\n",ans[i].x,ans[i].y);

    }


    cnt=0,th=0;
    cha=0.01;
    //sort(p,p+n,cmp);

    pre_x=-3001,pre_y=-3000.5;
    for(int i=0;i<n;i++)
    {
        double tx=p[i].x;
        double ty=p[i].y;
        int type=p[i].type;
        if(eq(pre_x,tx)==false)
        {
            ans[cnt].x=pre_x+cha;
            ans[cnt++].y=3000.4;
            ans[cnt].x=tx-50*cha;
            ans[cnt++].y=3000.4;
            ans[cnt].x=tx-50*cha;
            ans[cnt++].y=-3000.6;
            ans[cnt].x=tx+cha;
            ans[cnt++].y=-3000.6;
        }
        pre_x=tx;
        switch(type)
        {
            case 1: ans[cnt].x=tx-cha;
                    ans[cnt++].y=ty;
                    break;
            case 2: ans[cnt].x=tx+cha;
                    ans[cnt++].y=ty;
                    break;
            case 3: ans[cnt].x=tx+3*cha;
                    ans[cnt++].y=ty;
                    break;
        }
    }
   // ans[cnt].x=1111111111;
   // ans[cnt++].y=111111111;
    ans[cnt].x=pre_x+cha;
    ans[cnt++].y=3000.4;


  //  ans[cnt].x=3000-cha;
  //  ans[cnt++].y =3000.5;
    ans[cnt].x=3000.4;
    ans[cnt++].y=3000.4;
    ans[cnt].x=3000.4;
    ans[cnt++].y=-3000.8;
    ans[cnt].x=-3001+cha;
    ans[cnt++].y=-3000.8;

    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
    {
        //printf("%d: ",i);
        printf("%f %f\n",ans[i].x,ans[i].y);

    }
    return 0;
}
