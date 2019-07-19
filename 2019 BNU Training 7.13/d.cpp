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
//ll a[15];
string a[40005];
ll b[40005];
ll s[4000];
ll ts[40005];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("balls.in","r",stdin);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
ll r,c;

    cin>>r>>c;
    for(int i=0;i<c;i++)
    {
        scanf("%lld",b+i);
    }

    for(int i=0;i<r;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<c;i++)
    {
        scanf("%lld",s+i);
    }

    mem(ts,0);

    for(int i=r-1;i>=0;i--)
    {
        for(int j=0;j<c;j++)
        {
            ts[j]=s[j];
            if(j>0)
            {
                if(a[i][j]!='.')
                {
                    ts[j]=max(ts[j],s[j-1]);
                }
            }
            if(j<c-1)
            {
                if(a[i][j]!='.')
                {
                    ts[j]=max(ts[j],s[j+1]);
                }
            }
        }
        for(int j=0;j<c;j++)
        {
            s[j]=ts[j];
            ts[j]=0;
            //cout<<s[j]<<" ";
        }

        //cout<<endl;

    }ll ans=0;
    for(int i=0;i<c;i++)
    {
        ans+=s[i]*b[i];
    }
    cout<<ans<<"\n";


#ifdef use_t
}
#endif // use_t
    return 0;
}
