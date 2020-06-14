//Problem Web:
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
ll kk[10000005];
ll ni(ll x){
    return ksm(x,q-2);
}
ll C(ll n,ll m){

    return kk[n] * ni(kk[n-m]) %q * ni(kk[m])%q;
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
kk[0]=kk[1]=1;
for(int i=2;i<=2000000;i++){
    kk[i]=kk[i-1]*i%q;
}

cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    scanf("%lld%lld",&n,&m);
    if(n==1 || m==1){
        printf("1\n");
    }
    else
    printf("%lld\n", C(n+m-2,m-1) );




#ifdef use_t
}
#endif // use_t
    return 0;
}



