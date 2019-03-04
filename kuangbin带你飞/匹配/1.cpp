#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
char maze[maxn][maxn];
int ma,n;
int used[maxn][maxn];
void mark(int i,int j,int type)
{
    used[i][j]=type;
    for(int k=1;k<=n;k++)
    {
        if(j+k>=n)
            break;
        if(maze[i][j+k]=='X')
            break;
        used[i][j+k]=type;
    }
    for(int k=1;k<=n;k++)
    {
        if(j-k<0)
            break;
        if(maze[i][j-k]=='X')
            break;
        used[i][j-k]=type;
    }
    for(int k=1;k<=n;k++)
    {
        if(i+k>=n)
            break;
        if(maze[i+k][j]=='X')
            break;
        used[i+k][j]=type;
    }
    for(int k=1;k<=n;k++)
    {
        if(i-k<0)
            break;
        if(maze[i-k][j]=='X')
            break;
        used[i-k][j]=type;
    }
}
void dfs(int th,int ans)
{
    ma=ans>ma?ans:ma;
    if(th>=n)
        return ;
    for(int i=0;i<n;i++)
    {
        if(used[i]!=0 && maze[th][i]=='.')
        {
            //used[i]=1;
            ans++;
            mark(th,i,1);
            dfs(th,ans);
            dfs(th+1,ans);
            mark(th,i,0);
            //used[i]=0;
            ans--;
        }
    }
    return ;
}
int main ()
{

    while(~scanf("%d",&n))
    {
        memset(used,0,sizeof(used));
        if(!n)
            return 0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",maze[i]);
        }
        ma=0;
        dfs(0,0);
        printf("%d\n",ma);
    }
    return 0;
}
