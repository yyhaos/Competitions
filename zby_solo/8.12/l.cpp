
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
ll is[1005];
ll a[1005],b[1005];
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
mem(is,0);
ll tr=0;
//ll a,b;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
//        is[i]=1;
        cin>>a[i]>>b[i];
//        for(int j=a;j<=b;j++)
//        {
//            if(is[j]==0)
//            {
//                is[i]=0;
//                break;
//            }
//        }
////        if(is[i])
//        ans+=is[i];
    }
    for(int i=n;i>=0;i--)
    {
        if(i==0)
        {
            cout<<"-1";
        }
        else
        {
            ll cnt=0;
            for(int j=1;j<=n;j++)
            {
                if(a[j]<= i && i<=b[j])
                {
                    cnt++;
                }
            }
            if(cnt==i)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
//    cout<<ans;


#ifdef use_t
}
#endif // use_t
    return 0;
}

