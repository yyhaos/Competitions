//Problem Web:  https://ac.nowcoder.com/acm/contest/331/D
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
const ll maxn=100000;
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
struct pos
{
    ll now,th;
    pos(ll n=0,ll t=0)
    {
        now=n;
        th=t;
    }
};
ll t,n,m;
ll k,a,b;
ll tong[2000][2002];
ll used[maxn+5];
ll ma[500][500];
ll pos[1000];
ll co(const ll i,const ll j)
{
    if(i>j)
        return INF;
    if(i==j)
        return 0;
    ll cha=j-i;
    ll ans=0;
    while(cha>0)
    {
      //  cout<<cha<<" "<<lowbit(cha)<<endl;
        ans++;
        cha=cha-lowbit(cha);
    }
    return ans;
}
ll vis[1000];
ll dis[1000];
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
//cout<<co(452,1000000000);
    mem(used,0);
    cin>>n>>k;
    rep(i,1,k)
    {
        cin>>tong[i][0]>>tong[i][1];
    }
    ll cnt=0;
    pos[cnt++]=1LL;
    rep(i,1,k)
    {
        pos[cnt++]=tong[i][0];
        pos[cnt++]=tong[i][1];
    }
    pos[cnt++]=n;
    rep(i,0,cnt-1)
    {
        rep(j,0,cnt-1)
        {
            ma[i][j]=co(pos[i],pos[j]);
        }
    }
    //cout<<cnt;
   // cout<<"asd"<<endl;
    rep(i,1,k)
    {
        if(tong[i][0]<tong[i][1])
        {
            ma[2*i-1][2*i]=1;
        }
        else if(tong[i][0]>tong[i][1])
        {
            ma[i*2][2*i-1]=1;
        }
        else
        {
            ma[i*2][2*i-1]=0;
            ma[i*2-1][2*i]=0;
        }
    }
  //  cout<<dis[0]<<dis[1];
    dis[0]=0;
//    rep(i,0,cnt-1)
//        cout<<pos[i]<<"\t";
//    cout<<endl;
//    rep(i,0,cnt-1)
//    {
//        rep(j,0,cnt-1)
//        {
//            cout<<ma[i][j]<<"\t";
//        }
//        cout<<"\n";
//    }
    mem(vis,0);
    rep(i,1,cnt-1)
        dis[i]=INF;
//cout<<ma[0][1];
    rep(ii,1,cnt)
    {

        ll minn=0,mindis=INF;
        rep(i,0,cnt-1)
        {
            if(vis[i]==0)
            {
                if(mindis>dis[i])
                {
                    minn=i;
                    mindis=dis[i];
                }
            }
        }
      //  cout<<minn<<endl;
        vis[minn]=1;
        ll di=dis[minn];
        rep(i,0,cnt-1)
        {
            if(vis[i]==0)
                dis[i]=min(dis[i],dis[minn]+ma[minn][i]);
        }
    }
    cout<<dis[cnt-1];
#ifdef use_t
}
#endif // use_t
    return 0;
}
