
#include<bits/stdc++.h>
#define mem(a,b) memset(a,(b),sizeof(a))
using namespace std;
const int MAXN=4e5+5;

int head[MAXN],to[MAXN],w[MAXN],nxt[MAXN],o;
int dep[MAXN];
void add_edge(int a,int b,int c)
{
    nxt[o]=head[a];
    to[o]=b;
    w[o]=c;
    head[a]=o++;
    nxt[o]=head[b];
    to[o]=a;
    w[o]=c;
    head[b]=o++;
}
int ans=0;
void bfs(int u,int k){
    queue<int> Q;
    while(!Q.empty())Q.pop();
    mem(dep,-1);
    dep[u]=0;
    Q.push(u);
    while(!Q.empty()){
        int x=Q.front();Q.pop();
        if(dep[x]>=k) continue;
        for(int i=head[x];~i;i=nxt[i]){
            int y=to[i];
            ans=max(ans,w[i]);
            if(dep[y]==-1){
                dep[y]=dep[x]+1;
                Q.push(y);
            }
        }
    }
}

int main(void)
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("path.in","r",stdin);
#endif

    int t;scanf("%d",&t);
    while(t--){
        mem(head,-1);o=0;
        ans=0;
        int n,m,u,k,l;
        scanf("%d%d%d%d%d",&n,&m,&u,&l,&k);
        for(int i=0;i<m;i++){
            int a,b,c;scanf("%d%d%d",&a,&b,&c);
            add_edge(a,b,c);
        }

        bfs(u,k);
        printf("%d\n",ans);
    }
}
