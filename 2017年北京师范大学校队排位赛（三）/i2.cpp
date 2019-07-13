#include <bits/stdc++.h>
using namespace std;

const int maxn = 100006;
const int V = 19;
vector<int> G[maxn];
vector<int> in;
int n,q;
int par[V][maxn];
int d[maxn], a[maxn];
bool used[maxn];
int pre[maxn];

int Find(int X){
    if(X == pre[X])
        return X;
    return pre[X] = Find(pre[X]);
}

bool uni(int a,int b){
    if (Find(a)==Find(b)){
        return true;
    }
    return false;
}


void dfs(int v,int p,int dst){
    used[v] = true;
    par[0][v] = p;
    d[v] = dst;
    for (int i=0;i<G[v].size();i++){
        if (G[v][i]!=p)
            dfs(G[v][i],v,dst+1);
    }
}

void init(){
    for (int i=0;i<in.size();i++){
        dfs(in[i],-1,0);
    }
    for (int k=0;k+1<V;k++){
        for (int v=0;v<n;v++){
            if (par[k][v]<0) par[k+1][v] = -1;
            else par[k+1][v] = par[k][par[k][v]];
        }
    }
}

int lca(int u,int v){
    if (d[u]>d[v]) swap(u,v);
    for (int k=0;k<V;k++){
        if ((d[v]-d[u]>>k)&1){
            v = par[k][v];
        }
    }
    if (u==v) return u;
    for (int k=V-1;k>=0;k--){
        if (par[k][u]!=par[k][v]){
            u = par[k][u];
            v = par[k][v];
        }
    }
    return par[0][u];
}

int main(){
    scanf("%d%d",&n,&q);
    memset(used,0,sizeof(used));
    for (int i=0;i<n;i++){
        pre[i] = i;
    }
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if (a[i]==-1){
            in.push_back(i);
        }
        else {
            pre[i] = a[i];
            G[a[i]].push_back(i);
        }
    }
    init();
    while(q--){
        int u,v;scanf("%d%d",&u,&v);
        if (!uni(u,v)) printf("No");
        else{
            int fa = lca(u,v);
            if (fa == v) printf("Yes");
            else printf("No");
        }
        printf("\n");
    }
    return 0;
}
