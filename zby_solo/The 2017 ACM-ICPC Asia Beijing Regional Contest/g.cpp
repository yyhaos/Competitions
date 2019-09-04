//Problem Web:https://vjudge.net/contest/318541
#include<bits/stdc++.h>
#include<ext/rope> //using __gnu_cxx
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
//#define use_t 1
//const double PI=acos(-1.0);
//const double eps=1e-8;
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

ll t,n,m;
ll M[25][25][9];
const double eps = 1e-14; const double PI = acos(-1.0);
int sgn(double x) {
if(fabs(x) < eps)return 0; if(x < 0)return -1; else return 1;
}

struct Point
{  double x,y;
 Point(){}
 Point(double _x,double _y)
 {
  x = _x;y = _y;
 }
 Point operator -(const Point &b)const
 {
  return Point(x - b.x,y - b.y);
 }  //叉积
 double operator ^(const Point &b)const
 {
  return x*b.y - y*b.x;
 }  //点积
 double operator *(const Point &b)const
 {
  return x*b.x + y*b.y;
 }
//绕原点旋转角度B（弧度值），后x,y的变化
 void transXY(double B)
 {
  double tx = x,ty = y;   x = tx*cos(B) - ty*sin(B);   y = tx*sin(B) + ty*cos(B);
 }
 bool operator == (const Point &b)const
 {
     if(sgn(b.x-x)==0 && sgn(b.y-y)==0)
        return true;
     return false;
 }
 void show()
 {
     cout<<x<<" "<<y<<endl;
 }
};
struct Line
{
 Point s,e;
 Line(){}
 Line(Point _s,Point _e)
 {
  s = _s;e = _e;
 }
 //两直线相交求交点
 //第一个值为0表示直线重合，为1表示平行，为0表示相交,为2是相交
 //只有第一个值为2时，交点才有意义
    pair<int,Point> operator &(const Line &b)const
    {
        Point res = s;
        if(sgn((s-e)^(b.s-b.e)) == 0)
        {
            if(sgn((s-b.e)^(b.s-b.e)) == 0)
                return make_pair(0,res);//重合
            else return make_pair(1,res);//平行         }

        }
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
            res.x += (e.x-s.x)*t;
               res.y += (e.y-s.y)*t;
                   return make_pair(2,res);
    }
};
double dist(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}
bool inter(Line l1,Line l2)
{
 return
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&     max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&     max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&     max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&     sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0
    &&     sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}
bool OnSeg(Point P,Line L)
{
//        if(P == L.e || P==L.s)
//            return false;
     return     sgn((L.s-P)^(L.e-P)) == 0 &&     sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&     sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}
bool OnSeg2(Point P,Line L)
{
        if(P == L.e || P==L.s)
            return false;
     return     sgn((L.s-P)^(L.e-P)) == 0 &&     sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&     sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}


int inConvexPoly(Point a,Point p[],int n)
{
    ll sa=0;
     for(int i = 0;i < n;i++)
     {
         if(p[i]==p[(i+1)%n])
         {
                sa++;
         }
        if(sgn((p[i]-a)^(p[(i+1)%n]-a)) < 0)return -1;
        else if(OnSeg(a,Line(p[i],p[(i+1)%n])))return 0;
     }
     if(sa>=1)
        return -1;
     return 1;
}

Point bmd[25];
Line Lb[25];
ll fx[28]={1,1,1,0,-1,-1,-1,0};
ll fy[28]={1,0,-1,-1,-1,0,1,1};
string str[225];

