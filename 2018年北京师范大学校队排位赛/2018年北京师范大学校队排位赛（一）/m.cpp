//Problem Web:  https://codeforces.com/gym/225574/problem/M
#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1000;
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
vector<pair<ll,ll>> M[100005];
vector<pair<ll,ll>> Q[100005];
vector<pair<ll,ll>> M2[100005];
ll dis[100005];
ll dis2[100005];
ll t,n,m;
ll u,v,c1,c2;
ll sum;
ll ans[100005];
ll fa[100005];
ll vis[100005];
ll vv[100005];
void init(int k)
{
    rep(i,0,k+2)
    {
        fa[i]=i;
        Q[i].clear();
        M[i].clear();
        M2[i].clear();
        dis[i]=dis2[i]=0;
        vis[i]=0;
        ans[i]=0;
        vv[i]=0;
    }
    sum=0;

    return ;
}
ll fi(ll a)
{
    if(fa[a]==a)
        return a;
    else
    {
        return fa[a]=fi(fa[a]);
    }
}
bool un(ll a,ll b)
{
    if(fi(a)!=fi(b))
    {
        fa[fi(b)]=fi(a);
        fi(a);
        fi(b);
        return true;
    }
    return false;
}

void Tarjan(ll u)
{
//    cout<<"Tarjan "<<u<<endl;
    vv[u]=1;
    ll v;
    for(int i=0;i<M[u].size();i++)
    {
        v=M[u][i].first;
        if(vv[v]==1)
            continue;
        Tarjan(v);
        un(u,v);
        vis[v]=1;
    }
    ll e;
    for(int i=0;i<Q[u].size();i++)
    {
        e=Q[u][i].first;
        if(vis[e]==1)
        {
//            cout<<u<<" + "<<e<<" = "<<fi(e)<<endl;
//            cout<<Q[u][i].second<<endl;
//            cout<<sum<<" - "<< dis[u]-dis[fi(e)] + dis2[e]-dis2[fi(e)]<<
//                " "<<(dis2[u]-dis2[fi(e)] + dis[e]-dis[fi(e)] )<<endl;
            if(Q[u][i].second<0)
            {
                ans[-Q[u][i].second]=sum-(dis2[u]-dis2[fi(e)] + dis[e]-dis[fi(e)] );
            }
            else
            {
                ans[Q[u][i].second]=sum-(dis[u]-dis[fi(e)] + dis2[e]-dis2[fi(e)] );
            }

        }
    }
}
void dfs(ll st)
{
    //dis[st]=0;
    mem(dis,-1);
    dis[st]=0;
    stack<ll> s;
    s.push(st);
    ll to;
    while(!s.empty())
    {
        to=s.top();
        s.pop();

        for(int i=0;i<M[to].size();i++)
        {
            if(dis[M[to][i].first]>=0)
                continue;
            dis[M[to][i].first]=dis[to]+M[to][i].second;
            s.push(M[to][i].first);
        }
    }
    return;
}
void dfs2(ll st)
{
    //dis[st]=0;
    mem(dis2,-1);
    dis2[st]=0;
    stack<ll> s;
    s.push(st);
    ll to;
    while(!s.empty())
    {
        to=s.top();
        s.pop();
        for(int i=0;i<M2[to].size();i++)
        {
            if(dis2[M2[to][i].first]>=0)
                continue;
            dis2[M2[to][i].first]=dis2[to]+M2[to][i].second;
            s.push(M2[to][i].first);
        }
    }
    return ;
}
int main ()
{
    //ll a[5];
    //mem(a,-1);
    //cout<<a[2]<<" "<<(a[2]==-1LL)<<endl;
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
int ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    cin>>n;
    init(n);
    rep(i,1,n-1)
    {
        scanf("%lld%lld%lld%lld",&u,&v,&c1,&c2);
//        cout<<i<<endl;
        M[u].push_back(make_pair(v,c1));
        M[v].push_back(make_pair(u,c2));
        M2[u].push_back(make_pair(v,c2));
        M2[v].push_back(make_pair(u,c1));
        sum+=c1+c2;
    }
//    cout<<sum<<endl;
    ll gen=1;
    dfs(gen);
    dfs2(gen);
//    rep(i,1,n)
//    {
//        cout<<dis[i]<<" ";
//    }
//    cout<<endl;
//    rep(i,1,n)
//    {
//        cout<<dis2[i]<<" ";
//    }
//    cout<<endl;

    ll qq,x,y;
    cin>>qq;
   // cout<<qq<<endl;
    rep(i,1,qq)
    {
        scanf("%lld%lld",&x,&y);
        Q[x].push_back(make_pair(y,i));
        Q[y].push_back(make_pair(x,-i));
        if(x==y)
        {
            ans[i]=sum;
        }
    }
    //cout<<"c"<<endl;
    Tarjan(gen);
    rep(i,1,qq)
    {
        printf("%lld\n",ans[i]);
    }
#ifdef use_t
}
#endif // use_t
    return 0;
}
