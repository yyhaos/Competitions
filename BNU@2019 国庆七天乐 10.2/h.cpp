//Problem Web:https://vjudge.net/contest/330737#problem/A
#include<bits/stdc++.h>
#include<ext/rope> //using __gnu_cxx
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
ll used[1001000]={};
ll kcnt=0;
ll k[400000]={};

ll cnt(ll x,ll y)
{
//    cout<<x<<" "<<y<<endl;
//    mem(used,0);
    if(x==0 || y==0)
        return 0;
        ll ans=0;
        ll ti,tj;
    for(int i=0;i<kcnt;i++)
    {
        ti=k[i]/1000;
        tj=k[i]%1000;
        ans+=min( x/ti,y/tj );
    }
    return ans;
}

int main ()
{
    mem(used,0);
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
ll a,b,c,d;
    for(int i=1;i<=998;i++)
    {
        for(int j=1;j<= 998;j++)
        {
            //cout<<i<<" "<<j<<endl;
            if(i+j >=1000)
                break;
            ll gg=__gcd(i,j);
            ll ti=i/gg,tj=j/gg;
            if( used[ ti * 1000 + tj ]==0)
            {
                used[ ti * 1000 + tj ]=1;
                k[kcnt++]=ti*1000+tj;
//                cout<<k[kcnt-1]<<',';
            }
            else
            {

            }
        }
    }

//    cout<<endl<<endl<<kcnt<<endl;
    cin>>a>>b>>c>>d;
    cout<<cnt(b,d) - cnt(b,c-1) - cnt(a-1,d)+cnt(a-1,c-1);





#ifdef use_t
}
#endif // use_t
    return 0;
}
