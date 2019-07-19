//Problem Web:
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


ll a[100005];
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
ll n;
    cin>>n;

    //ll a;
    //ll ta=1;



    ll tq=1,tp=1;
   ll tag=-1;

    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]%2==0)
            tag=1;
    }

    ll fc=1e9+6;
    int da=0;
    ll ta=1;
    for(int i=0;i<n;i++)
    {
        //cout<<ta<<" "<<a[i]<<endl;
        if((fc+1)/a[i]<=ta)
            da=1;
        ta=ta*a[i];
    }
    if(da==0)
    {
        ta--;

        printf("%lld/%lld",  (ksm(2,ta)+tag)*ksm(3,q-2)%q ,ksm(2,ta));
    }
    else
    {
        ta=1;
        for(int i=0;i<n;i++)
        {
            a[i]=a[i]%(q-1);
            ta=(ta*a[i])%(q-1);

        }
        ta--;
        ta=(ta+(q-1))%(q-1);
        if(ta==0)
            ta=q-1;
        printf("%lld/%lld",  (ksm(2,ta)+tag)*ksm(3,q-2)%q ,ksm(2,ta));
    }


#ifdef use_t
}
#endif // use_t
    return 0;
}
