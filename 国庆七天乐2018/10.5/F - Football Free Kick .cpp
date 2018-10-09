#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 1;t<=T;t++){
        int N,M,Q;
        scanf("%d%d%d",&N,&M,&Q);
        bool vis[N+1] = {0};
        for(int i = 1;i<=M;i++)
            vis[i] = 1;
        int ans = 1;
        printf("Case %d: \n",t);
        while(Q--){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x==1 && vis[x+1] == 1)
                ans++;
            else if(x == N && vis[x-1] == 1)
                ans++;
            else if(x != 1 && x !=N && vis[x-1] == 1 && vis[x+1] == 1)
                ans++;
            else if(x != 1 && x !=N && vis[x-1] == 0 && vis[x+1] == 0)
                ans--;
            vis[x] = 0;
            if(y == N && vis[y-1] == 1)
                ans--;
            else if(y == 1 && vis[y+1] == 1)
                ans--;
            else if(y != N && y != 1 && vis[y+1] == 0 && vis[y-1] == 0)
                ans++;
            else if(y != N && y != 1 && vis[y+1] == 1 && vis[y-1] == 1)
                ans--;
            vis[y] = 1;
            printf("%d\n",ans);
        }
    }
    return 0;
}
