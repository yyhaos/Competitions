//Problem Web:https://codeforces.com/gym/101982/attachments
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
const int MAXN = 1000000;
int prime[MAXN+1];
void getPrime()
{
    mem(prime,0);
    for(int i=2;i<=MAXN;i++)
    {
        if(!prime[i])
        {
            prime[++prime[0]]=i;
        }
        for(int j=1;j<=prime[0] && prime[j]<=MAXN/i;j++)
        {
            prime[prime[j] * i]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
ll ex(ll x)
{
    ll pos=lower_bound(prime+1,prime+1+prime[0],x)-prime;
    if(x!= prime[pos])
        return 0;
    return 1;
}
ll gold(ll x)
{
    for(ll p = 1;prime[p]<=x/2;p++)
    {
//        cout<<"jian:"<<x-prime[p]<<endl;
        if(ex(x-prime[p]))
        {
            return x-2*prime[p];
        }
    }
}
ll cnt[1000005];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
getPrime();
//for(int i=1;i<=3;i++)
//{
//    cout<<i<<":"<<prime[i]<<endl;
//}
mem(cnt,0);
for(int x=0;x<=1000000;x++)
{
    if(x%2==0 && x>=4)
    {
        ll tx=gold(x);
//        ll cnt=0;
        cnt[x]=1+cnt[tx];
//        cout<<cnt[x]<<",";
    }
    else
    {
cnt[x]=0;
//        cout<<"0,";
    }
}
ll x;
cin>>x;
cout<<cnt[x];


#ifdef use_t
}
#endif // use_t
    return 0;
}


