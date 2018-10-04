#include<bits/stdc++.h>
using namespace std;
vector <int >G[100005];
int dp[100005];
int vis[100005];
int bfs(int a)
{
    vis[a]=1;
    if(G[a].empty())
        return 1;
    else
    {
        int ans=1;
        for(int i =0;i<G[a].size();i++)
        {
            if(vis[G[a][i]]==1)
                continue;
            ans=max(ans,bfs(G[a][i])+1);
        }
        return ans;
    }
}
int main ()
{
    //memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    int n,a;
    scanf("%d%d",&n,&a);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    printf("%d",bfs(a));
    return 0;
}
