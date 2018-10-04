#include<bits/stdc++.h>
using namespace std;
int sg[105][105];
    int vis[10005];
int sgget(int x,int y)
{
    //if(x==y)
    //    return sg[x][y]=0;

    memset(vis,0,sizeof(vis));
    for(int i=x-1;i>0;i--)
            vis[sg[i][y]]=1;
    for(int i=y-1;i>0;i--)
            vis[sg[x][i]]=1;
    for(int i=1;i<x && i<y;i++)
            vis[sg[x-i][y-i]]=1;
    for(int i=0;i<=10000;i++)
    {
        if(vis[i]==0)
            return i;
    }
    return -1;
}
int main ()
{
    memset(sg,0,sizeof(sg));
    for(int i=0;i<=100;i++)
    {
        sg[i][i]=10001;
        sg[i][1]=10001;
        sg[1][i]=10001;
    }
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
    {
        if(i!=j)
            sg[i][j]=sgget(i,j);
    }

    int ans=0,n;

    scanf("%d",&n);
    while(n--)
    {
        int tx,ty;
        scanf("%d%d",&tx,&ty);
        if(tx==ty || tx==0 || ty==0)
        {
            ans=-1;
        }
        if(ans==-1)
            continue;
        ans^=sg[tx][ty];
    }
    //printf("%d\n",win);
    if(ans==0)
    {
        printf("N");
    }
    else
    {
        printf("Y");
    }

    return 0;
}
