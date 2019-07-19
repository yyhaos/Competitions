//Problem Web:  https://codeforces.com/gym/225575/problem/E
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
struct sta
{
    ll x,y,w;
    sta(ll xx,ll yy,ll ww)
    {
        x=xx;
        y=yy;
        w=ww;
    }
    friend bool operator <(sta a,sta b)
    {
        return a.w<b.w;
    }
};
priority_queue<sta > pq;
ll used[2005];
ll t,n,m;
ll M[2005][2005];
void push(ll s)
{
    rep(i,1,n)
    {
        if(s==i || used[i]==1)
            continue;
        pq.push(sta(s,i,M[s][i]));
    }
    used[s]=1;
    return ;
}
ll fa[2005];
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
    ll tmp;
    rep(i,2,n)
    {
        rep(j,1,i-1)
        {
            cin>>tmp;
            M[i][j]=M[j][i]=tmp;
           // cout<<M[i][j]<<'\t';
        }
       // cout<<endl;
    }
    mem(used,0);
    ll ans=0;
    push(1);
    while(!pq.empty())
    {
        sta top=pq.top();
        pq.pop();
        if(used[top.y]==1)
            continue;
        else
        {
            push(top.y);
            fa[top.y]=top.x;
            ans+=top.w;
        }
    }
    cout<<ans<<endl;
    rep(i,2,n)
    {
        cout<<fa[i]<<endl;
    }


#ifdef use_t
}
#endif // use_t
    return 0;
}
