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

ll t,n,m;
struct poi
{
    double x,y;
}p[255];
double dis(poi a,poi b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
poi getyuan(poi a,poi b,poi c)
{
    double A,B,D,C;
    A=a.x*(b.y-c.y)-a.y*(b.x-c.x)+b.x*c.y-c.x*b.y;
    B=(a.x*a.x+a.y*a.y)*(c.y-b.y)+(b.x*b.x+b.y*b.y)*(a.y-c.y)+(c.x*c.x+c.y*c.y)*(b.y-a.y);
    C=(a.x*a.x+a.y*a.y)*(b.x-c.x)+(b.x*b.x+b.y*b.y)*(c.x-a.x)+(c.x*c.x+c.y*c.y)*(a.x-b.x);
    D=(a.x*a.x+a.y*a.y)*(c.x*b.y-b.x*c.y)+(b.x*b.x+b.y*b.y)*(a.x*c.y-c.x*a.y)+
        (c.x*c.x+c.y*c.y)*(b.x*a.y-a.x*b.y);
    poi ans,ans2;

        double ab=dis(a,b);
        double ac=dis(a,c);
        double bc=dis(c,b);
        if(ab*ab>ac*ac+bc*bc-0.00001)
        {

        }
        else if(ac*ac>ab*ab+bc*bc-0.00001)
        {
            swap(b,c);
        }
        else
        {
            swap(a,c);
        }
        ans.x=a.x+b.x;
        ans.x/=2;
        ans.y=a.y+b.y;
        ans.y/=2;
        //return ans;
        ans2.x=ans.x;
        ans2.y=ans.y;

    double r=dis(ans,a);



    ans.x=-B/2.0/A;
    ans.y=-C/2.0/A;
    double r2=dis(ans2,a);
//    cout<<ans.x<<" "<<ans.y<<" + "<<ans2.x<<" "<<ans2.y<<endl;
//    cout<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<" "<<c.x<<" "<<c.y<<endl;
//    cout<<"r:"<<r<<" "<<r2<<endl;
    if(r2 >= dis(ans2,c))
    {
        ans=ans2;
//        cout<<" Ö±¾¶"<<endl;
    }
    return ans;
}

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("robots.in","r",stdout);
#else
    freopen("robots.in","r",stdin);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    cin>>n;
//    cout<<n<<":"<<endl;
    double R,r;
    cin>>R>>r;
    ll px=0,py=0;
    p[0].x=p[0].y=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
        p[i].x+=p[i-1].x;
        p[i].y+=p[i-1].y;
       // cout<<p[i].x<<" "<<p[i].y<<endl;
    }

    if(n==1)
    {
//        <<' '<<<<'\n';
        printf("%.9f %.9f\n", -p[1].x/2.0,-p[1].y/2.0);
        continue;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                //cout<<i<<" "<<j<<" "<<k<<endl;
                poi yuanxin=getyuan(p[i],p[j],p[k]);

                ll fa=1;
                for(int s=0;s<=n;s++)
                {
                    if(dis(yuanxin,p[s]) >0.000001 + R-r )
                    {
                        fa=0;
                            break;
                    }
                }
                if(fa)
                {
                    printf("%.9f %.9f\n",-yuanxin.x,-yuanxin.y);
                    goto aa;
                }
            }
        }
    }

aa:;


#ifdef use_t
}
#endif // use_t
    return 0;
}
