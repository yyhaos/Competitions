//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=867
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
ll dp[5000000];
ll si[22];
vector < ll> bag[22];
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

//    cout<<ksm(2,21);
ll g,b,s;
    while(cin>>g>>b>>s)
    {
        if(g==0 && b==0 && s==0)
            return 0;
        for(int i=0;i<22;i++)
        {
            bag[i].clear();
        }
        for(int i=0;i<b;i++)
        {
            cin>>si[i];
            ll tmp;
            for(int j=0;j<si[i];j++)
            {
                scanf("%lld",&tmp);
                bag[i].push_back(tmp);
            }
        }

//        for(int i=0;i<b;i++)
//        {
//            for(int j=0;j<si[i];j++)
//            {
//                cout<<bag[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        ll sum=(1<<b)-1;
        for(int i=0;i<=sum;i++)
        {
            dp[i]=-INF;
        }

    }


#ifdef use_t
}
#endif // use_t
    return 0;
}
