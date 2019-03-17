//Problem Web:  http://fastvj.rainng.com/contest/288922#problem/B
//#include<bits/stdc++.h>
//#include<ext/rope>
#include<map>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair

//const double PI=acos(-1.0);
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
ll vis[2005];
ll su[2005];
ll t,n,m;
ll cnt=0;
//#define use_t 1
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
ll x;
    cin>>x;
    if(x<6 || x%2==1)
    {
        cout<<"Error!";
        return 0;
    }
    mem(su,0);
    mem(vis,0);
    rep(i,2,2000)
    {
        if(vis[i]==0)
        {
            su[cnt++]=i;
            rep(j,2,2000)
            {
                if(i*j>2000)
                    break;
                vis[i*j]=1;
            }
        }
    }
    //cout<<cnt;
    rep(i,0,cnt-1)
    {
        ll dui=x-su[i];
        if(dui<su[i])
            break;
        if(vis[dui]==0)
        {
            cout<<x<<"="<<su[i]<<"+"<<dui<<endl;
        }
    }






#ifdef use_t
}
#endif // use_t
    return 0;
}
