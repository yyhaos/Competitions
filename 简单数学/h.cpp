//Problem Web:https://vjudge.net/contest/358281
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
void che(ll n)
{
    ll fa=1;
    ll tn=n;
    ll s1=0;
    while(tn)
    {
        s1+=tn%16;tn/=16;
    }
    ll s2=0;
    tn=n;
    while(tn)
    {
        s2+=tn%12;tn/=12;
    }
    tn=n;
    ll s3=0;
    while(tn)
    {
        s3+=tn%10;tn/=10;
    }
    if(s1==s2 && s2==s3 )
    {
        cout<<n<<" is a Sky Number.\n";
    }
    else cout<<n<<" is not a Sky Number.\n";
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

    while(cin>>n)
    {
        if(n==0)break;
        che(n);
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}




