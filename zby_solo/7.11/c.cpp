//Problem Web:https://codeforces.com/contests/102152
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
#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1000;
const ll q=1e18+7;
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
    cin>>n>>m;
//    for(int i=1;i<=17;i++)
//    {
//        for(int j=1;j<=17;j++)
//        {
//            ll n=i,m=j;
//    if(__gcd(m,n)!=1)
//        continue;
//    ll a=ksm(5,n)+ksm(7,n);
//    ll b=ksm(5,m)+ksm(7,m);
    //cout<<n<<" "<<m<<" :\t"<<__gcd(a,b)<<" ";//<<"\t"<<a<<" "<<b<<endl;
    if(n%2==0 || m%2==0)
        cout<<2<<'\n';
    else
        cout<<12<<'\n';
//        }
//    }




#ifdef use_t
}
#endif // use_t
    return 0;
}