bool ok(ll x,ll y)
{
    if(x>=0 && y>=0 && x<n && y<n && str[x][y] !='#')
    {
        return true;
    }
    return false;
}
//bool cmp2(const Point a,const Point b)
//{
//    double tt=atan2(a.y,a.x)-atan2(b.y,b.x);
////    Point c(0,0);
//    if( fabs(tt)<eps )
//    {
//        if(a.x>0 && b.x>0)
//        return a.x<b.x;
//        else
//        {
//            return a.x>b.x;
//        }
//    }
//    else
//        return tt<0;
//}
double cross(Point a, Point b ,Point c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
bool cmp2(const Point a,const Point b)
{
    Point c(0,0);
    double ttt=cross(c,a,b);
    if(ttt>0)
        return true;
    return false;
}
void getm()
{
    ll nx,ny;
    mem(M,0);
    for(ll ti=0;ti<n;ti++)
    {
        for(ll tj=0;tj<n;tj++)
        {
//            cout<<i<<" "<<j<<"-----------------------------\n";
            if(ok(ti,tj)==false)
                continue;
            Point now(tj,n-1.0-ti);
//            now.show();
            for(ll ff=0;ff<8;ff++)
            {
                nx=ti+fx[ff],ny=tj+fy[ff];
                Point tmp(ny,n-1.0-nx);
                //for(int xxx=)
                Point mid;
                mid.x=(tmp.x+now.x)/2.0;
                mid.y=(tmp.y+now.y)/2.0;
                ll flag=1;

                if(ok(nx,ny))
                {
                    double zz;
                    for(double tx=0.000;tx<=1;tx+=0.001)
                    {

                        mid.x=tx*tmp.x+(1.0-tx)*now.x;
                        mid.y=tx*tmp.y+(1.0-tx)*now.y;
                        if( inConvexPoly(mid,bmd,3)==1  )
                        {
                            flag=0;
                            break;
                        }

                    }
//                    flag=1;
//                    for(i=1;i<=99;i++)
//                    {
//
//                    }
//                    cout<<" + "<<nx<<" "<<ny<<" ff:"<<ff<<endl;

//                    cout<<" + "<<nx<<" "<<ny<<" ff:"<<ff<<endl;


                }
                else
                {
                    flag=0;
                }

                if(flag==1)
                {
                    M[ti][tj][ff]=1;
                }
            }
        }
    }
}

ll dis[225][225];

void dfs(ll x,ll y)
{
    queue<ll> mq;
    while(!mq.empty())
        mq.pop();
    mq.push(n*100-100);
    ll tx,ty,nx,ny;
    dis[n-1][0]=1;
    while(!mq.empty())
    {
        ll top=mq.front();
        mq.pop();
        tx=top/100;
        ty=top%100;
        for(ll i=0;i<8;i++)
        {
            if(M[tx][ty][i])
            {
                nx=tx+fx[i];
                ny=ty+fy[i];
                if(dis[nx][ny]==0)
                {
                    dis[nx][ny]=dis[tx][ty]+1;
                    mq.push(nx*100+ny);
                }
            }
        }
    }
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    while(cin>>n)
    {
        for(int i=0;i<3;i++)
        {
            scanf("%lf%lf",&bmd[i].x,&bmd[i].y);
        }
        sort(bmd,bmd+3,cmp2);

        for(int i=0;i<3;i++)
            Lb[i]=Line( bmd[i], bmd[(i+1)%3]);
//        for(int i=0;i<3;i++)
//        {
//            printf("%f %f\n",bmd[i].x,bmd[i].y);
//        }
//getchar();
        for(int i=0;i<n;i++)
        {
            cin>>str[i];
//            cout<<str[i]<<endl;
        }
        getm();

//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cout<<i<<","<<j<<" :";
//                for(int k=0;k<8;k++)
//                {
//                    if(M[i][j][k])
//                    {
//                        cout<<i+fx[k]<<","<<j+fy[k]<<" ";
//                    }
//                }
//                cout<<endl;
//            }
//        }
        mem(dis,0);
        if(str[n-1][0]=='#')
        {
            cout<<-1<<endl;
            continue;
        }
        dfs(n-1,0);
//        if(dis[0][n-1] !=0)
//        {
            cout<<dis[0][n-1]-1<<endl;
//        }
//        else
//        {
//            cout<<"-1\n";
//        }

//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cout<<dis[i][j]<<" ";
//            }
//            cout<<endl;
//        }
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}


