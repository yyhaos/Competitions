//Problem Web:  https://ac.nowcoder.com/acm/contest/330/F
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
ll ru[200005],a[200005],b[200005];

bool ok(ll th)
{
    mem(ru,0);
    vector <ll> M[100005];
    rep(i,1,th)
    {
        M[a[i]].push_back(b[i]);
        ru[b[i]]++;
    }
    ll cnt=0;
    queue<ll>q;
    rep(i,1,n)
    {
        if(ru[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        ll top=q.front();
        q.pop();
        //cout<<top<<"-"<<M[top].size()-1LL<<endl;
        cnt++;

        rep(i,1,M[top].size())
        {
            //cout<<":"<<M[top][i]<<" "<<ru[M[top][i]]<<endl;
            ru[M[top][i-1]]--;
            if(ru[M[top][i-1]]==0)
                q.push(M[top][i-1]);
        }
        //cout<<"next"<<endl;
    }
    return cnt==n;
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
    rep(i,1,m)
    {
        scanf("%lld%lld",a+i,b+i);
    }
    ll l=1,r=m,mid,ans;
    while(l<=r)
    {
     //   cout<<l<<r<<endl;
        mid=(l+r)/2LL;
        if(ok(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else
            r=mid-1;
    }

    rep(i,1,ans)
    cout<<"Yes"<<endl;
    rep(i,ans+1,m)
    cout<<"No"<<endl;
#ifdef use_t
}
#endif // use_t
    return 0;
}
