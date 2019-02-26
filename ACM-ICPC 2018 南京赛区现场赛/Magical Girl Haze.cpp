#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
const int NN = 2e6+5;
const int INF = 0x3f3f3f3f;
typedef struct{
    int u,v;
    long long w;
}edge;
int head[maxn],ne[NN];
edge E[NN];

struct D{
    int num;
    long long d;
    int mag;
    D(){}
    D(int _num,long long _w,int _kind):num(_num),d(_w),mag(_kind){}
};
struct cmp{
    bool operator ()(D a,D b){
        return a.d > b.d;
    }
};
long long dis[maxn][15];
void BFS(int K){
    priority_queue<D,vector<D>,cmp> Q;
    memset(dis,INF,sizeof(dis));
    for(int i = 0;i<=K;i++)
        dis[1][i] = 0;
    Q.push(D(1,0,K));
    struct D s;
    while(!Q.empty()){
        s = Q.top();
        Q.pop();
        for(int i = head[s.num] ; i!=-1 ; i=ne[i]){
            long long sum = s.d + E[i].w;
            if(sum < dis[E[i].v][s.mag]){
                dis[E[i].v][s.mag] = sum;
                Q.push(D(E[i].v,sum,s.mag));
            }
            if(s.mag > 0){
                sum = sum-E[i].w;
                if(sum < dis[E[i].v][s.mag-1]){
                    dis[E[i].v][s.mag-1] = sum;
                    Q.push(D(E[i].v,sum,s.mag-1));
                }
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
            int N,M,K;
            scanf("%d%d%d",&N,&M,&K);
            for(int i = 1;i<=N;i++)
            {
                head[i] = -1;
                ne[i] = -1;
            }
            int tot = 0;
            for(int i = 1;i<=M;i++){
                int u,v;
                long long w;
                scanf("%d%d%lld",&u,&v,&w);
                E[tot].u = u;
                E[tot].v = v;
                E[tot].w = w;
                ne[tot] = head[u];
                head[u] = tot++;
            }
            BFS(K);
            long long ans = INF;
            for(int i = 0;i<=K;i++)
                ans = min(ans,dis[N][i]);
            printf("%lld\n",ans);
    }
    return 0;
}
