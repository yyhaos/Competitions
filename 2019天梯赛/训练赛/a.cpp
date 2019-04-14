//Problem Web:  http://www.bnuoj.com/contest_show.php?cid=9478#problem/A
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
ll a[15][15];
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

    mem(a,0);
    a[1][1]=1;
    for(int i=2;i<=13;i++)
    {
        for(int j=1;j<=i;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    cin>>n;
    for(int i=1;i<=n+1;i++)
    {
        cout<<a[n+1][i];
        if(i<=n)
            cout<<" ";
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}
