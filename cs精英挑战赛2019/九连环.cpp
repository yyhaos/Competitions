//Problem Web:https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=3272
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

ll n,m;
ll t[10];
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
    //mem(t,0);
    cin>>n;
    ll tt;
    rep(i,1,9)
    t[i]=1;
    rep(i,1,n)
    {
        scanf("%lld",&tt);
        t[tt]=0;
    }
    ll th=0;
    for(int i=9;i>=1;i--)
    {
        if(i<=8)
        {
            t[i]=t[i+1]^t[i];
        }
        if(t[i]==1)
            th+=ksm(2,i-1);
    }

    cout<<th<<endl;
#ifdef use_t
}
#endif // use_t
    return 0;
}
