//Problem Web:  https://vjudge.net/contest/239087#problem/J
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

ll t,n,m;
struct edge
{
    ll s,t,w;
    edge(ll ss=0,ll tt=0,ll ww=9999999999999LL)
    {
        s=ss,t=tt,w=ww;
    }
    bool operator <(const edge &r)const
    {
        return w>r.w;
    }
};
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
struct node
{
    ll th,dis;
    node (ll t=0,ll d=0)
    {
        th=t;
        dis=d;
    }
    friend bool operator < (node a,node b)
    {
        return a.dis>b.dis;
    }
};
vector< pa > M[1000005];
priority_queue<node> pq;
ll dis[1000005];
ll used[1000005];
ll bian[1000005];
ll cnt=0;
void ddi(ll ty)
{
    mem(bian,0);
  //  cout<<"ty "<<ty<<endl;
   // mem(dis,1);
    dis[1]=0;
    while(!pq.empty())
        pq.pop();
    pq.push(node(1,0));
    mem(used,0);
    ll pp=n;
    while(!pq.empty() )
    {
        node tt=pq.top();
        pq.pop();
     //   cout<<tt.s<<"-"<<tt.t<<"="<<tt.w<<endl;
        if(used[tt.th]==1)
            continue;
        used[tt.th]=1;
//        dis[tt.t]=min(dis[tt.t],dis[tt.s]+tt.w);
        for(int i=0;i<M[tt.th].size();i++)
        {
            ll des=M[tt.th][i].to;
            if(used[des]==0 )
            {
                if(dis[des]>dis[tt.th]+M[tt.th][i].we)
                {
                    dis[des]=dis[tt.th]+M[tt.th][i].we;
                    pq.push(node(des,dis[des]));
                }
                //cnt++;
                //if(cnt%100000==0)
                //cout<<" ["<<cnt<<endl;
              // bian[M[tt.t][i].th]++;
            }
        }
    }
}
void init()
{
    cnt=0;
    rep(i,0,1000003)
        M[i].clear();
    rep(i,1,n)
        dis[i]=9999999999999998LL;
    //cout<<dis[1];
    while(!pq.empty())
    {
        pq.pop();
    }
}
edge rec[1000005];
int main ()
{
#ifdef yyhao
    freopen("invite.in","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
int ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    scanf("%lld%lld",&n,&m);
    //cout<<n<<" "<<m<<endl;

    //cout<<n<<m<<endl;
    ll t1,t2,ww;
    init();
    rep(i,1,m)
    {
       // cout<<i<<endl;
        scanf("%lld %lld %lld",&rec[i].s,&rec[i].t,&rec[i].w);
        M[rec[i].s].push_back(pa(i,rec[i].t,rec[i].w));
        //M[t2].push_back(make_pair(t1,w));
        //cout<<'12'<<endl;
    }
   // if(ii==4)
   // {

   // }
    //cout<<"st"<<endl;
    ddi(1);
    ll ans=0;
    rep(i,2,n)
    {
       // cout<<"dis1:"<<dis[i]<<endl;
        ans+=dis[i];
    }
    //cout<<"-"<<ans<<endl;
    init();
    rep(i,1,m)
    {
        M[rec[i].t].push_back(pa(i,rec[i].s,rec[i].w));
        //M[t2].push_back(make_pair(t1,w));
    }
    ddi(2);
    rep(i,2,n)
        ans+=dis[i];

    cout<<ans;
    if(ii!=t)
        cout<<endl;


#ifdef use_t
}
#endif // use_t
    return 0;
}
