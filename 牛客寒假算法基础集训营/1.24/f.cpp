//Problem Web:  https://ac.nowcoder.com/acm/contest/327/F
#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
//#define use_t 1
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
ll state[200005];
ll vis[200005];
ll sw[200005];
vector <ll> BC[200005];
vector <ll> C[200005];
ll t,n,m;
const int MAXN = 400005;
const int MAXM = 800005;

struct Edge
{
    int to,next;
}edge[MAXM];
int head[MAXN],tot;
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];//Belong数组的值1~scc
int Index,top;
int scc;
bool Instack[MAXN];
int num[MAXN];
void Tarjan(int u)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;     Instack[u] = true;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        v = edge[i].to;
        if( !DFN[v] )
        {
            Tarjan(v);
            if(Low[u] > Low[v])
                Low[u] = Low[v];
        }
        else if(Instack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u])
    {
        scc++;
        do
        {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
            num[scc]++;
        }         while(v != u);
    }
}
bool solvable(int n)//n是总个数,需要选择一半
{
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    memset(num,0,sizeof(num));
    Index = scc = top = 0;
    for(int i = 0;i < n;i++)
        if(!DFN[i])
            Tarjan(i);
   // cout<<"Tarjan"<<endl;
    for(int i = 0;i < n;i += 2)
    {
        if(Belong[i] == Belong[i^1])
            return false;
    }
    return true;
}

int main ()
{mem(vis,0);
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
    cin>>n>>m;
    init();
    //cout<<n<<m<<endl;
    rep(i,1,n)
    {
        scanf("%lld",state+i);
    }
    ll k,cc;
    rep(i,1,m)
    {
        scanf("%lld",&k);
        rep(j,1,k)
        {
            scanf("%lld",&cc);
            C[i].push_back(cc);
            BC[cc].push_back(i);
        }
    }
    rep(i,1,n)
    {
        if(state[i]==1 && BC[i].size()==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else if(state[i]==1 && BC[i].size()==1)
        {
            ll q=BC[i][0]<<1;
            addedge(q,q^1);
            //addedge(i*2,i);
        }
        else if(state[i]==0 && BC[i].size()==1)
        {
            ll q=BC[i][0]<<1;
            //addedge(i,i*2);
            addedge(q^1,q);
        }
        else if(state[i]==1 && BC[i].size()==2)
        {
            //addedge(i,i*2);
            ll x=BC[i][1]<<1;
            ll y=BC[i][0]<<1;
            addedge(x,y^1);
            addedge(y,x^1);
            addedge(x^1,y);
            addedge(y^1,x);
        }
        else if(state[i]==0 && BC[i].size()==2)
        {
            ll x=BC[i][1]<<1;
            ll y=BC[i][0]<<1;
            addedge(x^1,y^1);
            addedge(y^1,x^1);
            addedge(x,y);
            addedge(y,x);
        }
    }
   // cout<<"jianbian"<<endl;

    if(solvable(m*2)==false)
    cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

    for(int i=0;i<m*2;i++)
    {
        if(Belong[i]==Belong[1])
        {
            cout<<i<<endl;
        }
    }


#ifdef use_t
}
#endif // use_t
    return 0;
}
