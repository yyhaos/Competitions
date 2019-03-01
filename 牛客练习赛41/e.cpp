//Problem Web:  https://ac.nowcoder.com/acm/contest/373/E
#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
//#define use_t 1
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
typedef struct point {
    double x,y,z;
    point() {

    }
    point(double a, double b,double c) {
        x = a;
        y = b;
        z = c;
    }
    point operator -(const point &b)const {     //返回减去后的新点
        return point(x - b.x, y - b.y,z-b.z);
    }
    point operator +(const point &b)const {     //返回加上后的新点
        return point(x + b.x, y + b.y,z+b.z);
    }
    //数乘计算
    point operator *(const double &k)const {    //返回相乘后的新点
        return point(x * k, y * k,z*k);
    }
    point operator /(const double &k)const {    //返回相除后的新点
        return point(x / k, y / k,z/k);
    }
    double operator *(const point &b)const {    //点乘
        return x*b.x + y*b.y+z*b.z;
    }
}point;
double dist(point p1, point p2) {       //返回平面上两点距离
    return sqrt((p1 - p2)*(p1 - p2));
}
typedef struct sphere {//球
    double r;
    point centre;
}sphere;
void SphereInterVS(sphere a, sphere b,double &v,double &s) {
    double d = dist(a.centre, b.centre);//球心距
    double t = (d*d + a.r*a.r - b.r*b.r) / (2.0 * d);//
    double h = sqrt((a.r*a.r) - (t*t)) * 2;//h1=h2，球冠的高
    double angle_a = 2 * acos((a.r*a.r + d*d - b.r*b.r) / (2.0 * a.r*d));  //余弦公式计算r1对应圆心角，弧度
    double angle_b = 2 * acos((b.r*b.r + d*d - a.r*a.r) / (2.0 * b.r*d));  //余弦公式计算r2对应圆心角，弧度
    double l1 = ((a.r*a.r - b.r*b.r) / d + d) / 2;
    double l2 = d - l1;
    double x1 = a.r - l1, x2 = b.r - l2;//分别为两个球缺的高度
    double v1 = PI*x1*x1*(a.r - x1 / 3);//相交部分r1圆所对应的球缺部分体积
    double v2 = PI*x2*x2*(b.r - x2 / 3);//相交部分r2圆所对应的球缺部分体积
     v = v1 + v2;//相交部分体积
    double s1 = PI*a.r*x1;  //r1对应球冠表面积
    double s2 = PI*a.r*x2;  //r2对应球冠表面积
     s = 4 * PI*(a.r*a.r + b.r*b.r) - s1 - s2;//剩余部分表面积
}
ll t,n,m;
double fa(double x)
{
    return x*x;
}
double dis(double x1,double y1,double z1,double x2,double y2,double z2)
{
    return sqrt(fa(x1-x2)+fa(y1-y2)+fa(z2-z1));
}
double qiu(double r)
{
    return r*r*r*4.0/3.0*PI;
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
int ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
//    cout<<dis(0,0,0,1 ,1,1);

    double x1,y1,z1,r1;
    double x2,y2,z2,r2;
    cin>>x1>>y1>>z1>>r1>>x2>>y2>>z2>>r2;
    sphere a,b;
    if(r1>r2)
        swap(r1,r2);
    a.r=r1;
    b.r=r2;
    a.centre=point(x1,y1,z1);
    b.centre=point(x2,y2,z2);
    double vv,s;
    SphereInterVS(a,b,vv,s);double ans;
    double diss=dis(x1,y1,z1,x2,y2,z2);
    if(diss>r1+r2)
    {
        ans=qiu(r1)+qiu(r2);
    }
    else if(diss<r2-r1)
    {
        ans=qiu(r2);
    }
    else
    {
        ans=qiu(r1)+qiu(r2)-vv;
    }

    printf("%.10f",ans);
#ifdef use_t
}
#endif // use_t
    return 0;
}




