//Problem Web:https://codeforces.com/gym/101982/attachments
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
const ll INF = 100000000;
const ll maxn=1000;
const ll q=1e9+9;
ll ksm(ll a,ll b,ll qq=q)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a%qq;
        a=a*a%qq;
        b/=2LL;
    }
    return ans;
}

ll t,n,m;
ll cnt(ll x)
{
    ll ans=0;
    while(x)
    {
        if(x&1)
            ans++;
        x/=2;
    }
    return ans;
}
ll bruce(ll k,ll b)
{
    ll ans=0;
    ll maxn=ksm(2,b)-1;
    for(ll tk=1;tk*k <= maxn ;tk++)
    {
        ans+=cnt(tk*k);
    }
    return ans;
}
ll ni(ll x)
{
    return ksm(x,q-2);
}
ll dp[130][1005];
ll dp2[130][1005];
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
ll k,b;
    //cin>>k>>b;


//
//    cout<<bruce(1,4)<<endl;
//    cout<<bruce(10,5)<<endl;
//    cout<<bruce(100,7)<<endl;
    cin>>k>>b;
//    cout<<"zong: "<< b* ksm(2,b-1) %q<<endl;
    if(k==1)
    {
        cout<< b* ksm(2,b-1) %q;
    }
    else
    {
        mem(dp,0);
        dp[0][0]=0;

        for(int tb=1;tb<=b;tb++)
        {
            for(int tk=0;tk<k;tk++)
            {
                if(tb==1)
                {
                    dp[1][1]=1;
                    dp[1][0]=1;
                    continue;
                }
                ll pre=(tk - ksm(2,tb-1,k) + k)%k;
                dp[tb][tk]= (dp[tb-1][tk] + dp[tb-1][pre])%q;
            }
        }
//       for(int tb=1;tb<=b;tb++)
//        {
//            for(int tk=0;tk<k;tk++)
//            {
//                cout<<dp[tb][tk]<<" ";
//            }
//            cout<<endl;
//        }

        mem(dp2,0);
        for(int tb=1;tb<=b;tb++)
        {
            for(int tk=0;tk<k;tk++)
            {
                if(tb==1)
                {
                    dp2[1][1]=1;
                    continue;

                }
                ll pre=(tk - ksm(2,tb-1,k) + k)%k;
                dp2[tb][tk] =(dp[tb-1][pre]+dp2[tb-1][pre] + dp2[tb-1][tk] )%q;
            }
        }

        ll ans=dp2[b][0];

        cout<<ans<<endl;
    }
//    cout<<bruce(3,28)<<endl;


#ifdef use_t
}
#endif // use_t
    return 0;
}


