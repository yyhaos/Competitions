
//Problem Web:https://ac.nowcoder.com/acm/contest/884#countdown
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
//#define mp make_pair
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
ll s,e,k;
ll dis[1005][1005];
ll M[1005][1005];
struct sta
{
    ll ed,len,tk;
    sta(ll _ed=0,ll _len=0, ll _tk=0)
    {
        ed=_ed;len=_len;tk=_tk;
    }
    bool friend operator < (sta a,sta b)
    {
        if(a.tk!=b.tk)
            return a.tk<b.tk;
        return a.len>b.len;
    }
};

vector<ll > mp[10005];
void dfs(ll now)
{
    priority_queue<sta> pq;
    mem(dis,-1);
//    cout<<dis[0][0]<<endl;
    pq.push(sta(now,0,k));
    sta top;
    ll ed,tk,si,len;
    while(!pq.empty())
    {
        top=pq.top();pq.pop();
        ed=top.ed;len=top.len;tk=top.tk;
//        cout<<ed<<" "<<len<<" "<<tk<<endl;
        if(dis[ed][tk]!=-1 && dis[ed][tk]<= len)
            continue;
        dis[ed][tk]=len;
        si=mp[ed].size();
        ll nxt;
        for(int i=0;i<si;i++)
        {
            nxt=mp[ed][i];
            if(dis[nxt][tk]==-1)
            {
                pq.push(sta(nxt,len+M[ed][nxt],tk));
            }
            if(tk&&dis[nxt][tk-1]==-1)
            {
                pq.push(sta(nxt,len,tk-1));
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
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
//priority_queue<sta> test;
//for(int i=0;i<10;i++)
//{
//    for(int j=0;j<10;j++)
//    {
//        test.push(sta(1,i,j));
//    }
//}
//while(!test.empty())
//{
//    sta tt=test.top();
//    test.pop();
//    cout<<tt.tk<<" "<<tt.len<<endl;
//}
    cin>>n>>m>>s>>e>>k;
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
        M[i][j]=100000000LL;
//    cout<<n<<" "<<m<<endl;
    ll a,b,v;
    for(int i=0;i<m;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&v);
//        printf("%lld %lld %lld\n",a,b,v);
        v=min(M[a][b],v);
        M[a][b]=M[b][a]=v;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
//            cout<<M[i][j]<<' ';
            if(M[i][j]<=1000000LL)
            {
                mp[i].push_back(j);
            }
        }
//        cout<<endl;

    }

//    cout<<M[1][2];

//    mem(dis,-1);
    dfs(s);
    ll ans=1000000000LL;
    for(int i=0;i<=k;i++)
    {
        if(dis[e][i]!=-1)
        ans=min(ans,dis[e][i]);
    }
//    if(s==e)
//        ans=0;
    cout<<ans;



#ifdef use_t
}
#endif // use_t
    return 0;
}
