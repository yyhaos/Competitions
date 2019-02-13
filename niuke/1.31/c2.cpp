#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int maze[1005][1005];
#define zh 1
#define ko 0
int sx,sy,ex,ey;

void show()
{
    printf("%d %d\n%d %d\n",sx,sy,ex,ey);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(maze[i][j]==1)
            {
                printf("x");
            }
            else
                printf(".");
        }
        printf("\n");
    }
}
struct poi
{
    int x,y;
};
poi x1[1000];
poi x2[1000];
poi x3[1000];
poi x4[1000];
int main ()
{
    scanf("%d%d%d",&n,&m,&k);
    memset(maze,0,sizeof(maze));
    for(int i=1;i<=)

    sx=sy=1;

    return 0;
}
