//Problem Web:https://vjudge.net/contest/330734#problem/A
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
//#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 10000000000LL;
const ll maxn=3e6;
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



ll sum[10000005];
vector<ll> M[105];
ll cnt=0;
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
freopen("digits.in","r",stdin);
freopen("digits.out","w",stdout);

#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
cin>>n;
    for(int i=1;i<=maxn;i++)
    {
        ll tsum=0;
        ll ti=i;
        while(ti)
        {
            tsum+=ti%10;
            ti/=10;
        }
        sum[i]=tsum;
    }
//    for(int i=33;i<=maxn;i*=10)
//    {
//
//        printf("%d\n",sum[i]);
//    }
    sum[0]=0;
    for(int i=1;i<=maxn;i++)
    {
        M[sum[i]].push_back(i);
    }


    for(int i=1;i<105;i++)
    {
        sort(M[i].begin(),M[i].end());
    }
    ll ans=INF;
    for(int i=1;i<105;i++)
    {
        ll si=M[i].size();
        if(si<n)
            continue;
        else
        {
            ll tans=0;
            for(int j=0;j<n;j++)
            {
                tans+=M[i][j];
            }
            ans=min(ans,tans);
        }
    }
    printf("%d",ans);






#ifdef use_t
}
#endif // use_t
    return 0;
}


