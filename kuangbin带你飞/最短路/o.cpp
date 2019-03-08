//Problem Web:  https://vjudge.net/contest/239087#problem/O
//#include<bits/stdc++.h>
//#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
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
//const ll PI=acos(-1.0);
const ll eps=1e-8;
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
vector<pr<ll,ll>> M[205];
ll cu(ll a)
{
  //  if(a<0)
  //      a=-a;
    return a*a*a;
}
ll bu[205];
bool cir[205];
ll cnt[205];
ll dis[205];
ll vis[205];
void dfs(ll n)
{
    if(cir[n]==1)
        return ;
    cir[n]=1;
    for(int i=0;i<M[n].size();i++)
    {
        dfs(M[n][i].first);
    }
}

void SPFA()
{
    mem(vis,0);
    mem(cir,0);
    mem(cnt,0);
    mem(dis,1);
    dis[1]=0;
    vis[1]=1;
    queue<ll>q;
    q.push(1);
    while(!q.empty())
    {
        ll fr=q.front();
        q.pop();
      //  cout<<fr<<endl;
        vis[fr]=0;
        for(int i=0;i<M[fr].size();i++)
        {
            ll v=M[fr][i].first;
            if(cir[v])
                continue;
            ll cost=M[fr][i].second;
            //cout<<"to"<<v<<endl;
            if(dis[v]>dis[fr]+cost)
            {
                dis[v]=dis[fr]+cost;
                if(vis[v]==0)
                {
                    q.push(v);
                    vis[v]=1;
                }
                cnt[v]++;
                if(cnt[v]>=n)
                {
                    dfs(v);
                }
            }
        }
    }
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
    cin>>n;
    rep(i,1,n)
    {
        M[i].clear();
    }
    rep(i,1,n)
    {
        scanf("%lld",bu+i);
    }
    cin>>m;
    ll u,v;

    //cout<<x[1][1];
    rep(i,1,m)
    {
        scanf("%lld%lld",&u,&v);
        M[u].push_back(mp(v,cu(bu[v]-bu[u])));
    }
    SPFA();
//    rep(i,1,n)
//    {
//        cout<<dis[i]<<" ";
//    }
printf("Case %lld:\n",ii);
    //cout<<"Case "<<ii<<":\n";
    ll s;
    scanf("%lld",&s);
    ll tmp;
    while(s--)
    {
        scanf("%lld",&tmp);
        if(1LL==tmp || dis[tmp]<3LL || dis[tmp]>99999999LL || cir[tmp])
        {
            printf("?");

        }
        else
        {
            printf("%lld",dis[tmp]);
        }
      //  if(s!=0 || ii!=t)
      //  {
            printf("\n");
      //  }
    }


#ifdef use_t
}
#endif // use_t
    return 0;
}
