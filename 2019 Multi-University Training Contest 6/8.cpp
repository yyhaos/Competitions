//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=853
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
ll f(ll n,ll m)
{
    for(ll x=n+1;x;x++)
    {
        if(__gcd(x,n)==1)
        {
            m--;
            if(m==0)
                return x;
        }
    }
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
//cout<<( (16-4) | 6 )<<" "<< (16|6 )- (4|6)<<endl;
#ifdef use_t
ll ii=1;
cin>>t;
ll k;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
ll fa=0;
    cin>>k>>m;
    for(ll n=1;n;n++)
    {
//        cout<<"n:"<<n<<" "<<f(n,m)-n<<" "<<(k^n)<<endl;
        if( (f(n,m) - n) == (k ^ n))
        {
            fa=1;
            cout<<n<<"\n";
            break;
        }
        if(n>1e5)
            break;
    }
    if(fa==0)
    cout<<"-1\n";




#ifdef use_t
}
#endif // use_t
    return 0;
}

