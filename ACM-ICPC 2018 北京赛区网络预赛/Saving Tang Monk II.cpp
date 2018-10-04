#include<bits/stdc++.h>
using namespace std;
const int INF = -1;
char maze[105][105];
typedef struct state
{
    int x,y,time,ox;
    /*friend bool operator < (const state &p,const state &q)
    {
        return p.time > q.time;
    }*/
    bool operator < (const state &a) const
    {
        return time > a.time;
    }
}state;
struct cmp
{
    bool operator () (state a,state b)
    {
        return a.time < b.time;
    }
};

int n,m;
int vis[105][105][10];
bool ok_x(int x)
{
    if(x>=0 && x<n)
        return true;
    return false;
}
bool ok_y(int x)
{
    if(x>=0 && x<m)
        return true;
    return false;
}
int dp[105][105][105];
int main ()
{

    int tx,ty;
    int sx,sy;
    while(~scanf("%d %d",&n,&m))
    {
        priority_queue<state  > q;
        //memset(vis,0,sizeof(vis));
        if(n==0)
            break;
        memset(dp,0,sizeof(dp));
        memset(maze,0,sizeof(maze));
        while(!q.empty())
            q.pop();
       getchar();
        for(int i=0;i<n;i++)
        {
            scanf("%s",maze[i]);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(maze[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                }
                else if(maze[i][j]=='T')
                {
                    tx=i;
                    ty=j;
                }
            }
        //printf("%d %d\n",tx,ty);
        state tmp;
        tmp.x=sx;
        tmp.y=sy;
        tmp.time=0;
        tmp.ox=0;
        q.push({tmp.x,tmp.y,tmp.time,tmp.ox});
        //dp[sx][sy][0]=0;
        int ans=INF;
        while(!q.empty())
        {
            tmp=q.top();
            int x=tmp.x;
            int y=tmp.y;
            int time=tmp.time;
            int ox=tmp.ox;
            //printf("%d %d %d %d %d\n",x,y,time,ox,dp[x][y][ox]);
            q.pop();

            if (dp[x][y][ox]!=0 )
            {
                continue;
            }
            dp[x][y][ox]=1;
            if(x==tx && y==ty)
            {
                ans=time;
                break;
            }
            //printf("%d %d %d %d\n",x,y,time,ox);
            for(int i=-1;i<=1;i+=2)
            {
                if(ok_x(x+i) && ok_y(y))
                {
                    tmp.x=x+i;
                    tmp.y=y;
                    if(maze[tmp.x][tmp.y]=='.'|| maze[tmp.x][tmp.y]=='S')
                    {
                        tmp.time=time+1;
                        tmp.ox=ox;
                        q.push({tmp.x,tmp.y,tmp.time,tmp.ox});
                    }
                    //if(x==1  && y+i==2 )
                       // printf("1 2 %d %d ==\n",time, ox);
                    else if(maze[tmp.x][tmp.y]=='#' && ox>0)
                    {
                        tmp.time=time+2;
                        tmp.ox=ox-1;
                        q.push({tmp.x,tmp.y,tmp.time,tmp.ox});
                    }
                    else if(maze[tmp.x][tmp.y]=='P')   //yao pian
                    {
                        tmp.time=time;
                        tmp.ox=ox;
                        q.push({tmp.x,tmp.y,tmp.time,tmp.ox});
                    }
                    else if(maze[tmp.x][tmp.y]=='B')   // yang qi
                    {
                        tmp.time=time+1;
                        if(ox<=4)
                        {
                            tmp.ox=ox+1;
                        }
                        q.push({tmp.x,tmp.y,tmp.time,tmp.ox});

                    }
                    else if(maze[tmp.x][tmp.y]=='T')
                    {
                        ans=time+1;
                        break;
                    }
                }
                if(ok_x(x) && ok_y(y+i))
                {
                    tmp.x=x;
                    tmp.y=y+i;
                    if(maze[tmp.x][tmp.y]=='.'|| maze[tmp.x][tmp.y]=='S')
                    {
                        tmp.time=time+1;
                        tmp.ox=ox;
                        q.push({tmp.x,tmp.y,tmp.time,tmp.ox});
                    }
                    //if(x==1  && y+i==2 )
                       // printf("1 2 %d %d ==\n",time, ox);
                    else if(maze[tmp.x][tmp.y]=='#' && ox>0)
                    {
                        tmp.time=time+2;
                        tmp.ox=ox-1;
                        q.push({tmp.x,tmp.y,tmp.time,tmp.ox});
                    }
                    else if(maze[tmp.x][tmp.y]=='P')   //yao pian
                    {
                        tmp.time=time;
                        tmp.ox=ox;
                        q.push({tmp.x,tmp.y,tmp.time,tmp.ox});
                    }
                    else if(maze[tmp.x][tmp.y]=='B')   // yang qi
                    {
                        tmp.time=time+1;
                        if(ox<=4)
                        {
                            tmp.ox=ox+1;
                        }
                        q.push({tmp.x,tmp.y,tmp.time,tmp.ox});

                    }
                    else if(maze[tmp.x][tmp.y]=='T')
                    {
                        ans=time+1;
                        break;
                    }
                }
            }
            if(ans!=INF)
                break;
        }

        //for(int i=0;i<=5;i++)
        //    ans=min(ans,dp[tx][ty][i]);
        if(ans==INF)
            printf("-1\n");
        else
            printf("%d\n",ans);

    }
    return 0;
}

