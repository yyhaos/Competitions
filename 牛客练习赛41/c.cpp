//Problem Web:  https://ac.nowcoder.com/acm/contest/373/C
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

ll t,n,m;
ll A[100005];
ll fa[100005];
ll fi(ll a)
{
    if(fa[a]==a)
        return a;
    else
    {
        return fa[a]=fi(fa[a]);
    }
}
ll un(ll a,ll b)
{

    if(fi(a)==fi(b))
        return 0;
    else
    {
       // A[a]+=A[b];
        fa[fi(b)]=fi(a);
        fi(b);
        fi(a);
        return 1;
    }

}
ll v[100005];
ll ans[100005];
ll cnt=0;
ll vis[100005];
ll to[100005];
ll in[100005];
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
    cin>>n>>m;

    rep(i,1,n)
    {
        fa[i]=i;
        in[i]=0;
        //A[i]=i;
        vis[i]=0;
        ans[i]=0;
        cin>>A[i];
        //cout<<A[i]<<"+";
    }
    ll tmp;
    rep(i,1,n)
    {
        cin>>tmp;
        if(un(i,tmp))
        {
            to[i]=tmp;
            in[tmp]++;
        }
    }
    stack<ll> s;
    rep(i,1,n)
    {
        if(in[i]==0)
        {
            s.push(i);
        }
    }
    while(!s.empty())
    {
        ll tt=s.top();

        s.pop();
        ll too=to[tt];
        //cout<<tt<<"  "<<too<<" - "<<in[too]<<endl;
        if(too==tt||too ==0)
        {

            ans[cnt++]=A[tt];
            //cout<<"ans"<<ans[cnt-1]<<endl;
            continue;
        }
        A[too]+=A[tt];

        //cout<<endl<<A[too]<<"="<<A[tt]<<endl;
        if(--in[too]==0)
        {
            s.push(too);
        }
    }
   // cout<<cnt<<endl;
    sort(ans,ans+cnt);
    ll aaa=0;
    crep(i,cnt-1,max(0LL,cnt-m))
    {
        aaa+=ans[i];
    }
    cout<<aaa;

#ifdef use_t
}
#endif // use_t
    return 0;
}


