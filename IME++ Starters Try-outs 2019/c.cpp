//Problem Web:https://codeforces.com/gym/225575
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
const ll INF = 1e9+2;
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
ll sum;
ll s[20];
ll x,d;
ll cnt=0;


int main ()
{
//    mem(h,0);
//    mem(used,0);
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
    cin>>n>>x>>d;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    cnt=0;
    //cout<<ksm(2,15);
    sum=ksm(2,n);
   // cout<<sum;
   // cout<<sum;
   ll mii,maa;
   ll tmp=0;
   // cout<<sum;
    for(ll i=1;i<=sum-1;i++)
    {
        mii=INF;
        maa=0;
        tmp=0;
        for(ll j=0;j<n;j++)
        {
            if((1LL<<j)&i)
            {
                mii=min(mii,s[j]);
                maa=max(maa,s[j]);
                 tmp+=s[j];
            }

        }
        if(tmp>=x && maa-mii<=d)
        {
            //cout<<i<<endl;
            cnt++;
        }
        //cout<<i<<" "<<w[i]<<endl;
    }
   // dfs(0,INF,0,0);
    cout<<cnt<<endl;
    //ll sum=0;
//    for(int i=1;i<=10;i++)
//    {
//        sum+=S(i,10);
//    }
//    cout<<sum;

#ifdef use_t
}
#endif // use_t
    return 0;
}



