#include<iostream>
#include<string.h>
#include <queue>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(a,b,c) for(long long a=b;a<=c;a++)
const long long INF=99999999999;
long long n,m,w;
long long dis[1005];
long long vis[1005];
long long num[1005];
long long t[1005][1005];
long long t2[1005][1005];
struct edge
{
    int s,e,tt;
};
int ec=0;
edge es[50005];
void add_edge(int S,int E,int Tt)
{
    es[ec].s=S;
    es[ec].e=E;
    es[ec++].tt=Tt;
}
bool spfa(long long st)
{
    mem(num,0);
    mem(vis,0);
    rep(i,1,n)
        dis[i]=0;
    //dis[st]=0;
    queue <int> q;
    q.push(st);
    vis[st]=1;
    num[st]++;
    long long flag=0;
    long long th=n;

    rep(k,1,n)
    {
        flag=0;
        rep(i,0,ec-1)
        {
            int sd=es[i].s;
            int ed=es[i].e;
            int tt=es[i].tt;
            if(dis[ed]>dis[sd]+tt)
            {
                flag=1;
                dis[ed]=dis[sd]+tt;
            }
        }
        if(flag==0)
            return false;
    }
    return true;
}

int main ()
{
    freopen("test.txt","r",stdin);
    long long f;
    scanf("%lld",&f);

    while(f--)
    {
        ec=0;
        rep(i,1,505)
            rep(j,1,505)
                t[i][j]=t2[i][j]=INF;
        rep(i,1,505)
            t[i][i]=0;
        long long s,e,tt;
        scanf("%lld%lld%lld",&n,&m,&w);
        rep(i,1,m)
        {
            scanf("%lld%lld%lld",&s,&e,&tt);
            add_edge(s,e,tt);
            add_edge(e,s,tt);
        }
        rep(i,1,w)
        {
            scanf("%lld%lld%lld",&s,&e,&tt);
            add_edge(s,e,-tt);
        }
        //long long ans=0;
        if(spfa(1))
        {
            printf("YES\n");
            //ans=1;
        }
        else
            printf("NO\n");
    }

    return 0;
}
