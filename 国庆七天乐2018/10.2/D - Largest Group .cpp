#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 50;
int T,p,n;
vector<int> G[maxn];
int match[maxn];
bool used[maxn];
bool in[maxn][maxn];

void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v){
    used[v] = true;
    for (int i=0;i<G[v].size();i++){
        int u = G[v][i],w= match[u];
        if (w<0||!used[w]&&dfs(w)){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int b_match(){
    int res = 0;
    memset(match,-1,sizeof(match));
    for (int v=1;v<=p;v++){
        if (match[v]<0){
            memset(used,0,sizeof(used));
            if(dfs(v)){
                res++;
            }
        }
    }
    return res;
}

int main(){
    scanf("%d",&T);
    while(T--){
        memset(in,0,sizeof(in));
        scanf("%d%d",&p,&n);
        for (int i=1;i<=2*p+1;i++) G[i].clear();
        while(n--){
            int u,v;
            scanf("%d%d",&u,&v);
            in[u][v+p] = true;
        }
        for (int i=1;i<=p;i++){
            for (int j=p+1;j<=2*p;j++){
                if (!in[i][j]){
                    add_edge(i,j);
                }
            }
        }
        int ans = b_match();
        printf("%d\n",2*p-ans);
    }
    return 0;
}
