#include<bits/stdc++.h>
using namespace std;
const int maxn = 4000005;
vector< pair<int,int> > g[maxn];
const int inf=1e9+7;

int vis[maxn],dis[maxn];

struct node{
    int pos,fli,cost;
    bool operator < (const node & o) const {
        return cost > o.cost;
    }


}nod;

int nn(int pos,int cnt)
{
    return 1010*pos+cnt;
}




void dij()
{


    for(int i=0;i<maxn;++i)
    {
        dis[i]=inf;
        vis[i]=0;
    }

    dis[nn(1,0)]=0;
priority_queue<node> pq;
    nod.pos=1;
    nod.fli=0;
    nod.cost=0;

    pq.push(nod);
    while(pq.size()){

        node now= pq.top();
        pq.pop();

        int u=nn(now.pos,now.fli);

        if(vis[u])continue;
        vis[u]=1;


        for(int i=0;i<g[u].size();++i){
            int v=g[u][i].first;

            if(vis[v])continue;
            if(dis[u]+g[u][i].second<=dis[v]){

                dis[v]=dis[u]+g[u][i].second;

                nod.pos=v/1010;
                nod.fli=now.fli+1;
                nod.cost=dis[v];

                pq.push(nod);

            }

        }



    }











}











int main()
{

    #ifdef yyhaos
    freopen("in.txt","r",stdin);
    #endif // yyhaos



int n,m;
    scanf("%d%d",&n,&m);




    for(int i=1;i<=m;++i){
        int u,v,w;

        scanf("%d%d%d",&u,&v,&w);
        for(int j=0;i<=1000;++j){
            g[nn(u,j)].push_back(make_pair(nn(v,j+1),w));

        }


    }



dij();






    int t;
    scanf("%d",&t);

    while(t--){

        int a,b;
        scanf("%d%d",&a,&b);

        int ans=1e9+7;
        b++;

        for(int i=0;i<=b;++i){
            if(dis[nn(a,i)]<=ans)
                ans=dis[nn(a,i)];
        }

        if(ans<10000000) printf("=] %d\n",ans);
        else printf("=[\n");



    }



    return 0;
}
