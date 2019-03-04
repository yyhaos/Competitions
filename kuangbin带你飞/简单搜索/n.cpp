#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;

char maze[205][205];
int Kx[205*205];
int Ky[205*205];
int cnt;
int n,m,x,y,th;
int dp1[205][205],dp2[205][205];
struct pos
{
    int x,y,th;
};
int yx,yy,mx,my;
void dfs1()
{
    queue <pos> a;
    pos tem;
    tem.x=yx;
    tem.y=yy;
    tem.th=0;
    a.push(tem);
    while(!a.empty())
    {
        tem=a.front();
        a.pop();
        x=tem.x;
        y=tem.y;

        th=tem.th;
        if(dp1[x][y]!=-1)
            continue;
        if(maze[x][y]=='#')
            continue;
        dp1[x][y]=th;
     //   printf("%d %d\n",x,y);
        th++;
        for(int k=-1;k<=1;k+=2)
        {
            int ii=x+k;
            int jj=y+k;
            if(ii>=0 && ii<n)
            {
               // printf("in : %d %d\n",ii,y);
                tem.x=ii;
                tem.y=y;
                tem.th=th;
                a.push(tem);
            }
            if(jj>=0 && jj<m)
            {
               // printf("in : %d %d\n",x,jj);
                tem.x=x;
                tem.y=jj;
                tem.th=th;
                a.push(tem);
            }
        }
    }
}
void dfs2()
{
    queue <pos> a;
    pos tem;
    tem.x=mx;
    tem.y=my;
    tem.th=0;
    a.push(tem);
    while(!a.empty())
    {
        tem=a.front();
        a.pop();
        x=tem.x;
        y=tem.y;

        th=tem.th;
        if(dp2[x][y]!=-1)
            continue;
        if(maze[x][y]=='#')
            continue;
        dp2[x][y]=th;
     //   printf("%d %d\n",x,y);
        th++;
        for(int k=-1;k<=1;k+=2)
        {
            int ii=x+k;
            int jj=y+k;
            if(ii>=0 && ii<n)
            {
               // printf("in : %d %d\n",ii,y);
                tem.x=ii;
                tem.y=y;
                tem.th=th;
                a.push(tem);
            }
            if(jj>=0 && jj<m)
            {
               // printf("in : %d %d\n",x,jj);
                tem.x=x;
                tem.y=jj;
                tem.th=th;
                a.push(tem);
            }
        }
    }
}
int main ()
{
    while(~scanf("%d%d",&n,&m))
    {
        cnt=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",maze[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp1[i][j]=-1;
                dp2[i][j]=-1;
                if(maze[i][j]=='@')
                {
                    Kx[cnt]=i;
                    Ky[cnt++]=j;
                }
                if(maze[i][j]=='Y')
                {
                    yx=i;yy=j;
                }
                if(maze[i][j]=='M')
                {
                    mx=i;my=j;
                }
            }
        }
        dfs1();
        /*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                printf("%d",dp1[i][j]);
            }
            printf("\n");
        }*/
        dfs2();
        int ans=99999999;
        //printf("anx=%d\n",ans);
        for(int i=0;i<cnt;i++)
        {
            if(dp1[Kx[i]][Ky[i]]==-1||dp2[Kx[i]][Ky[i]]==-1)
                continue;
            ans=min(ans,dp1[Kx[i]][Ky[i]]+dp2[Kx[i]][Ky[i]]);
        }
        printf("%d\n",ans*11);
    }
    return 0;
}
