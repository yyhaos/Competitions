//Problem Web:https://vjudge.net/contest/288637#problem/D
//#include<bits/stdc++.h>
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


    while(cin>>n)
    {
        ll f3,f5,f7;
        f3=f5=f7=0;
        if(n%3==0)
        {
            f3=1;
        }
        if(n%5==0)
            f5=1;
        if(n%7==0)
            f7=1;
        if(f3+f5+f7==3)
        {
            cout<<"3 5 7\n";
        }
        else if(f3+f5+f7==1)
        {
            if(f3)
            cout<<"3\n";
            if(f5)
                cout<<"5\n";
            if(f7)
                cout<<"7\n";
        }
        else if(f3+f5+f7==0)
            cout<<"n\n";
        else
        {
            if(f3==0)
            {
                cout<<"5 7\n";
            }
            if(f5==0)
                cout<<"3 7\n";
            if(f7==0)
                cout<<"3 5\n";
        }
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}
