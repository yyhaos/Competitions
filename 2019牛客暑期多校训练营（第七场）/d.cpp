//Problem Web:https://ac.nowcoder.com/acm/contest/887#question
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
ll ksm(ll a,ll b,ll p)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a%p;
        a=a*a%p;
        b/=2LL;
    }
    return ans;
}

ll t,n,m;
ll wei(ll x)
{
    ll ans=0;
    while(x)
    {
        ans++;
        x/=10;
    }
    return ans;
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
ll p;
    cin>>n>>p;
    ll we=wei(p);
    if(we>n)
    {
        cout<<"T_T";
    }
    else if(we==n)
    {
        cout<<p;
    }
    else
    {
//        cout<<"we:"<<we<<endl;
        cout<<"1";
        ll now=1;
        ll pre=0;
        for(int i=n-1;i>we;i--)
        {
            now*=10;
            now%=p;
            cout<<"0";
        }
        now*=ksm(10,we,p);
        now%=p;
//        cout<<"now:"<<now<<endl;
        ll out=p-now;
        ll wo=wei(out);

        for(int i=we;i>wo;i--)
        {
            cout<<"0";
        }
        cout<<out;
//        cout<<"\n"<<(100000000000071LL%p)<<" "<<p<<endl;
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}



