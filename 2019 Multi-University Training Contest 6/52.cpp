#include<bits/stdc++.h>
#define mem(a,b) memset(a,(b),sizeof(a))
using namespace std;
typedef long long LL;

const int maxn = 4e3+5;

vector<int> x_y[maxn];
vector<int> x_val[maxn];


LL pre[maxn<<2],suf[maxn<<2],maxx[maxn<<2],all[maxn<<2];


void solve1(int n)
{
    for(int i=0;i<=n+1;i++){
        x_y[i].clear();
        x_val[i].clear();
    }
    int xx[maxn],yy[maxn];
    int x[maxn],y[maxn],w[maxn];
    for(int i=0;i<n;i++){
        scanf("%d%d%lld",x+i,y+i,w+i);
        xx[i]=x[i];
        yy[i]=y[i];
    }
    sort(xx,xx+n);sort(yy,yy+n);
    for(int i=0;i<n;i++){
        int tmpx = lower_bound(xx,xx+n,x[i])-xx +1;
        int tmpy = lower_bound(yy,yy+n,y[i])-yy +1;
        x_y[tmpx].push_back(tmpy);
        x_val[tmpx].push_back(w[i]);
    }
    for(int i=1;i<=n;i++)
        for(int y:x_y[i])
            printf("%d %d\n",i,y);
}

void push_up(int rt)
{
    all[rt]=all[rt<<1]+all[rt<<1|1];
    maxx[rt]=max(maxx[rt<<1],maxx[rt<<1|1]);
    maxx[rt]=max(maxx[rt],suf[rt<<1]+pre[rt<<1|1]);

    LL tmp = all[rt<<1|1] + suf[rt<<1];
    suf[rt] = max(tmp,suf[rt<<1|1]);

    tmp = all[rt<<1] + pre[rt<<1|1];
    pre[rt] = max(tmp,pre[rt<<1]);
    //printf("rt = %d maxx = %lld\n",rt,maxx[rt]);
}

void build(int rt,int l,int r)
{
    if(l==r){
        pre[rt]=suf[rt]=maxx[rt]=all[rt]==0ll;
        return ;
    }
    int m=(l+r)>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    push_up(rt);
}

void update(int rt,int pos,int l,int r,LL val)
{
    if(l==r){
        all[rt]+=val;
        pre[rt]=suf[rt]=maxx[rt]=max(0ll,all[rt]);
        return ;
    }
    int m=(l+r)>>1;
    if(pos<=m) update(rt<<1,pos,l,m,val);
    else update(rt<<1|1,pos,m+1,r,val);
    push_up(rt);
}

int main(void)
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        solve1(n);
        LL ans=0;
        for(int i=1;i<=n;i++){
            build(1,1,n);
            for(int j=i;j<=n;j++){
                int sz=x_y[j].size();
                for(int k=0;k<sz;k++){
                    int pos = x_y[j][k];
                    LL val = x_val[j][k];
                    update(1,pos,1,n,val);
                }
                ans = max(ans,maxx[1]);
            }
        }
        printf("%lld\n",ans);
    }
}
