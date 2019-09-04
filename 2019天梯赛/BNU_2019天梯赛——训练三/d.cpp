//Problem Web:  //Problem Web:  https://vjudge.net/contest/290417?tdsourcetag=s_pcqq_aiomsg#problem/C
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
ll b;
ll a[500005];
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

    while(~scanf("%lld%lld",&n,&b))
    {
        if(n==-1)
            break;
        ll l,r;
        l=0;
        r=b*5000000LL;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",a+i);
            //sum+=a[i];
        }
        ll mid=0;
        ll sum=0;
        while(r>l)
        {
            mid=(l+r)/2LL;
            //cout<< "m "<<mid<<endl;
            sum=0;
            for(int i=1;i<=n;i++)
            {
                sum+=a[i]/mid;
                if(a[i]%mid>0)
                {
                    sum++;
                }
                //cout<<"s " <<sum<<endl;
            }
            if(sum<=b)
            {
                r=mid-1;
            }
            else if(sum>b)
            {
                l=mid+1;
            }
        }
        ll ans;
        for(ans=l-3;ans<=l+3;ans++ )
        {
            ll mid=ans;
            sum=0;
            for(int i=1;i<=n;i++)
            {
                sum+=a[i]/mid;
                if(a[i]%mid>0)
                {
                    sum++;
                }
                //cout<<"s " <<sum<<endl;
            }
            if(sum<=b)
            {
                break;
            }
        }
        cout<<ans<<endl;


    }




#ifdef use_t
}
#endif // use_t
    return 0;
}
