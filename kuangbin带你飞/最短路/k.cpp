//Problem Web:  https://vjudge.net/contest/239087#problem/K
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define pr pair
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

ll t,n,m;
struct pa
{
    ll th,to,we;
    pa(ll t=0,ll o=0,ll w=0)
    {
        th=t;
        to=o;
        we=w;
    }
};
struct edge{
	int to,cost;
	edge(int to,int cost){
		this->to=to;
		this->cost=cost;
	}
	edge() {}
};
int head[30010],nextt[160000],cnt;
edge G[160000];
struct node
{
    ll th,dis;
    node (ll t=0,ll d=0):
        th(t),dis(d)
    {
    }
    friend bool operator < (node a,node b)
    {
        return a.dis>b.dis;
    }
};
vector< pr<ll,ll> > M[30005];
typedef pair<int,int> P;
priority_queue <node> pq;

ll dis[30005];
ll used[30005];
//ll bian[1000005];

void ddi(ll ty)
{
  //  cout<<"ty "<<ty<<endl;
   // mem(dis,1);
    dis[1]=0;
    while(!pq.empty())
        pq.pop();
    pq.push(node(1,0));
    mem(used,0);
    while(!pq.empty() )
    {
        node tt=pq.top();
        pq.pop();
        ll u=tt.th;
        if(used[u]==1)
            continue;
        used[u]=1;
//        if( dis[]<tt.first)
//            continue
        //used[tt.th]=1;
//        for(int i=head[u];i!=-1;i=nextt[i]){
//				int v=G[i].to;
//				if(dis[v]>dis[u]+G[i].cost){
//					dis[v]=dis[u]+G[i].cost;
//					pq.push(node(v,dis[v]));
//				}
//        }
        //if(M[u].size()>0)
        for(int i=0;i<M[u].size();i++)
        {
            int v=M[u][i].first;
            int cost=M[u][i].second;

            //cout<<v<<" "<<cost<<endl;
            if(dis[v]>dis[u]+cost)
            {
                dis[v]=dis[u]+cost;
                pq.push(node(v,dis[v]));
            }
        }
    }
}
void init()
{
    cnt=0;
    rep(i,1,n)
        dis[i]=999999999999999998LL;
    //cout<<dis[1];
    while(!pq.empty())
    {
        pq.pop();
    }
}

void add(int from,int to,int cost){
	nextt[cnt]=head[from];
	G[cnt]=edge(to,cost);
	head[from]=cnt;
	cnt++;
}
int main ()
{
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

    scanf("%lld%lld",&n,&m);
    ll t1,t2,ww;
    init();
//    while(!q.empty()) q.pop();
	memset(head,-1,sizeof(head));
	cnt=0;
    rep(i,1,m)
    {
       // cout<<i<<endl;
        scanf("%lld %lld %lld",&t1,&t2,&ww);
        M[t1].push_back(mp(t2,ww));
        //add(t1,t2,ww);
    }
   // if(ii==4)
   // {

   // }
    //cout<<"st"<<endl;
    //cout<<dis[1];
    ddi(1);
    cout<<dis[n];



#ifdef use_t
}
#endif // use_t
    return 0;
}
