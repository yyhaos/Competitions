//Problem Web:  https://ac.nowcoder.com/acm/contest/331/B
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

ll t,n,m;

set < pair<ll,ll> > s1,s2;
ll nn;


ll cnt[10];
ll dis[10][2]={0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,-1,1};


int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("in.txt","w",stdout);
#endif
#ifdef use_t
int ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
//cout<<300000<<" "<<300000<<endl;
//for(int i=1;i<=300000;i++)
//{
//    cout<<i<<" "<<1<<endl;
//    cout<<i<<" "<<2<<endl;
//}
//return 0;
    ll x,y;
    scanf("%lld%lld",&n,&m);

    while(m)
    {
        m--;
        scanf("%lld %lld",&x,&y);
       // cout<<x<<" "<<y<<endl;
        s1.insert(make_pair(x,y));
        if(s1.size()<5)
        {
            printf("N\n");
        }
        else
        {
            bool flag=false;
            for(int i=0;i<=3;i++)
            {mem(cnt,0);
                for(int k=1;k<=4;k++)
                {
                    int xx=x+k*dis[i][0],yy=y+k*dis[i][1];
            if(xx>=1 && xx<=n)
            {
                if(yy>=1 && yy<=n)
                {
                    if(s1.count(make_pair(xx,yy)))
                            {
                                cnt[i]++;
                            }
                            else
                                break;
                        }
                        else break;
                    }
                    else break;
                }
                for(int k=1;k<=4;k++)
                {
                    int xx=x+k*dis[i+4][0],yy=y+k*dis[i+4][1];
            if(xx>=1 && xx<=n)
            {
                if(yy>=1 && yy<=n)
                {
                    if(s1.count(make_pair(xx,yy)))
                            {
                                cnt[i+4]++;
                            }
                            else
                                break;
                        }
                        else break;
                    }
                    else break;
                }
                cnt[i]=cnt[i]+cnt[i+4];
                if(cnt[i]>=4)
                {
                    flag= true;
                    break;
                }
            }
                if(flag)
                    printf("Y\n");
                else printf("N\n");
        }
   // mem(cnt,0);
        if(m==0)
            break;
        m--;

        scanf("%lld%lld",&x,&y);
      //  cout<<x<<" "<<y<<endl;
        s2.insert(make_pair(x,y));
        if(s2.size()<5)
        {
            printf("N\n");
        }
        else
        {
            bool flag=false;
    for(int i=0;i<=3;i++)
    {
        mem(cnt,0);
        for(int k=1;k<=4;k++)
        {
            int xx=x+k*dis[i][0],yy=y+k*dis[i][1];
            if(xx>=1 && xx<=n)
            {
                if(yy>=1 && yy<=n)
                {
                    if(s2.count(make_pair(xx,yy)))
                    {
                        cnt[i]++;
                    }
                    else
                        break;
                }
                else break;
            }
            else break;
        }
        for(int k=1;k<=4;k++)
        {
            int xx=x+k*dis[i+4][0],yy=y+k*dis[i+4][1];
            if(xx>=1 && xx<=n)
            {
                if(yy>=1 && yy<=n)
                {
                    if(s2.count(make_pair(xx,yy)))
                    {
                        cnt[i+4]++;
                    }
                    else
                        break;
                }
                else break;
            }
            else break;
        }
        cnt[i]=cnt[i]+cnt[i+4];
        if(cnt[i]>=4)
                {
                    flag= true;
                    break;
                }
    }

        if(flag)
            printf("Y\n");
        else printf("N\n");
    }
        }





#ifdef use_t
}
#endif // use_t
    return 0;
}
