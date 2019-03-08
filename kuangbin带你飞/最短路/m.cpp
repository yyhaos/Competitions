//Problem Web:  https://vjudge.net/contest/239087#problem/M
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<string>
#include<map>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
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
ll n,m;
ll x[105][105];
ll level[105];
ll dis[105];
struct node
{
    ll th,dis;
    node(ll t,ll d)
    {
        th=t;
        dis=d;
    }
    friend bool operator <(node a,node b)
    {
        return a.dis>b.dis;
    }
};
void Di(ll mi,ll ma)
{
   // cout<<"mi"<<mi<<" "<<ma<<endl;
    priority_queue<node>pq;
    while(!pq.empty())
    {
        pq.pop();
    }
    rep(i,1,m)
    {
        dis[i]=x[0][i];
        if(level[i]<=ma && level[i]>=mi)

        pq.push(node(i,dis[i]));
    }
    //pq.push(node(0,0));
    while(!pq.empty())
    {
        node top=pq.top();
        pq.pop();
     //   cout<<top.th<<" "<<top.dis<<endl;
        ll now=top.th;
        ll nd=top.dis;

        dis[now]=min(dis[now],nd);

        rep(i,0,m)
        {
            if(level[i]<=ma && level[i]>=mi)
            {
                //cout<<"ru"<<now<<" -> "<<i<<"  |"<<dis[i]<<" "<<dis[now]<<" "<<x[now][i]<<endl;
                if(dis[i]>dis[now]+x[now][i])
                {
              //      cout<<"ru"<<endl;
                    pq.push(node(i,dis[now]+x[now][i]));
                }
            }
        }
    }
}
int main ()
{
#ifdef yyhao
freopen("in.txt","r",stdin);
#endif // yyhao
    cin>>n>>m;
    ll tmp;
    ll u,cost;
    mem(x,1);
    rep(i,1,m)
    {
        //cout<<i<<endl;
        cin>>x[0][i];
        cin>>level[i];
        cin>>tmp;
        while(tmp--)
        {
            cin>>u>>cost;
            x[u][i]=cost;
        }
    }
    ll ans=9999999999999999LL;
    rep(i,1,m)
    {
        Di(level[i],level[i]+n);
        ans=min(ans,dis[1]);
    }
    cout<<ans;
    return 0;
}
