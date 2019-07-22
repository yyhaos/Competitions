#include<bits/stdc++.h>
using namespace std;
double a,b,x,y;
const double g=9.8,pi=acos(-1.0),eps=1e-6;
double s,v;
void mov()  //Ð±Å×ÔË¶¯
{
    double t=2.0*(b*v*sin(s)/a+v*cos(s))/g;

    x+=t*v*sin(s);
    y=-b/a*x;

    double tx=t*v*sin(s);
    double ty=tx*b/a;

    double ts=s;

    s=atan(v*sin(s)/(g*t-v*cos(s)))+2.0*atan(b/a);
    v=sqrt(2*g*(ty)+v*v);

   //printf("t=%lf x=%lf y=%lf v=%lf s=%lf\n",t,x,y,v,s);
}
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&x,&y);
   //     printf("%lf %lf %lf %lf\n",a,b,x,y);
        s=atan(b/a)*2.0;

        v=sqrt(2.0*g*(y+(b/a*x)));

        int ans=0;
        y=-b/a*x;

    //    printf("x=%lf y=%lf v=%lf s=%lf\n",x,y,v,s);
  //  printf("t=%lf\n",t);

        while(x<=eps && y>=-eps)
        {
            mov();
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
