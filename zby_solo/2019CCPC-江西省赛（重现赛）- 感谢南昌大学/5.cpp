
//Problem Web:http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1005&cid=868
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
ll a[1000005];
ll ta[1000005];
struct sta
{
    ll th,v,ta;
    sta (ll _th=0,ll _v=0, ll _ta=0)
    {
        th=_th;v=_v;ta=_ta;
    }
    friend bool operator < (sta a , sta b)
    {
        return a.v>b.v;
    }
};
vector<ll> ti[1000005];
ll si[1000005];
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
    mem(si,0);
    ll tmp=0;
    ll ans=0;
    ll tp,tt;
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&tt,&tp);
        si[tt]++;
        ti[tt].push_back(tp);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",a+i);
    }
    priority_queue<sta> pq;
    pq.clear();
    for(int time=0;time<=2*1000000;time++)
    {
        if(time<=1000000 && si[time]>0)
        {
            for(int i=0;i<si[time];i++)
            {
                ll now=ti[time][i];
                ta[now]++;
                pq.push(sta(ti[time][i],ta[now],ta[now]-a[i]));
                if()
            }
        }
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}
