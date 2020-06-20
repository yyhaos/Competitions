//Problem Web:https://ac.nowcoder.com/acm/contest/6013
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


ll f2(ll x){

    return (ll)sqrt(x);
}
ll f(ll x){
    if(x==0)return 0;
    if(x==1){
        return 1;
    }
//    printf("test2 %lld\n",x);
    return (f2(x)+f2((x)/2));
}
int main ()
{
ll t,n,m;
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

    ll a,b;
    scanf("%lld%lld",&a,&b);
//    cout<<a<<" "<<b<<"s"<<endl;
    if(a>b)
        printf("1\n");
    else
    printf("%lld\n",(f(b)+f(a-1)) %2);

//    printf("test %lld\n",f2(b));


#ifdef use_t
}
#endif // use_t
    return 0;
}



