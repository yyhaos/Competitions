#include<bits/stdc++.h>
#define mem(a,b) memset(a,(b),sizeof(a))
typedef long long LL;
using namespace std;
const LL MAXN=1e5+10LL;
typedef pair<LL,LL> PII;
typedef pair<pair<LL,LL>,LL> PIII;
map<PII,int> M;
vector<PII> G[MAXN];
const LL INF=10000000000000000LL;
struct edge{
    LL u,v;
    LL w;
    bool operator < (edge a){
        return w<a.w;
    }
}E[MAXN*30LL];

LL fa[MAXN];
LL find_fa(LL x){
    return x==fa[x]? x : fa[x]=find_fa(fa[x]);
}

int main(void)
{
     #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    LL t;scanf("%lld",&t);
    while(t--){
        mem(G,0LL);
        M.clear();
        LL n;scanf("%lld",&n);
        for(LL i=0LL;i<n-1;i++){
            LL a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
            G[a].push_back({b,c});
            G[b].push_back({a,c});
        }
        LL o=0LL;
        LL cnt=0LL;
        for(LL i=1;i<=n;i++){
            PII tmp1,tmp2;
            LL sz=G[i].size();
            if(sz<=1)
                continue;
            if(sz==2)
            {
                LL j=0LL;
                tmp1=G[i][j];
                LL node1=tmp1.first;
                LL w1=tmp1.second;
                LL x1=i,x2=node1;
                if(x1>x2) swap(x1,x2);
                if(M[{x1,x2}]==0LL) M[{x1,x2}]=++o;
                LL k=1;
                tmp2=G[i][k];
                LL node2=tmp2.first;
                LL w2=tmp2.second;
                LL y1=i,y2=node2;
                if(y1>y2) swap(y1,y2);
                if(M[{y1,y2}]==0LL) M[{y1,y2}]=++o;
                E[cnt].u=M[{x1,x2}];
                E[cnt].v=M[{y1,y2}];
                E[cnt].w=1ll*w1+1ll*w2;
                cnt++;
            }
            if(sz>=3)
            {
                LL minn=INF,th;
                LL node1;
                LL w1;
                for(LL j=0LL;j<sz;j++)
                {
                    tmp1=G[i][j];
                    LL tnode1=tmp1.first;
                    LL tw1=tmp1.second;
                    minn=min(minn,tw1);
                    if(minn==tw1)
                    {
                        node1=tnode1;
                        w1=tw1;
                        th=j;
                    }
                }
                LL x1=i,x2=node1;
                if(x1>x2) swap(x1,x2);
                if(M[{x1,x2}]==0LL) M[{x1,x2}]=++o;

                for(LL k=0LL;k<sz;k++){
                    if(k==th)
                        continue;
                    tmp2=G[i][k];
                    LL node2=tmp2.first;
                    LL w2=tmp2.second;
                    LL y1=i,y2=node2;
                    if(y1>y2) swap(y1,y2);
                    if(M[{y1,y2}]==0LL) M[{y1,y2}]=++o;
                    E[cnt].u=M[{x1,x2}];
                    E[cnt].v=M[{y1,y2}];
                    E[cnt].w=1ll*w1+1ll*w2;
                    cnt++;
                }
            }

//            for(LL j=0LL;j<sz;j++){
//                tmp1=G[i][j];
//                LL node1=tmp1.first;
//                LL w1=tmp1.second;
//                LL x1=i,x2=node1;
//                if(x1>x2) swap(x1,x2);
//                if(M[{x1,x2}]==0LL) M[{x1,x2}]=++o;
//                for(LL k=j+1;k<sz;k++){
//                    tmp2=G[i][k];
//                    LL node2=tmp2.first;
//                    LL w2=tmp2.second;
//                    LL y1=i,y2=node2;
//                    if(y1>y2) swap(y1,y2);
//                    if(M[{y1,y2}]==0LL) M[{y1,y2}]=++o;
//                    E[cnt].u=M[{x1,x2}];
//                    E[cnt].v=M[{y1,y2}];
//                    E[cnt].w=1ll*w1+1ll*w2;
//                    cnt++;
//                }
//            }
        }
        sort(E,E+cnt);
       // for(LL i=0LL;i<cnt;i++) printf("%lld %lld\n",E[i].u,E[i].v);
        for(LL i=1;i<=o;i++) fa[i]=i;
        LL num=0LL;
        LL ans=0LL;
        for(LL i=0LL;i<cnt;i++){
            LL u=E[i].u;
            LL v=E[i].v;
            LL ww=E[i].w;
            LL fu=find_fa(u);
            LL fv=find_fa(v);
            if(fu==fv) continue;
            fa[fu]=fv;
            ans+=ww;
            num++;
            if(num==o) break;
        }
        printf("%lld\n",ans);
    }

}
