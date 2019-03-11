//Problem Web:  http://www.bnuoj.com/contest_show.php?cid=9478#problem/B
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

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
ll t1,t2,t3,t4,t5,t6;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    scanf("%lld/%lld/%lld-%lld:%lld:%lld",&t1,&t2,&t3,&t4,&t5,&t6);
   // cout<<t1<<t2<<t3<<t4<<t5<<t6<<endl;
    int flag=1;
    if( t4<12)
    {
        flag=1;
        if(t4==0)
        {
            t4=12;
        }
    }
    else
    {
        flag=0;
        if(t4>=13)
            t4-=12;
    }
    printf("%02lld/%02lld/%04lld-%02lld:%02lld:%02lld",t2,t3,t1,t4,t5,t6);
    if(flag)
        cout<<"am";
    else
        cout<<"pm";

    cout<<endl;




#ifdef use_t
}
#endif // use_t
    return 0;
}

