//Problem Web:http://39.97.97.11/problem.php?cid=1002&pid=2
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
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
int a[105];
double test(ll n)
{
    ll t=1;
    for(ll i=0;i<n;i++)
    {
        t*=i+1;
        a[i]=i+1;
    }
    double sum=0;
    rep(i,1,t){
next_permutation(a,a+n);
        for(int i=0;i<n-1;i++)
        {
            sum+=abs(a[i]-a[i+1]);
        }
    }
    return sum/t;
}
double aa(ll n){
    return (n-1)*(5.0/3+n*2.0/3.0+1)/2;
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
    cin>>n;
    //for(n=2;n<=15;n++)
    printf("%.10f\n",aa(n)-n+1);





#ifdef use_t
}
#endif // use_t
    return 0;
}

