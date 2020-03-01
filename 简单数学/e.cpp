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
ll md=7;

ll f[10][10];
ll ff[5050];

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
ll a,b;
    while(cin>>a>>b>>n)
    {
        ll st=-1;ll xun=0;
map<ll,ll>mp;
        if(a==0)break;
        ff[1]=1;ff[2]=1;
        int i;
        for(i=3;i<=5000;i++)
        {
            ff[i]=a*ff[i-1]+b*ff[i-2];
            ff[i]%=7;
//            f[ff[i-1]][ff[i-2]]=ff[i];
            if(mp[ff[i-1]*10+ff[i-2]]!=0)
            {
                st=mp[ff[i-1]*10+ff[i-2]];
                xun=i-mp[ff[i-1]*10+ff[i-2]];
                break;
            }
            mp[ff[i-1]*10+ff[i-2]]=i;
        }
        if(n<st)
        {
            cout<<ff[n]<<endl;
        }
        else
        {
            cout<<ff[st+ (n-st)%xun]<<endl;
        }

    }




#ifdef use_t
}
#endif // use_t
    return 0;
}



