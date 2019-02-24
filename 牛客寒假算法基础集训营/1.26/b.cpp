//Problem Web:  https://ac.nowcoder.com/acm/contest/329/B
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
ll t,n,m;
struct road
{
    ll t,c;
    road (ll tt, ll cc)
    {
        t=tt;
        c=cc;
    }
};
struct DAG
{
    vector<road> M[100005];
    ll ru[100005];
    ll dis[100005];
    void Init()
    {
        mem(ru,0);
        rep(i,1,n)
        M[i].clear();
    }
    void add(ll s,ll t,ll c)
    {
        //if(t==1)
        //    return ;
        M[s].push_back(road(t,c));
        ru[t]++;
    }
    ll solve()
    {
        mem(dis,0x3f);
        dis[1]=0;
        //ru[s]=0;
        queue<ll> qq;
        rep(i,1,n)
        {
            if(ru[i]==0)
                qq.push(i);
        }
        while(!qq.empty())
        {
            ll fro=qq.front();
            qq.pop();
           // cout<<fro<<endl;
                for(ll j=0;j<M[fro].size();j++)
                {
                    dis[M[fro][j].t]=min(dis[M[fro][j].t],dis[fro]+M[fro][j].c);
                    ru[M[fro][j].t]--;
                    if(ru[M[fro][j].t]==0)
                        qq.push(M[fro][j].t);
                }

        }
        return max(0LL,dis[n]);
    }
}m1,m2;

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
ll s,v,c,cnz,jff;
    cin>>n>>m;
    m1.Init();
    m2.Init();
    rep(i,1,m)
    {
        scanf("%lld%lld%lld%lld%lld",&s,&v,&c,&cnz,&jff);
        m1.add(s,v,c-cnz);
        m2.add(s,v,c-jff);
    }
    ll s1,s2;
    s1=m1.solve();
    s2=m2.solve();
    //cout<<s1<<"-"<<s2<<endl;
    if(s1<s2)
    {
        cout<<"cnznb!!!\n";//<<endl;
        cout<<s2-s1<<'\n';
    }
    else if(s1>s2)
    {
        cout<<"rip!!!\n";
        cout<<s1-s2<<'\n';
    }
    else
        cout<<"oof!!!\n";
#ifdef use_t
}
#endif // use_t
    return 0;
}
