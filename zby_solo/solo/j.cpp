//Problem Web:https://vjudge.net/contest/353524
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

ll tr[20];
ll cou(ll s,ll th)
{
    if(th==0)return 0;
    ll a=0,b=0;
    ll prea=1;
    for(int i=0;i<th;i++)
    {
        prea*=tr[i];
    }
    for(int i=th+1;i<s;i++)
    {

    }
}
ll call(ll x)
{
    if(x==0)return 1;
    int cnt=0;
    while(x)
    {
        tr[cnt++]=x%10;
        x/=10;
    }
    ll tmp=0;
    for(int i=0;i<cnt;i++)
        tmp+=cou(cnt,i);
    return tmp;
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

    while(cin>>m>>n)
    {
        printf("%lld",call(n)-call(m-1));
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}



