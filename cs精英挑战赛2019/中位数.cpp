//Problem Web:
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
ll a[6000005];
priority_queue<ll > l;
priority_queue<ll ,vector<ll>,greater<ll>> r;

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
    scanf("%lld",&n);
    for(int i=1;i<=2*n-1;i++)
    {
        scanf("%lld",a+i);
    }
    printf("%lld\n",a[1]);
     if(n==1)
        return 0;
    ll mid;
    ll lc,rc;
    lc=rc=1;
    sort(a+1,a+4);
    l.push(a[1]);
    r.push(a[3]);
    mid=a[2];
    ll lt,rt;
    printf("%lld\n",a[2]);
    rep(i,4,2*n-1)
    {
       // cout<<"i"<<i<<endl;
        lt=l.top();
        rt=r.top();
        if(a[i] <=mid )
        {
            l.push(a[i]);
            lc++;
        }
        else
        {
            r.push(a[i]);
            rc++;
        }
        if(lc-rc>=2)
        {
       //     cout<<"youyi"<<endl;
            r.push(mid);
            mid=l.top();
            l.pop();
            lc--;
            rc++;
        }
        if(rc-lc>=2)
        {
       //     cout<<"zuoyi"<<endl;
            l.push(mid);
            mid=r.top();
            r.pop();
            rc--;
            lc++;
        }
        if(i%2==1)
        {
    printf("%lld\n",mid);
        }
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}
