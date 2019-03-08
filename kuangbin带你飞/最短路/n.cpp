//Problem Web:  https://vjudge.net/contest/239087#problem/n
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
    mem(x,1);
ll a,b;
    cin>>n>>a>>b;
    ll tmp,v;
    rep(i,1,n)
    {
        cin>>tmp;
        //while(tmp--)
        rep(j,1,tmp)
        {
            cin>>v;
            if(j==1)
            {
                x[i][v]=0;
            }
            else x[i][v]=1;
        }
    }
    rep(k,1,n)
    {
        rep(i,1,n)
        {
            rep(j,1,n)
            {
                if(x[i][j]>x[i][k]+x[k][j])
                {
                    x[i][j]=x[i][k]+x[k][j];
                }
            }
        }
    }
    if(x[a][b]>10000)
    cout<<-1;
    else
        cout<<x[a][b];
    return 0;
}
