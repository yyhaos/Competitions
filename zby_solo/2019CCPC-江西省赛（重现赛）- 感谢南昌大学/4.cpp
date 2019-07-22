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
ll a[100005];
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
ll c;
    while(cin>>n>>c)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lld",a+i);
        }
        ll ans=0;
        ll tmp;
        ll th=0;
        ll ta[2];
        for(ta[0]=1;ta[0]<=c;ta[0]++)
        {
            for(ta[1]=1;ta[1]<=c;ta[1]++ )
            {
                th=0;
                tmp=0;
                if(ta[1]==ta[0])
                    continue;
                for(int k=0;k<n;k++)
                {
                    if(a[k]==ta[th])
                    {
                        th=1-th;
                        tmp++;
                    }
                }
                ans=max(ans,tmp);
            }
        }
        if(ans<2)
            ans=0;
        cout<<ans<<endl;
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}

