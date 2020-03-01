//Problem Web:https://vjudge.net/contest/358281
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
ll a[30];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
memset(a,0,sizeof(a));
for(int i=1;i<(1<<20);i++)
{
    int ti=i;
    int cnt=0;
    int g=0;
    while(ti)
    {
        cnt++;
        g+=ti%2;
        ti/=2;
    }
//    cout<<i<<" "<<cnt<<" "<<g<<endl;
    a[cnt]+=g;
}
//for(int i=0;i<21;i++)
//{
//    cout<<i<<":"<<a[i]<<endl;
//}
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
cin>>n;
cout<<a[n]<<endl;




#ifdef use_t
}
#endif // use_t
    return 0;
}





