#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
//int pre[maxn];
int tot;
int pre[maxn][maxn];
int vis[maxn];
int dfs(int i)
{
    vis[i]=1;
    for(int j=1;j<tot;j++)
    {
        if(j==i)
            continue;
        if(pre[i][j]==1)
        {
            if(vis[j]==0)
                dfs(j);
            vis[j]=1;
            for(int k=1;k<=tot;k++)
            {
                if(k==i || k==j)
                    continue;
                if(pre[j][k]==1)
                    pre[i][k]=1;
            }
        }
    }
    return 0;
}

int main()
{
   // freopen("test.txt","r",stdin);
   // init();
   memset(pre,0,sizeof(pre));
    map<string,int> G;
    G.clear();
    int n,m;
    scanf("%d %d\n",&n,&m);
    tot = 1;

    //char tmp[100];
    //cout<<n<<m<<endl;
    for(int i = 0;i<n;i++){
        int na,nb;
        string  a,b;
        cin>>a;
        scanf(" are worse than ");
        cin>>b;
        //cout<<"a:"<<a<<" b:"<<b<<endl;

        if(G[a] == 0){
            G[a] = tot;
            na = tot++;
        }
        else na = G[a];
        if(G[b] == 0){
            G[b] = tot;
            nb = tot++;
        }
        else nb = G[b];
       // if(Find(na,-1) != Find(nb,-1))
        pre[na][nb] = 1;
    }

    memset(vis,0,sizeof(vis));
    for(int i=1;i<tot;i++)
    {
        dfs(i);
    }

    for(int i = 0;i<m;i++){
        string a,b;
        cin>>a;
        scanf(" are worse than ");
        cin>>b;
        //cout<<"a:"<<a<<" b:"<<b<<endl;

        if(G[a] == 0 || G[b] == 0){
            printf("Pants on Fire\n");
            continue;
        }
        int na=G[a];
        int nb=G[b];
        if(pre[na][nb] == 0 && pre[nb][na]==0){
            printf("Pants on Fire\n");
            continue;
        }
        if(pre[na][nb] ==1){
            printf("Fact\n");
            continue;
        }
        if(pre[nb][na]==1){
            printf("Alternative Fact\n");
            continue;
        }
        printf("Pants on Fire\n");
    }
    return 0;
}
