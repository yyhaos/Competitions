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
struct fen
{
    ll a,b;
    double v;
    fen(ll _a=0,ll _b=0)
    {
        a=_a;b=_b;
        v=1.0*a/b;
    }
    friend bool operator < (fen a, fen b)
    {
        return a.v<b.v;
    }
}ff[1000005];
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

    for(int n=1;n<=9;n++)
    {
        ll cnt=0;
        for(ll a=1;a<=n;a++)
        {
            for(ll b=a;b<=n;b++)
            {
                if(__gcd(a,b)==1 )
                    ff[cnt++]=fen(a,b);
            }
        }
        sort(ff,ff+cnt);

        cout<<"n="<<n<<" : ";
        for(int i=0;i<cnt;i++)
        {
            cout<<ff[i].a<<"/"<<ff[i].b<<" ";
        }
        cout<<endl;
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}


