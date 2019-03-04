#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
int maze[7][7];
int dp[7][7][5];
struct state
{
    int i,j,th;
};
void myprint(int x,int y)
{
    if(x!=0||y!=0)
    {
        myprint(dp[x][y][1],dp[x][y][2]);
        printf("(%d, %d)\n",x,y);
    }
    return ;
}
void bfs()
{
    state tem;
    tem.i=tem.j=tem.th=0;
    queue<state> a;
    a.push(tem);
    while(!a.empty())
    {
        tem=a.front();
        a.pop();
        int i=tem.i;
        int j=tem.j;
        //printf("%d-%d\n",i,j);
        if(dp[i][j][0]>0)
            continue;
        dp[i][j][0]=1;
        if(maze[i][j]==1)
            continue;
        if(i==j && i==4)
        {
            /*
            for(int ii=0;ii<5;ii++)
            {
                for(int jj=0;jj<5;jj++)
                    printf("%d ",dp[ii][jj][0]);
                printf("\n");
            }*/
            printf("(%d, %d)\n",0,0);
            myprint(4,4);
            break;
        }
        for(int k=-1;k<=1;k+=2)
        {
            if(i+k>=0 && i+k<5)
            {
                if(maze[i+k][j]==0 && dp[i+k][j][0]==0)
                {
                    tem.i=i+k;
                    tem.j=j;
                    dp[i+k][j][1]=i;
                    dp[i+k][j][2]=j;
                    a.push(tem);

                }
            }
            if(j+k>=0 && j+k<5)
            {
                if(maze[i][j+k]==0 && dp[i][j+k][0]==0)
                {
                    tem.j=j+k;
                    tem.i=i;
                    dp[i][j+k][1]=i;
                    dp[i][j+k][2]=j;
                    a.push(tem);
                }
            }
        }
    }
}
int main ()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            scanf("%d",&maze[i][j]);
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            for(int k=0;k<4;k++)
            dp[i][j][k]=0;
    bfs();
    return 0;
}
