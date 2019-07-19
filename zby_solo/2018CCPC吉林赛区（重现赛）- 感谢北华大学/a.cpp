//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=867
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
ll ty[1000500];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
    for(int i=1;i<=1000000;i++)
    {
        ty[i]=ksm(i+1,2)-1;
    }
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    cin>>n;
//    ll tmp=0;
//    for(int i=1;i<=n;i++)
//    {
//        tmp+=n/i;
//    }
//    cout<<tmp<<" "<<tmp%2<<endl;
//
    ll lo=lower_bound(ty+1,ty+1+1000000,n)-ty;
//
//    cout<<lo<<endl;

    if(lo%2)
    {
        cout<<"Case "<<ii<<": odd\n";
    }
    else
        cout<<"Case "<<ii<<": even\n";
//    if(tmp%2)
//    {
//        cout<<"odd\n";
//    }
//    else
//        cout<<"even\n";





#ifdef use_t
}
#endif // use_t
    return 0;
}
