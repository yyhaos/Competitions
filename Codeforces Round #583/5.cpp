//Problem Web:https://codeforces.com/contests/1214
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


ll link[2000005];
struct ed
{
    ll u,v,w;
    friend bool operator <(ed a, ed b)    {
        return a.w>b.w;
    }
}edg[200005];

ll used[200005];

void build(ll tar,ll u,ll v)
{

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
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&edg[i].w);
        edg[i].v=2*i;
        edg[i].u=2*i|1;
    }

    sort(edg+1,edg+1+n);
    for(int i=1;i<=n;i++)
    {

        cout<<edg[i].v<<" "<<edg[i].u<<" "<<edg[i].w<<endl;
    }

    mem(used,0);




#ifdef use_t
}
#endif // use_t
    return 0;
}



