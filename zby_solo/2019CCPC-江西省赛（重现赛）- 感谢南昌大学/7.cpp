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
ll a[10005];
ll tb[10005];
ll b[10005];
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

    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%lld",b+i);
        }
        sort(a,a+n);
        sort(b,b+m);
        for(int i=0;i<=1000;i++)
        {
            for(int k=0;k<m;k++)
            {
                tb[k]=b[k]+i;
            }
            ll fa=1;
            for(int s=0;s<n;s++)
            {
                ll pos=lower_bound(tb,tb+m,a[s])-tb;
                if(pos<m && tb[pos]==a[s])
                {
                    fa=0;
                    break;
                }
            }
            if(fa)
            {
                cout<<i<<endl;
                break;
            }
            else
                continue;
        }
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}
