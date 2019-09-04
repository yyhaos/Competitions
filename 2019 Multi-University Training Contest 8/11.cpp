//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=855
#include<bits/stdc++.h>
#include<ext/rope> //using __gnu_cxx
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
ll a[1000005];
ll b[1000005];
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
    ll sb=0;
    ll sa=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&a[i],&b[i]);
        sb+=b[i];
        sa+=a[i];
    }
    ll ans=0;
    ll tsb=sb;
    for(int i=0;i<n;i++)
    {
        if(tsb==0)
            break;
//        cout<<sb<<" "<<b[i]<<" "<<a[i]<<" "<<ans<<endl;
        if(sb-b[i] >=0 && tsb>=0)
        {
            ans+= min(tsb,min(a[i], sb-b[i])) ;
            tsb-=min(tsb,min(a[i], sb-b[i])) ;
        }
        else
        {

        }
    }

    cout<<ans<<"\n";



#ifdef use_t
}
#endif // use_t
    return 0;
}


