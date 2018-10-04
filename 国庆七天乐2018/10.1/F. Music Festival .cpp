#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int T, n, su, cnt1;
int dp[maxn][1<<10 + 1];
struct bili{
    int u,v,w,ind;
    bili(int _u = 0,int _v = 0,int _w = 0):u(_u),v(_v),w(_w){}
}val[maxn];
vector<int> E[maxn];
//struct Edge{
//    int v;
    //Edge(int _v = 0, int _cost = 0):v(_v),cost(_cost){}
//};

bool cmp(bili &a,bili& b){
    return a.v<b.v;
}
int tr(int i){
    return (1<<i);
}

void addedge(int u,int v){
    E[u].push_back(v);
}

int main(){
    //freopen("1.txt","r",stdin);
    scanf("%d",&T);
    su = tr(T);
    cnt1 = 0;
    memset(dp,0,sizeof(dp));
    for (int i=0;i<T;i++){
        int pp;
        scanf("%d",&pp);
        while(pp--){
            int u,v,w;
            ++cnt1;
            scanf("%d%d%d",&val[cnt1].u,&val[cnt1].v,&val[cnt1].w);
            val[cnt1].ind = tr(i);
        }
    }
    //for (int i=1;i<=cnt1;i++) printf("%d %d %d %d\n",val[i].u,val[i].v,val[i].w,val[i].ind);
    sort(val+1,val+1+cnt1,cmp);
    for (int i=1;i<=cnt1;i++){
        for (int j=i+1;j<=cnt1;j++){
            if (val[i].v<=val[j].u)
                addedge(i,j);
        }
    }
    /*for (int i=1;i<=n;i++){
        addedge(0,i);
        addedge(i,n+1);
    }*/
    for (int i=1;i<=cnt1;i++){
        dp[i][val[i].ind] = val[i].w;
    }
    for (int i=1;i<=cnt1;i++){
        for (int j=0;j<E[i].size();j++){
            int u = E[i][j];
            for (int k=0;k<su;k++){
                int ot = k|val[u].ind;
                if(dp[i][k]==0) continue;
                dp[u][ot] = max(dp[u][ot],dp[i][k]+val[u].w);
            }
        }
    }
    int ans = 0;
    for (int i=1;i<=cnt1;i++){
        ans = max(ans,dp[i][su-1]);
    }
    if (ans == 0) ans = -1;
    printf("%d\n",ans);
    return 0;
}
