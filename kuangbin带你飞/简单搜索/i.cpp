
#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cmath>

#include<cstring>

#include<queue>

using namespace std;
char maze[15][15];
int F[15*15];
int n,m;
int ch(int i,int j)
{
    return i*m+j;
}
int fi(int i)
{
    int fa=F[i];
    if(fa==i)
        return i;
    else
        return F[i]=fi(fa);
}

void join(int i,int j)
{
    //printf("%d+%d\n",i,j);
    fi(i);
    fi(j);
    if(fi(i)==fi(j))
        return ;
    else
    {
        F[fi(i)]=F[fi(j)];
    }
    fi(i);
    fi(j);
}

int dp[15][15];
int tem[15][15];
int vis[15*15];

struct fire
{
    int i,j,th;
};
void dfs(int si,int sj)
{
    int aa=0;
    memset(vis,0,sizeof(vis));
    if(maze[si][sj]=='.')
    {
        dp[si][sj]=-1;
        return ;
    }
    queue <fire> a;
    fire tem;
    tem.i=si;
    tem.j=sj;
    tem.th=0;
    a.push(tem);
    while(!a.empty())
    {
        tem=a.front();
        a.pop();
        int i=tem.i;
        int j=tem.j;
        if(maze[i][j]=='.')
            continue;
        if(vis[ch(i,j)]==1)
            continue;
        vis[ch(i,j)]=1;
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
    dp[si][sj]=aa;
}


int dfs2(int si1,int sj1,int si2,int sj2)
{
    int aa=0;
    memset(vis,0,sizeof(vis));
    queue <fire> a;
    fire tem;
    tem.i=si1;
    tem.j=sj1;
    tem.th=0;
    a.push(tem);
    tem.i=si2;
    tem.j=sj2;
    tem.th=0;
    a.push(tem);
    while(!a.empty())
    {
        tem=a.front();
        a.pop();
        int i=tem.i;
        int j=tem.j;
        if(maze[i][j]=='.')
            continue;
        if(vis[ch(i,j)]==1)
            continue;
        vis[ch(i,j)]=1;
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
            }
            if(j+k<m && j+k>=0)
            {
                tem.i=i;
                tem.j=j+k;
                tem.th=th;
                a.push(tem);
            }
        }
    }
    return aa;
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
            scanf("%s",maze[i]);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                F[ch(i,j)]=ch(i,j);
            }
        }
        /*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                printf("%d",F[ch(i,j)]);
            printf("\n");
        }*/
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(maze[i][j]=='.')
                    continue;
                for(int k=-1;k<=1;k+=2)
                {

                    if(i+k<n && i+k>=0)
                    {
                        if(maze[i+k][j]=='#')
                            join(ch(i,j),ch(i+k,j));
                    }
                    if(j+k<m && j+k>=0)
                    {
                        if(maze[i][j+k]=='#')
                            join(ch(i,j),ch(i,j+k));
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                fi(ch(i,j));
                //printf("%d",F[ch(i,j)]);
            }
            //printf("\n");
        }
        //int vis[15*15];
        int cnt=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(maze[i][j]=='.')
                    continue;
                if(vis[F[fi(ch(i,j))]]==0)
                {
                    vis[F[fi(ch(i,j))]]=1;
                    cnt++;
                }
            }
        }
       // printf("cnt=%d\n",cnt);
        if(cnt==0)
        {
            ans=0;
        }
        else if(cnt>=3)
        {
            ans=-1;
        }
        else if(cnt==2)
        {

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    dfs(i,j);
                   // printf("%3d",dp[i][j]);
                }
                //printf("\n");
            }
            ans=999998;
            for(int i1=0;i1<n;i1++)
                for(int j1=0;j1<m;j1++)
                    for(int i2=0;i2<n;i2++)
                        for(int j2=0;j2<m;j2++)
                {
                    if(i1==i2 && j1==j2)
                        continue;
                    if(maze[i1][j1]=='.' || maze[i2][j2]=='.')
                        continue;
                    if(F[ch(i1,j1)] != F[ch(i2,j2)] )
                        ans=min(ans,max(dp[i1][j1],dp[i2][j2]));
                }
        }
        else
        {
            ans=999999;
            for(int i1=0;i1<n;i1++)
                for(int j1=0;j1<m;j1++)
                    for(int i2=0;i2<n;i2++)
                        for(int j2=0;j2<m;j2++)
                {

                    if(maze[i1][j1]=='.' || maze[i2][j2]=='.')
                        continue;
                    ans=min(ans,dfs2(i1,j1,i2,j2));
                }
        }
        printf("Case %d: %d\n",ii,ans);

    }
    return 0;
}
