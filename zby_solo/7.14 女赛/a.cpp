//Problem Web:http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1001&cid=866
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
    ll a;
    double ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(ans<100)
        {
            ans+=a;
        }
        else if(ans<150)
        {
            ans+=a*0.8;
        }
        else if(ans<400)
        {
            ans+=a*0.5;
        }
        else ans+=a;

    }
    printf("%.2f\n",ans);





#ifdef use_t
}
#endif // use_t
    return 0;
}
