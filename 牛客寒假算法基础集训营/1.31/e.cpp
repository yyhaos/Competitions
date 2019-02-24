//Problem Web:  https://ac.nowcoder.com/acm/contest/331/E
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
ll x[100005],y[100005];
ll vis[100005];
stack <ll > ss;
bool judge(int th)
{
    while(!ss.empty())
        ss.pop();
    mem(vis,0);
    rep(i,1,th)
    {
        vis[x[i]]=x[i];
        vis[y[i]]=-x[i];
    }
    rep(i,1,n)
    {
        if(vis[i]>0)
        {
            ss.push(vis[i]);
        }
        else if(vis[i]<0)
        {
            ll top=ss.top();
            ss.pop();
            //cout<<th<<":"<<top<<"-aaa"<<i<<endl;
            if(top!=-vis[i])
            {
                return false;
            }
        }
    }
    return true;

}
void check(ll & ans)
{
    ll l=1,r=m,mid;
    while(r>=l)
    {
        mid=(r+l)/2;


        bool flag=judge(mid);
        if(!flag)
            r=mid-1;
        else
            l=mid+1;
       // cout<<r<<"-"<<l<<"-"<<mid<<endl;
    }
    ans=l;
    if(ans>m)
        ans=-1;
    return ;
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

    cin>>n>>m;
    ll ans=-1;
    rep(i,1,m)
    {
        scanf("%lld%lld",x+i,y+i);
        if(x[i]>y[i])
            swap(x[i],y[i]);
    }
    check(ans);
    cout<<ans<<endl;




#ifdef use_t
}
#endif // use_t
    return 0;
}
