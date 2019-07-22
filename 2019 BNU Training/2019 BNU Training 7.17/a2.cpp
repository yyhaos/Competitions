//Problem Web:https://codeforces.com/contests/248218
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
ll tick=5e7;
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
ll x,y;
ll k;
ll a[45];
ll m2[45];
ll ans;
ll dfs(ll t1,ll t0,ll now)
{
    if(tick==0)
        return 0;

    //ll ans=0;
  //  cout<<t1<<" "<<t0<<" "<<now<<endl;
    if(x-t1)
    {
        dfs(t1+1,t0,((now<<1)+1));
    }
    if(y-t0)
    {
        dfs(t1,t0+1,(now<<1));
    }
//    if(ans)
//    {
//        cout<<ans<<endl;
//        return ans;
//
//    }
    if(x==t1 && y==t0)
    {
        tick--;
        if(now%m>=k)
        {
            ans++;
            return 1;
        }

        return 0;
    }
    return 0;

}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("zeros.in","r",stdin);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    //cout<<ksm(2,42);

    cin>>x>>y>>m>>k;
//    cout<<x<<y<<m<<k<<endl;
    ll sum=x+y;
    mem(a,0);
    for(int i=0;i<x;i++)
    {
        a[sum-i-1]=1;
    }

    ll fa=0;
//    cout<<a[sum-1]<<endl;
//for(int i=0;i<sum;i++)
//{
//    cout<<a[i]<<" ";
//}
//cout<<endl;
    if(sum==1)
    {
        if(1%m >= k)
            cout<<"1\n";
        else
            cout<<"0\n";
        continue;
    }

//    for(int i=1;i<=sum;i++)
//    {
//        m2[i]=ksm(2,i-1,m);
//    }
    //cout<<dfs(1,0,1%m)<<"\n";

    ans=0;
    dfs(1,0,1);
    cout<<ans<<"\n";





#ifdef use_t
}
#endif // use_t
    return 0;
}

