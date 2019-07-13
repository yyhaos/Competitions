//Problem Web:https://codeforces.com/contests/102152
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
ll z[10105];
ll f[10015];
ll t,n,m;

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

ll k;
ll zn=0,fn=0;
    cin>>n>>k;
    ll tmp;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&tmp);
        if(tmp<0)
        {
            f[fn++]=tmp;
        }
        else
            z[zn++]=tmp;
    }
    sort(f,f+fn);
    sort(z,z+zn);
    for(int i=0;i<min(k,fn);i++)
    {
        f[i]=-f[i];
    }
    ll yu=k-fn;
    if(yu>0)
        yu%=2;

    for(int i=0;i<yu;i++)
    {
        if(fn)
        {
            if(zn)
            {
                if(abs(f[fn-1])>abs(z[0]))
                {
                    z[0]=-z[0];
                 //   cout<<"----"<<endl;
                }
                else
                    f[fn-1]=-f[fn-1];
                   // cout<<"----"<<endl;
            }
            else
                f[fn-1]=-f[fn-1];
        }
        else
            z[0]=-z[0];
    }
    ll sum=0;
    for(int i=0;i<fn;i++)
        sum+=f[i];
    for(int j=0;j<zn;j++)
    {
        sum+=z[j];
    }
    cout<<sum<<"\n";

#ifdef use_t
}
#endif // use_t
    return 0;
}

