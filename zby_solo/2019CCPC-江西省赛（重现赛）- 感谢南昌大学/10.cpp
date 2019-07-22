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
ll lcm(ll x, ll y)
{
    return x*y/__gcd(x,y);
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

    while(cin>>n>>m)
    {
        ll lc=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            lc=lcm(lc,a[i]);
        }
        ll cnt=0;
        for(int k=1;k<=n;k++)
        {
            cnt+=lc/a[k];
        }
        if(m%cnt==0)
        {
            cout<<"Yes\n";
            for(int i=1;i<=n;i++)
            {
                if(i-1)
                    cout<<" ";
                cout<<m/cnt*lc/a[i];
            }
            cout<<endl;
        }
        else
        {
            cout<<"No\n";
        }
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}

