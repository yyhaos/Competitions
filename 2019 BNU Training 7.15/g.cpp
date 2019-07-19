//Problem Web:https://codeforces.com/gym/248076/standings/friends/true
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

ll t,n,m;

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
    if(n%2==0)
    {
        cout<<"YES\n1\n";
        for(int i=0;i<n;i+=2)
        {
            cout<<"+-";
        }
        return 0;
    }
    else
    {
        if(n==1)
        {
            cout<<"NO\n";
            return 0;
        }
        else
        {
            cout<<"YES\n3\n";

        }
        cout<<"-++";
        for(int i=0;i<n-3;i+=2)
        {
            cout<<"+-";
        }
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}
