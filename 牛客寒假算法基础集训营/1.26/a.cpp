//Problem Web:  https://ac.nowcoder.com/acm/contest/329/A
#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
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

ll t,n,m;ll p[100004][12];

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
    ll k;
    cin>>n>>k;
    rep(i,1,n)
    {
        rep(j,1,k)
        {
            scanf("%lld",&p[i][j]);
        }
    }
    if(n>=2*k+10)
    {
        cout<<0<<endl;
        continue;
    }
    else
    {
        //cout<<1<<endl;
        ll ans=0;
        ll aa[10000];
        rep(i,1,n)
        {
            ll flag=1;
            rep(j,1,n)
            {
                if(flag==0)
                        break;
                rep(h,1,n)
                {
                    if(flag==0)
                        break;
                    if(i==j|| i==h || j==h)
                        continue;
                    ll sum=0;
                    rep(kk,1,k)
                    {
                        sum+=(p[j][kk]-p[i][kk])*(p[h][kk]-p[i][kk]);
                    }
                    if(sum>=0)
                        flag=0;
                }


            }
            if(flag==1)
            {
                aa[ans++]=i;
                //break;
            }
        }
        cout<<ans<<endl;
        if(ans>0)
        {
            rep(i,0,ans-1)
            {
                rep(j,1,k)
                cout<<p[aa[i]][j]<<" ";
            }
            cout<<endl;
        }
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}
