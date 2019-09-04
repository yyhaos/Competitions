//Problem Web:https://vjudge.net/contest/315213#problem/D
//#include<bits/stdc++.h>
//#include<ext/rope>
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
//const ll q=1e9+7;
//ll ksm(ll a,ll b)
//{
//    ll ans=1LL;
//    while(b>0)
//    {
//        if(b&1LL)
//            ans=ans*a%q;
//        a=a*a%q;
//        b/=2LL;
//    }
//    return ans;
//}

ll t,n,m;
ll mget(ll shi,ll b)
{
    ll ans=0;
    ll tt=1;
    while (shi)
    {
        ans+=shi%10 * tt;
        if(shi%10 >=b)
        {
            ans=-1000;
            break;
        }
    tt*=b;
        shi/=10;
    }
    return ans;
}
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
ll p,q,r;
    cin>>p>>q>>r;
//    ll sheng=;
    ll ans=0;
    for(ll i=2;i<=16;i++)
    {
//        cout<<mget(p,i)<<" "<<mget(q,i)<<" == "<<mget(r,i)<<endl;
        if(mget(p,i)<0 || mget(q,i)<0 ||mget(r,i)<0)
            continue;
        if(mget(p,i)*mget(q,i)==mget(r,i))
        {
            ans=i;
            break;
        }
    }
    cout<<ans<<"\n";




#ifdef use_t
}
#endif // use_t
    return 0;
}

