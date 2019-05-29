//Problem Web:https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=3247
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
unsigned int nextInt(unsigned int x){
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

void initData(unsigned int *a, int n, int k, unsigned int seed){
    for (int i = 0; i < n; ++i) {
        seed = nextInt(seed);
        a[i] = seed >> (32 - k);
    }
}
ll t,n,m;
unsigned a[67108865];
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
ll k,seed;
    cin>>n>>k>>seed;
    initData(a,n,k,seed);

    sort(a,a+n);
//    rep(i,0,n-1)
//        cout<<a[i]<<" ";
    unsigned ans=0;
    rep(i,1,n-1)
    {
        if(a[i]>a[i-1])
        {
            if(ans<a[i]-a[i-1])
                ans=a[i]-a[i-1];
        }
        else
            if(ans<a[i-1]-a[i])
                ans=a[i-1]-a[i];
      //  cout<<ans<<endl;
    }
    printf("%u",ans);

#ifdef use_t
}
#endif // use_t
    return 0;
}

