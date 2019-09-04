//Problem Web:https://ac.nowcoder.com/acm/contest/883#countdown
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
//const ll maxn=1000;
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
string str;
const ll maxn=1e5;
ll off=maxn;
ll dp[2*maxn+5];
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
    cin>>n;
    cin>>str;
//    cout<<str<<endl;
ll n1=0,n0=0;
    for(int i=0;i<n;i++)
    {
        dp[i]=dp[off+i]=0;
    }
    ll pre=0;
    dp[0+off]=0;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
//        ll ti=i-1;
        char now=str[i-1];
//        cout<<now;
        if(now=='0')
        {
            n0++;
            pre--;
        }
        else
        {
            n1++;
            pre++;
        }
        if(dp[pre+off] || pre==0)
        {
//            cout<<"ru"<<dp[pre+off]<<endl;
            if(i-dp[pre+off]>ans)
                ans=i-dp[pre+off];
        }
        else
            dp[pre+off]=i;
//        cout<<i<<" "<<pre<<" "<<ans<<endl;
    }

    cout<<ans<<" "<<2*min(n0,n1)<<endl;


#ifdef use_t
}
#endif // use_t
    return 0;
}



