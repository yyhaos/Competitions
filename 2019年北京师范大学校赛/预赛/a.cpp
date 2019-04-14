//Problem Web:http://39.97.97.11/problem.php?cid=1003&pid=0
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
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
ll a[100005];
ll t,n,m;
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

    while(scanf("%lld%lld",&n,&m))
    {
        if(n==0 && m==0 )
            break;
        rep(i,0,n-1)
        scanf("%lld",&a[i]);
        sort(a,a+n);
        ll sum=0;
        int f=1;
        rep(i,0,n-1)
        {
            if(sum+a[i]>m)
            {
                cout<<i<<endl;
                f=0;
                break;
            }
            sum+=a[i];
        }
        if(f)
            cout<<n<<endl;
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}
