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
ll a[100005];
ll b[100005];
ll anp[100005];
ll bnp[100005];
struct sta
{
    ll v,pos;
    friend bool operator<(sta a,sta b)
    {
        return a.v<b.v;
    }
}tmp[100005];;
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
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&tmp[i].v);
            tmp[i].pos=i;
        }
        sort(tmp+1,tmp+1+n);
        for(int i=1;i<=n;i++)
        {
            a[tmp[i].pos]=i;
            anp[i]=tmp[i].pos;
        }

        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&tmp[i].v);
            tmp[i].pos=i;

        }
        sort(tmp+1,tmp+1+n);
        for(int i=1;i<=n;i++)
        {
            b[tmp[i].pos]=i;
            bnp[i]=tmp[i].pos;
        }

//        for(int i=1;i<=n;i++)
//        {
//            cout<<b[i]<<" ";
//        }
//        cout<<endl;
//        for(int i=1;i<=n;i++)
//        {
//            cout<<bnp[i]<<" ";
//        }
//        cout<<endl;
        ll ami,bmi;
        ami=bmi=1;
        ll ans=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]>a[i-1] && b[i]>b[i-1])
            {
                ans=i;
                continue;
            }
            if(a[i]>a[i-1] && b[i]<b[i-1])
            {
                break;
            }
            if(a[i]<a[i-1] && b[i]>b[i-1])
            {
                break;
            }
            else if(a[i]<a[bmi] && b[i]<b[bmi])
            {
                ami=bmi=i;
                continue;
            }

            break;
        }

        cout<<ans<<"\n";
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}

