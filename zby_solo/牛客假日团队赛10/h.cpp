//Problem Web:https://ac.nowcoder.com/acm/contest/1072#question
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
vector<ll> M[200005];
ll dis[200005];
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

    cin>>n>>m;ll x,y;
    while(m--)
    {
        scanf("%lld%lld",&x,&y);
        M[x].push_back(y);
        M[y].push_back(x);
    }
    mem(dis,0);
    queue<ll> qq;

    qq.push(1);
    dis[1]=1;
    ll faa=0;
    while(!qq.empty())
    {
        ll top=qq.front();
        qq.pop();
        ll si=M[top].size();
        ll nxt;
        for(int i=0;i<si;i++)
        {
            nxt=M[top][i];
            if(dis[nxt]==0)
            {
                dis[nxt]=dis[top]+1;
                faa=max(faa,dis[nxt]);   qq.push(nxt);
            }
        }
    }
    ll a1=-1,a2=0;
    for(int i=1;i<=n;i++)
    {
        if(faa==dis[i])
        {
            if(a1==-1)
                a1=i;
            a2++;
        }
    }

    cout<<a1<<" "<<faa-1<<" "<<a2<<endl;


#ifdef use_t
}
#endif // use_t
    return 0;
}



