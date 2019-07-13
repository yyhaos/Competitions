//Problem Web:https://codeforces.com/contests/247802
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
#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;
const ll maxn=1000;
const ll q= 998244353LL;
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
ll dp[200005];

struct line {
    ll xa,xb,ya,yb;
    friend bool operator < (line n,line m)
    {
        ll k1m=n.ya-n.yb;
        ll k1z=n.xa-n.xb;

        ll k2m=m.ya-m.yb;
        ll k2z=m.xa-m.xb;

        if(k1z==0)
        {
            if(k2z!=0)
                return 1;
            else
                return n.xa>m.xa;
        }
        else if(k1m == 0)
        {
            if(k2z==0)
                return 0;
            if(k2m!=0)
            {
                return k2m*k2z>0;
            }
            return n.ya>m.ya;
        }
        else if(k1m*k1z>0)
        {
            if(k2z==0)
                return 0;
            if(k2m!=0)
            {
                if(k2m*k2z<0)
                {
                    return 1;
                }
                else
                {
                    if(k1m * k2z != k2m * k1z)
                    {
                        return k1m * k2z > k2m * k1z;
                    }
                    else
                    {
                        return (n.xb*n.ya-n.xa*n.yb)*(m.xb-m.xa)>(m.xb*m.ya-m.xa*m.yb)*(n.xb-n.xa);
                    }
                }
            }
            else
                return 1;
        }
        else
        {
            if(k2z==0)
                return 0;
            if(k2m!=0)
            {
                if(k2m*k2z>0)
                    return 0;
                if(k1m * k2z != k2m * k1z)
                {
                    return k1m * k2z > k2m * k1z;
                }
                else
                {
                    return (n.xb*n.ya-n.xa*n.yb)*(m.xb-m.xa)>(m.xb*m.ya-m.xa*m.yb)*(n.xb-n.xa);
                }
            }
            else
                return 0;
        }





    }
}a[100005];

double bb(line n)
{

    return 1.0*(n.xb*n.ya-n.xa*n.yb)/(n.xb-n.xa);
}
bool ispingxing(line n,line m)
{
    return (n.ya-n.yb)*(m.xa-m.xb)==(m.ya-m.yb)*(n.xa-n.xb);
}
bool ischonghe(line n,line m)
{
    if(ispingxing(n,m))
    {
        if(n.xa == n.xb && m.xa==m.xb)
            return n.xa==m.xa;
        else if((n.xb*n.ya-n.xa*n.yb)*(m.xb-m.xa)==(m.xb*m.ya-m.xa*m.yb)*(n.xb-n.xa))
            return true;
        return false;
    }
    //return ispingxing(n,m) ;
    return false;
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

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld%lld",&a[i].xa,&a[i].ya,&a[i].xb,&a[i].yb);
    }
    sort(a+1,a+1+n);
    ll cnt=0;
    ll same=1;
    ll ans=0;
    ll pre=1;
//    cout<<a[1].xa<<" "<<a[1].ya<<" "<<a[1].xb<<" "<<a[1].yb<<" "<<ans<<endl;
    for(int i=2;i<=n;i++)
    {
//        cout<<a[i].xa<<" "<<a[i].ya<<" "<<a[i].xb<<" "<<a[i].yb<<" "<<ans<<endl;
//        cout<<"b:"<<bb(a[i])<<endl;
//        if(a[i]<a[i-1])
//        {
//            cout<<"xiaoyu"<<endl;
//        }
//        else
//            cout<<"dayu"<<endl;
        if(ispingxing(a[i-1],a[i]))
        {
            if(ischonghe(a[i-1],a[i]))
            {
                ans+=cnt+pre;
                same++;
                pre++;
            }
            else
            {
                pre=1;
                ans+=cnt;
                same++;
            }
        }
        else
        {
            pre=1;
            cnt+=same;
            ans+=cnt;
            same=1;
        }
    }
    cout<<ans<<endl;

//    ans=0;
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=i+1;j<=n;j++)
//        {//cout<<i <<" "<<j<<endl;
//            if(!ispingxing(a[i],a[j]))
//            {
//                ans++;
//               // cout<<i <<" "<<j<<endl;
//            }
//            else
//                if(ischonghe(a[i],a[j]))
//            {
//                ans++;
//              //  cout<<i <<" "<<j<<endl;
//
//            }
//        }
//    }
//    cout<<"baoli:"<<ans<<endl;




#ifdef use_t
}
#endif // use_t
    return 0;
}
