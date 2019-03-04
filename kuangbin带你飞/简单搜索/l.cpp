#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int n,m;
int ch(int x,int y)
{
    return x*m+y;
}
int xx[10]={1,1 ,0 ,-1,-1,-1,0 ,1};
int yy[10]={0,-1,-1,-1,0 ,1 ,1 ,1};
char maze[105][105];
int F[105*105];
int fi(int x)
{
    int fa=F[x];
    if(fa==x)
        return x;
    else
        return F[x]=fi(fa);
}
void join(int x,int y)
{
    fi(x);
    fi(y);
    if(fi(x)==fi(y))
        return;
    else
    {
        F[fi(x)]=fi(y);
        fi(x);
        fi(y);
    }
}
int vis[105*105];
int main ()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0)
            return 0;
        for(int i=0;i<n;i++)
            scanf("%s",maze[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                F[ch(i,j)]=ch(i,j);
               // printf("%d %d %d\n",i,j,F[ch(i,j)]);
            }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(maze[i][j]=='*')
                    continue;
                for(int k=0;k<8;k++)
                {
                    int ii=i+xx[k];
                    int jj=j+yy[k];
                    //printf("%d-%d\n",ii,jj);
                    if(ii<0 || ii>=n || jj<0 ||jj>=m)
                        continue;
                    if(maze[ii][jj]=='*')
                        continue;
                    join(ch(i,j),ch(ii,jj));
                }
            }
        }
        int cnt=0;
        for(int i=0;i<10005;i++)
        {
            vis[i]=0;
            fi(i);
        }
        //printf("4\n");
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
              //  printf("F:%d %d %d\n",i,j,F[ch(i,j)]);
                if(maze[i][j]=='*')
                    continue;
                if(vis[F[ch(i,j)]]==0)
                {
                    cnt++;
                    vis[F[ch(i,j)]]=1;
                }
            }
        printf("%d\n",cnt);
    }
    return 0;
}
