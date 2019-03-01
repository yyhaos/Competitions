//Problem Web:  https://ac.nowcoder.com/acm/contest/373/B
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
const ll q=1e8+7;
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
const int qq=199800;
ll dp[3][2*199800+5];
ll a[305];
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
    mem(dp,0);
    cin>>n;
    rep(i,1,n)
    cin>>a[i];
    dp[0][0+qq]=1;
    rep(i,1,n)
    {
        rep(j,0,2*qq+3LL)
        {
            if(2*qq-j>=0 && 2*qq-j<=2*qq)
                dp[1][2*qq-j]+=dp[0][j];
            if(j+a[i]>=0 && j+a[i]<=2*qq)
                dp[1][j+a[i]]+=dp[0][j];
        }
        //cout<<"2: "<<dp[1][-666+qq]<<endl;
        dp[1][666+qq]=0;
        rep(j,0,2*qq)
        {
            dp[0][j]=dp[1][j]%q;
            dp[1][j]=0;
        }
    }
    cout<<dp[0][-666+qq];



#ifdef use_t
}
#endif // use_t
    return 0;
}
