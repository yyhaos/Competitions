#include<iostream>
#include<string.h>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define rep(a,b,c) for(int a=b;a<=c;a++)
const int INF=999999999;
int dis[1005][1005];
int d1[1005];
int d2[1005];
int used[1005];
int used2[1005];
int main ()
{
    rep(i,1,1000)
        rep(j,1,1000)
            dis[i][j]=INF;
    rep(i,1,1000)
        dis[i][i]=0;
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    int s,e,t;
    rep(i,1,m)
    {
        scanf("%d%d%d",&s,&e,&t);
        dis[s][e]=min(dis[s][e],t);
    }
    rep(i,1,1000)
    {
        d1[i]=dis[i][x];
        d2[i]=dis[x][i];
        used[i]=0;
        used2[i]=0;
    }
    d1[x]=0;
    used[x]=1;
    used2[x]=1;
    d2[x]=0;
    rep(kk,1,n)
    {
        int mi=1,mi_dis=INF;
        rep(i,1,n)
        {
            if(used[i]==0 && mi_dis>d1[i])
            {
                mi=i,mi_dis=d1[i];
            }
        }
        used[mi]=1;
        rep(j,1,n)
        {
            if(used[j]==0)
                d1[j]=min(d1[j],dis[j][mi]+mi_dis);
        }

        mi=1,mi_dis=INF;
        rep(i,1,n)
        {
            if(used2[i]==0 && mi_dis>d2[i])
            {
                mi=i,mi_dis=d2[i];
            }
        }
        used2[mi]=1;
        rep(j,1,n)
        {
            if(used2[j]==0)
                d2[j]=min(d2[j],dis[mi][j]+mi_dis);
        }
    }
    int ans=0;
    rep(i,1,n)
    {
        //if(d1[i]+)
        ans=max(ans,d1[i]+d2[i]);
        //printf("%d %d\n",d1[i],d2[i]);
    }

    cout<<ans;
    return 0;
}
