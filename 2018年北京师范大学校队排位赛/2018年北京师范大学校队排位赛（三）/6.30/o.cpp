//https://codeforces.com/gymRegistration/101653/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define used_t 1
const ll q=1e9+7;
const ll maxn= 100000;
const ll INF=1e16;
const double eps=1e-12;
const double PI=acos(-1);
ll sg(double x)
{
    if(x>eps)
        return 1;
    else if(x<-eps)
        return -1;
    return 0;
}

ll ksm(ll a,ll b,ll qq=q)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%q;
        a=a*a%q;
        b/=2;
    }
    return ans;
}

ll n,m;
struct jw
{
    double w,c;
    jw(double _w=0,double _c=0)
    {
        w=_w;
        c=_c;
    }
    friend bool operator < (jw a,jw b)
    {
        if(sg(a.w-b.w)!=0)
        return sg(a.w-b.w)<0;
        return sg(a.c>b.c);
    }
}g[2500];

ll dp[2005];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
#endif // yyhao


#ifdef used_t
ll t;
cin>>t;
for(ll ii=1;ii<=t;ii++)
{
#endif // used_t

    cin>>n;
    double w,c;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&w,&c);
        g[i]=jw(w,c);
    }

   // sort(g+1,g+n+1);
//    for(int i=1;i<=n;i++)
//    {
//        cout<<g[i].w<<" "<<g[i].c<<endl;
//    }
    mem(dp,0);
    dp[0]=0;
    dp[1]=1;

    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
        for(int j=1;j<i;j++)
        {
            if((g[i].c-g[j].c) < -eps && (g[i].w-g[j].w)>eps)
            {
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        ans=max(ans,dp[i]);
    }

    cout<<ans<<endl;


#ifdef used_t
}
#endif // used_t
}

