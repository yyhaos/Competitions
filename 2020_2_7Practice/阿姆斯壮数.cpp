//Problem Web:https://vjudge.net/problem/¼ÆËâ¿Í-T1255

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
ll ans[1000005];
ll f(ll x,ll zn)
{
    if(zn==0)return 1;
    return x*f(x,zn-1);
}
bool check(ll x)
{
    ll tmp=0;
    ll yx=x;
    ll tx=x;
    ll cc=0;
    while(tx)
    {
        cc++;
        tx/=10;
    }
//    cout<<cc<<" "<<x<<endl;
    while(x)
    {
        tmp+=f(x%10,cc);
        x/=10;
//        cout<<(x%10)*(x%10)*(x%10)*(x%10)<<endl;

    }
//    cout<<tmp<<endl;
    if(tmp==yx)
    {
        return true;
    }return false;
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
    cin>>n>>m;
    int cnt=0;
    for(int i=n;i<=m;i++)
    {
//        cout<<i<<endl;
        if(check(i))
        {
            ans[cnt++]=i;
        }
    }
    if(cnt==0)
    {
        cout<<"none";
    }
    else
    {
        for(int i=0;i<cnt;i++)
        {
            if(i)
            {
                printf(" ");
            }

                printf("%lld",ans[i]);

        }
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}

