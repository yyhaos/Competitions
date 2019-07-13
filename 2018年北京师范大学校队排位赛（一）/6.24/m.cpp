//Problem Web:
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=10010;
const ll q=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a%q;
        a=a*a%q;
        b/=2LL;
    }
    return ans;
}

ll t,n,m;
struct edge
{
    ll u,v,c1,c2;
    edge(ll _u=0, ll _v=9,ll _c1=0,ll _c2=0)
    {
        u=_u;
        v=_v;
        c2=_c2;
        c1=_c1;
    }
};

vector<edge> M[maxn];
ll gen_i[maxn];
ll i_gen[maxn];
void get1(ll gen)
{
    for(int i=1;i<=n;i++)
    {
        gen_i[i]=-1;
    }
    gen_i[gen]=0;
    stack <ll> s;
    s.push(gen);
    ll nxt;
    while(!s.empty())
    {

        ll top=s.top();
        s.pop();
        //cout<<top<<endl;
        ll si=M[top].size();
        for(ll i=0;i<si;i++)
        {
            nxt=M[top][i].v;
            if(gen_i[nxt]==-1)
            {
                s.push(nxt);
                gen_i[nxt]=gen_i[top]+M[top][i].c1;
            }
        }
    }
}

void get2(ll gen)
{
    for(int i=1;i<=n;i++)
    {
        i_gen[i]=-1;
    }
    i_gen[gen]=0;
    stack <ll> s;
    s.push(gen);
    ll nxt;
    while(!s.empty())
    {

        ll top=s.top();
        s.pop();
        //cout<<top<<endl;
        ll si=M[top].size();
        for(ll i=0;i<si;i++)
        {
            nxt=M[top][i].v;
            if(i_gen[nxt]==-1)
            {
                s.push(nxt);
                i_gen[nxt]=i_gen[top]+M[top][i].c2;
            }
        }
    }
}

int rmq[2*maxn];
struct ST{
    int mm[2*maxn];
    int dp[2*maxn][20];
    void init(int n)
    {
        mm[0]=-1;
        for(int i=1;i<=n;i++)
        {
            mm[i]=((i&(i-1)) == 0 )? mm[i-1]+1:mm[i-1];
            dp[i][0]=i;
        }
        for(int j=1;j<=mm[n];j++)
        {
            for(int i=1;i+(1<<j) - 1<= n;i++)
                dp[i][j]=rmq[dp[i][j-1]]<
                rmq[dp[i+(1<<(j-1))][j-1]]? dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
        }
    }
    int query(int a,int b)
    {
        if(a>b)
            swap(a,b);
        int k=mm[b-a+1];
        return rmq[dp[a][k]]<=
        rmq[dp[b-(1<<k)+1][k]]?dp[a][k]:dp[b-(1<<k)+1][k];
    }
};
struct Edge
{
    int to,next;
};
Edge ed[maxn*2];
int tot,head[maxn];
int F[maxn*2];
int P[maxn*2];
int cnt;
ST st;
void init()
{

    tot=0;
    mem(head,-1);
}
void addedge(int u,int v)
{
    ed[tot].to=v;
    ed[tot].next=head[u];
    head[u]=tot++;
}
void dfs(int u,int pre,int dep)
{
    F[++cnt]=u;
    rmq[cnt]=dep;
    P[u]=cnt;
    for(int i=head[u];i!=-1;i=ed[i].next)
    {
        int v=ed[i].to;
        if(v==pre)
            continue;
        dfs(v,u,dep+1);
        F[++cnt]=u;
        rmq[cnt]=dep;
    }
}
void LCA_init(int root,int node_num)
{
    cnt=0;
    dfs(root,root,0);
    st.init(2*node_num-1);
}
int query_lca(int u,int v)
{
    return F[st.query(P[u],P[v])];
}
bool flag[maxn];



int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    ll sc=0;

    scanf("%lld",&n);
    for(int i=0;i<=1+n;i++)
        M[i].clear();
    ll u,v,c1,c2;
    init();
    ll N=n;
    memset(flag,false,sizeof(flag));

    for(int i=1;i<n;i++)
    {
        scanf("%lld%lld%lld%lld",&u,&v,&c1,&c2);
        M[u].push_back(edge(u,v,c1,c2));
        M[v].push_back(edge(v,u,c2,c1));
        sc+=c1+c2;
        addedge(u,v);
        addedge(v,u);
        flag[v]=true;
    }
    int root=1;
    for(int i=1;i<=N;i++)
    {
        if(!flag[i])
        {
            root=i;
            break;
        }
    }
    root=1;
    get1(root);
    get2(root);
    LCA_init(root,N);



//    for(int i=1;i<=n;i++)
//    {
//         cout<<gen_i[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=1;i<=n;i++)
//    {
//         cout<<i_gen[i]<<" ";
//    }
//    cout<<endl;
//
//    cout<<sc<<endl;

    ll quee;
    scanf("%lld",&quee);
    ll ti,tj;
    while(quee--)
    {
        scanf("%lld%lld",&ti,&tj);
        ll ans=sc;
        ll Fa=query_lca(ti,tj);
        ll ji=i_gen[tj]-i_gen[Fa]+gen_i[ti]-gen_i[Fa];
        printf("%lld\n",sc-ji);
    }

    for(int i=1;i<=n;i++)
        M[i].clear();
#ifdef use_t
}
#endif // use_t
    return 0;
}





