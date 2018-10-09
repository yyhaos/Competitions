
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct ride
{
    long long time,cost;

}r[1005];
vector <long long > p[1005];
long long x;
long long n,m,t;
long long ans=100000000000004LL;
ll dp[1005][1005];

struct state
{
    ll i, cost,time;
    bool operator <(state a) const  {  return cost > a.cost; }
    bool operator >(state a) const  {  return cost > a.cost; }
};

priority_queue< state>q;
int main ()
{

    ans=10000000000000LL+4LL;

    memset(p,0,sizeof(p));
    memset(r,0,sizeof(r));
    scanf("%lld%lld%lld%lld",&x,&n,&m,&t);
    for(long long i=1;i<=m;i++)
    {
        long long t1,t2;
        scanf("%lld%lld",&t1,&t2);
        p[t1].push_back(t2);
        p[t2].push_back(t1);
    }
    for(long long i=1;i<=n;i++)
    {
        long long t1,t2;
        scanf("%lld%lld",&t1,&t2);
        r[i].cost=t2;
        r[i].time=t1;
    }
//    dfs(1,r[1].cost,r[1].time);
    state tmp;
    tmp.i=1;
    tmp.cost=r[1].cost;
    tmp.time=r[1].time;
    q.push(tmp);
    memset(dp,-1,sizeof(dp));
    while(!q.empty())
    {

        state to=q.top();
        q.pop();
        ll time=to.time;
        ll cost=to.cost;
        ll i=to.i;
        if(time>x)
            continue;
        if(dp[i][time]>=0)
            continue;
        dp[i][time]=1;
      //  cout<<i<<" "<<time<<" "<<cost<<" "<<t<<endl;

        if(time==x && i==1)
        {
            ans=min(ans,cost);
            break ;
        }

        long long si=p[i].size();
      //  dfs(i,cost+r[i].cost,time+r[i].time);
        tmp.i=i;
        tmp.cost=cost+r[i].cost;
        tmp.time=time+r[i].time;
        q.push(tmp);
        for(long long j=0;j<si;j++)
        {
            long long nxt=p[i][j];
            tmp.i=nxt;
            tmp.cost=r[nxt].cost+cost;
            tmp.time=r[nxt].time+time+t;
            //dfs(nxt,cost+r[nxt].cost,time+t+r[nxt].time);
            q.push(tmp);
        }
    }

    if(ans>=10000000000000LL)
        printf("It is a trap.");
    else
        printf("%lld",ans);

    return 0;
}
