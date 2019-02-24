//Problem Web:  https://ac.nowcoder.com/acm/contest/331/H
//interesting:  this code is either ac or tle, depends on your luck
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
ll a[5005];
struct data
{
    ll a,th;
    friend bool operator < (data x,data y)
    {
        if(x.a!=y.a)
        return x.a>y.a;
        else return x.th>y.th;
    }
}d[5005];
priority_queue<ll, vector<ll>, greater<ll>> pd;
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
ll sum=0;
    ll k;
    cin>>n>>k;
    rep(i,1,n)
    {
        scanf("%lld",&a[i]);
        pd.push(a[i]);
        sum+=a[i];
    }
//    rep(i,0,n)
//    {
//        cout<<i<<" : "<<d[i].a<<" "<<d[i].th<<endl;
//    }
    ll ma=0,aa=0;
    while(!pd.empty())
    {
        if(ma+pd.top()<=k)
        ma+=pd.top(),aa++;
        pd.pop();
    }
    printf("%lld\n",aa);

    ll ans[5005];
    ll minn=0,cnt=0;
    rep(j,1,n)
    {
        d[j].a=a[j];
            d[j].th=j;
    }
    rep(i,1,n)
    {
        if(a[i]>k)
        {
            ans[i]=1;
            continue;
        }
        minn=0,cnt=0;
        rep(j,i+1,n)
        {
            pd.push(a[j]);
            //scanf("%lld",&a[i]);
        }
        while(!pd.empty())
        {
            if(pd.top()+minn<=k-a[i])
            {
                cnt++;
                minn+=pd.top();
            }
            pd.pop();
        }

        if(cnt>=aa-1)
        {
            ans[i]=0,aa--,k-=a[i];
        }
        else
            ans[i]=1;
    }

    rep(i,1,n)
    printf("%lld",ans[i]);



#ifdef use_t
}
#endif // use_t
    return 0;
}//tle or ac
