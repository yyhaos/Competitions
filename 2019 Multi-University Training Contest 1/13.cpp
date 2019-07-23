
//Problem Web:
#include<bits/stdc++.h>
#include<ext/rope>
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
#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-10;
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
int sgn(double x)
{
    if(fabs(x)<eps)return 0;
    if(x<0)return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point (){}
    Point (double _x,double _y)
    {
        x=_x;y=_y;
    }
    bool operator < (const Point &b)const {
        if(x!=b.x)
            return x<b.x;
        else
            return y<b.y;
    }
    double operator ^(const Point &b)const {
        return x*b.y-y*b.x;
    }

    double operator *(const Point &b)const {
        return x*b.x+y*b.y;
    }
    double operator ==(const Point &b)const {
        return sgn(x-b.x)==0 && sgn(y-b.y)==0 ;
    }
    Point operator - (const Point &b)const {
        return Point (x-b.x,y-b.y);
    }
}a[105],b[105];
ll na=0,nb=0;
struct Line {
    Point s,e;
    Line (){}
    Line (Point _s,Point _e)
    {
        s=_s;e=_e;
    }
    pair<int , Point > operator &(const Line &b)const
    {
        Point res=s;
        if(sgn((s-e)^(b.s-b.e))==0)
        {
            if(sgn((s-b.e)^(b.s-b.e))==0)
            {
                return make_pair(0,res);
            }
            else
                return make_pair(1,res);
        }
        double t=((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x+=(e.x-s.x)*t;
        res.y+=(e.y-s.y)*t;
        return make_pair(2,res);
    }
};
double dist(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}
bool Seg_inter_line(Line l1,Line l2)
{
    return sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e))<=0;
}

map<Point , ll >useda;
map<Point , ll >usedb;
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
    cin>>n;
    useda.clear();
    usedb.clear();
    na=nb=0;

        ll tx,ty,type;
        #ifdef yyhao
    cout<<"n:"<<n<<" ";
    #endif
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld%lld",&tx,&ty,&type );
        if(type==1)
        {
            Point tmp(tx,ty);
            if(useda[tmp]==0)
            {
                a[na++]=tmp;
                useda[tmp]++;
            }
        }
        else
        {
            Point tmp(tx,ty);
            if(usedb[tmp]==0)
            {
                b[nb++]=tmp;
                usedb[tmp]++;
            }
        }
    }
//    cout<<na<<" "<<nb<<endl;
    if( (na<=1 && nb<=1) || (na==0 || nb==0))
    {
        if(na==1 && nb==1)
        {
            if(a[0]==b[0])
            {
                cout<<"Infinite loop!\n";
                continue;
            }

        }
        cout<<"Successful!\n";
        continue;
    }
    if(na>1)
    {
//        cout<<"cha11111"<<endl;
        ll aaa=0;
        for(int i=0;i<na;i++)
        {
            for(int j=i+1;j<na;j++)
            {
                if(i==j)
                    continue;
                ll fa=1,fb=1;
                ll sa=1;
                ll tara=0;

                ll ta=0;
                Point now=a[i]-a[j];
//                cout<<now.x<<" "<<now.y<<endl;
                tara=0;
                for(int k=0;k<na;k++)
                {
                    Point tmp=a[k]-a[j];
                    if(sgn(tmp^now)==0)
                        continue;
                    if(tara!=0)
                    {
                        if(tara!=(sgn(tmp^now)) )
                        {
                            fa=0;
                            break;
                        }
                    }
                    else
                    {
                        tara=sgn(tmp^now);
                    }
                }
//                cout<<"fa:"<<fa<<endl;
                ll tarb=0;
                for(int k=0;k<nb;k++)
                {
                    Point tmp=b[k]-a[j];
//                    cout<<"k:"<<k<<" "<<(tmp.x)<<","<<(tmp.y)<<" "<<(tmp^now)<<endl;
                    if(sgn(tmp^now) == 0)
                    {
//                        cout<<"1:::fb=0"<<endl;
                        fb=0;
                        break;
                    }
                    if(tarb!=0)
                    {
                        if(tarb!=(sgn(tmp^now)) )
                        {
//                            cout<<"2:::fb=0"<<endl;
                            fb=0;
                            break;
                        }
                    }
                    else
                    {
                        tarb=sgn(tmp^now);
                    }
                }
//                cout<<"fb:"<<fb<<endl;
                if(fa&& fb && tara!=tarb && tarb!=0)
                {
                    aaa=1;
                    break;
                }
            }
            if(aaa)
                break;
        }
        if(aaa)
        {
            cout<<"Successful!\n";
            continue;
        }
    }

    if(nb>1)
    {

//        cout<<"cha2222"<<endl;
        ll aaa=0;
        for(int i=0;i<nb;i++)
        {
            for(int j=i+1;j<nb;j++)
            {
                if(i==j)
                    continue;
                ll fa=1,fb=1;
                ll sa=1;
                ll tara=0;

              //  ll ta=0;
                Point now=b[i]-b[j];
//                cout<<now.x<<" "<<now.y<<endl;
                tara=0;
                for(int k=0;k<nb;k++)
                {
                    Point tmp=b[k]-b[j];
                    if(sgn(tmp^now)==0)
                        continue;
                    if(tara!=0)
                    {
                        if(tara!=(sgn(tmp^now)) )
                        {
                            fa=0;
                            break;
                        }
                    }
                    else
                    {
                        tara=sgn(tmp^now);
                    }
                }
//                cout<<"fa:"<<fa<<endl;
                ll tarb=0;
                for(int k=0;k<na;k++)
                {
                    Point tmp=a[k]-b[j];
//                    cout<<"k:"<<k<<endl;
                    if(sgn(tmp^now) == 0)
                    {
//                        cout<<"1:::fb=0"<<endl;
                        fb=0;
                        break;
                    }
                    if(tarb!=0)
                    {
                        if(tarb!=(sgn(tmp^now)) )
                        {
//                            cout<<"2:::fb=0"<<endl;
                            fb=0;
                            break;
                        }
                    }
                    else
                    {
                        tarb=sgn(tmp^now);
                    }
                }
//                cout<<"fb:"<<fb<<endl;
                if(fa&& fb && tara!=tarb && tarb!=0)
                {
                    aaa=1;
                    break;
                }
            }
            if(aaa)
                break;
        }
        if(aaa)
        {
            cout<<"Successful!\n";
            continue;
        }
    }

cout<<"Infinite loop!\n";


#ifdef use_t
}
#endif // use_t
    return 0;
}

