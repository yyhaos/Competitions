
#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cmath>

#include<cstring>

#include<queue>

using namespace std;
char maze[1005][1005];
int vis[1001005];
int dp[1005][1005];
int cnt;
int n,m,Fi[1000005],Fj[1000005];
int ch(int i,int j)
{
    return i*1000+j;
}
struct fire
{
    int i,j,th;
};
void dfs(int si,int sj)
{
    //int aa=0;
    memset(vis,0,sizeof(vis));
    if(maze[si][sj]=='.')
    {
        dp[si][sj]=-1;
        return ;
    }
    queue <fire> a;
    fire tem;
    for(int i=0;i<cnt;i++)
    {
        tem.i=Fi[i];
        tem.j=Fj[i];
        tem.th=1;
        a.push(tem);
    }
    while(!a.empty())
    {
        tem=a.front();
        a.pop();
        int i=tem.i;
        int j=tem.j;
        if(maze[i][j]=='#')
            continue;
        if(vis[ch(i,j)]==1)
            continue;
        vis[ch(i,j)]=1;
        dp[i][j]=tem.th;
        //aa=max(aa,tem.th);
        int th=1+tem.th;
        for(int k=-1;k<=2;k+=2)
        {
            if(i+k<n && i+k>=0)
            {
                tem.i=i+k;
                tem.j=j;
                tem.th=th;
                a.push(tem);
              //  cnt=th;
            }
            if(j+k<m && j+k>=0)
            {
                tem.i=i;
                tem.j=j+k;
                tem.th=th;
                a.push(tem);
             //   cnt=th;
            }
        }
    }
    //dp[si][sj]=aa;
}

void dfs2(int si,int sj)
{

    int aa=0;
    memset(vis,0,sizeof(vis));
    queue <fire> a;
    fire tem;
    tem.i=si;
    tem.j=sj;
    tem.th=1;
    a.push(tem);
    int flag=0;
    while(!a.empty())
    {
        if(flag)
        {
            a.pop();
            continue;
        }
        tem=a.front();
        a.pop();
        int i=tem.i;
        int j=tem.j;
        //printf("%d - %d %d\n",i,j,tem.th);
        if(maze[i][j]=='#')
            continue;
        if(vis[ch(i,j)]==1)
            continue;
        vis[ch(i,j)]=1;
        if(dp[i][j]<=tem.th)
            continue;
       // printf("%d - %d\n",i,j);
        aa=max(aa,tem.th);
        int th=1+tem.th;
        for(int k=-1;k<=2;k+=2)
        {
            if(i+k<n && i+k>=0)
            {
                tem.i=i+k;
                tem.j=j;
                tem.th=th;
                a.push(tem);
              //  cnt=th;
            }
            else
                flag=th;
            if(j+k<m && j+k>=0)
            {
                tem.i=i;
                tem.j=j+k;
                tem.th=th;
                a.push(tem);
             //   cnt=th;
            }
            else
                flag=th;
        }
    }
    if(flag)
        printf("%d\n",flag-1);
    else
        printf("IMPOSSIBLE\n");
    //dp[si][sj]=aa;
}



int main ()
{
    int t;
    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {
        int ans;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                dp[i][j]=9999999;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",maze[i]);
        }
        int sti,stj,fti=-1,ftj;
        cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(maze[i][j]=='J')
                {
                    sti=i;
                    stj=j;
                }
                if(maze[i][j]=='F')
                {
                    Fi[cnt]=i;
                    Fj[cnt++]=j;
                }

            }
        }
        if(cnt!=0)
            dfs(fti,ftj);
        //printf("%d\n",dp[0][0]);
        dfs2(sti,stj);
    }
    return 0;
}
