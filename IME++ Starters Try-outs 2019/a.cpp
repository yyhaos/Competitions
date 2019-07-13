
//Problem Web:https://codeforces.com/gym/225575
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
vector < ll > M[20005];
ll dis[20005];

void dfs(ll st)
{

    for(int i=1;i<=n;i++)
        dis[i]=-1;
    queue<pr<ll,ll>> qq;
    qq.push(mp(st,0));
    while(!qq.empty())
    {
        st=qq.front().first;
        ll th=qq.front().second;

//pair <ll,ll> top=qq.top();
        qq.pop();
        if(dis[st]==-1)
            dis[st]=th;
        else
            dis[st]=min(dis[st],th);
//cout<<st<<" "<<th<<endl;
        int si=M[st].size();
        for(int i=0;i<si;i++)
        {
            if(dis[M[st][i]]==-1)
            {
                qq.push(mp(M[st][i],th+1));
            }
        }
    }

}
void geth(ll & x, ll &ii)
{
    x=0;
    for(int i=1;i<=n;i++)
    {
        x=max(x,dis[i]);
        if(x==dis[i])
            ii=i;
        if(dis[i]==-1)
        {
           x=INF;
           break;
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
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    ll u,v;
    cin>>n>>m;
    while(m--)
    {
        scanf("%lld%lld",&u,&v);
        M[u].push_back(v);
        M[v].push_back(u);
       // cout<<u<<v<<endl;
    }
    for(int i=0;i<=n;i++)
    {
        dis[i]=-1;
    }


//    for(int i=1;i<=n;i++)
//    {
//        cout<<dis[i]<<" ";
//    }
    ll mi,x;
    ll ans=0;

    for(int st=1;st<=n;st++)
    {
        dfs(st);
        geth(x,mi);

        ans=max(ans,x);
        if(ans==INF)
        {
            cout<<"=[";
            return 0;
        }
    }


        cout<<"=] "<<ans;




#ifdef use_t
}
#endif // use_t
    return 0;
}


