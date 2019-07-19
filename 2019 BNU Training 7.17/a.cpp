//Problem Web:https://codeforces.com/contests/248218
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

ll a[45];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("zeros.in","r",stdin);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    //cout<<ksm(2,42);
    ll x,y,M,K;
    cin>>x>>y>>M>>K;
//    cout<<x<<y<<M<<K<<endl;
    ll sum=x+y;
    mem(a,0);
    for(int i=0;i<x;i++)
    {
        a[sum-i-1]=1;
    }

    ll fa=0;
//    cout<<a[sum-1]<<endl;
//for(int i=0;i<sum;i++)
//{
//    cout<<a[i]<<" ";
//}
//cout<<endl;
    if(sum==1)
    {
        if(1%M >= K)
            cout<<"1\n";
        else
            cout<<"0\n";
        continue;
    }
    ll cnt=0;
    ll now=0;
        for(int i=0;i<sum;i++)
        {
            now+=a[i]*ksm(2,i);
        }
//        for(int i=0;i<sum;i++)
//{
//    cout<<a[i]<<" ";
//}        cout<<now<<endl;
        if(now%M>=K)
        {
//            cout<<now<<"\n";
           cnt++;
           // break;
        }
    while(next_permutation(a,a+sum))
    {
//        for(int i=0;i<sum;i++)
//{
//    cout<<a[i]<<" ";
//}
//cout<<endl;
//        cout<<a[sum-1]<<endl;
        if(a[sum-1]==0)
            continue;
        ll now=0;
        for(int i=0;i<sum;i++)
        {
            now+=a[i]*ksm(2,i);
        }
//        for(int i=0;i<sum;i++)
//{
//    cout<<a[i]<<" ";
//}        cout<<now<<endl;
        if(now%M>=K)
        {
//            cout<<now<<"\n";
           cnt++;
           // break;
        }
    }
    cout<<cnt<<"\n";







#ifdef use_t
}
#endif // use_t
    return 0;
}
