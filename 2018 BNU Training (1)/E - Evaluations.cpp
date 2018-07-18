
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100005;
struct bili{
    int to,w;
    bili(int to,int w):to(to),w(w){}
};

vector<bili> G[maxn];
int n,l;
int root;
int vis[maxn];
int prime[10000];
int par[20][maxn];
int depth[maxn];
ll from_root[maxn];

void dfs(int v,int p,ll weight){
    par[0][v] = p;
    depth[v] = depth[p]+1;
    from_root[v] = weight;
    for (int i=0;i<G[v].size();i++){
        if (G[v][i].to!=p)
            dfs(G[v][i].to,v,weight*G[v][i].w);
    }
}

void in(){
    l = 0;
    int p = 0;
    for (int i=0;i<=100000;i++) vis[i] = 1;
    vis[0] = vis[1] = 0;
    for (int i=2;i<=100000;i++){
        if(vis[i]){
            prime[p++] = i;
            for (int j=2*i;j<=100000;j+=i)
                vis[j] = 0;
        }
    }
}

void init(){
    dfs(1,-1,1);
    for (int k=0;k<18;k++){
        for (int v=1;v<=n;v++){
            if (par[k][v]<0) par[k+1][v] = -1;
            else par[k+1][v] = par[k][par[k][v]];
        }
    }
}

int lca(int u,int v){
    if (depth[u]>depth[v]) swap(u,v);
    for (int k=0;k<19;k++){
        if ((depth[v]-depth[u])>>k&1){
            v = par[k][v];
        }
    }
    if (u==v) return u;
    for (int k=18;k>=0;k--){
        if (par[k][u]!=par[k][v]){
            u = par[k][u];
            v = par[k][v];
        }
    }
    return par[0][u];
}

int ok(ll r){
    for (int i=0;i<9593;i++){
        if (prime[i]>sqrt(r))
            break;
        if (r%prime[i]==0){
            int m = r/prime[i];
            if (vis[m]==1){
                return 1;
            }

        }
    }
    return 0;
}
int main(){
    freopen("evaluations.in","r",stdin);
    int T,kase = 0;
    scanf("%d",&T);
    in();
    while(T--){
        scanf("%d",&n);
        for (int i=0;i<n-1;i++){
            int r,s,wei;
            scanf("%d%d%d",&r,&s,&wei);
            G[r].push_back(bili(s,wei));
            G[s].push_back(bili(r,wei));
        }
        init();
        int ans = 0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                int pp = lca(i,j);
                ll r = from_root[i]*from_root[j]/from_root[pp]/from_root[pp];
                if (ok(r)){
                    ans++;
                }
                //printf("%d %d %d\n",i,j,r);
            }
        }
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
