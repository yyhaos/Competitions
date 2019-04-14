//Problem Web:http://39.97.97.11/problem.php?cid=1002&pid=1
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
#define use_t 1
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
ll a[1005];
ll k;
ll kk[1005];
ll kni[1005];
ll ans[1005];
ll ki[1005];// ki[i]=k*k+1*...*(k+i-1)
void get(ll k)
{
    ki[0]=1;
    for(int i=1;i<=n;i++)
    {
        ki[i]=ki[i-1]*(k+i-1)%q;
    }
    kk[1]=1;
    kni[0]=1;
    kk[0]=1;
    kni[1]=1;
    for(int i=2;i<=1000;i++)
    {
        kk[i]=kk[i-1]*i%q;
        kni[i]=ksm(kk[i],q-2);
    }
}
ll C(ll i)//C(i+k-1,i)
{
    return ki[i] * kni[i]%q;
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

    cin>>n>>k;
    //cout<<n<<" "<<k<<endl;
    get(k);
    rep(i,1,n)
    {
        scanf("%lld",a+i);
    }

    cout<<a[1];
    //mem(ss,0);
    rep(i,2,n)
    {
        rep(j,1,i-1)
        {
            ll in=a[i-j]*C(j);
            a[i]-=in;
            a[i]+=q;
            a[i]%=q;
        }
        a[i]=a[i]+1000*q;
        a[i]%=q;
        cout<<" "<<a[i];
    }

    cout<<"\n";


#ifdef use_t
}
#endif // use_t
    return 0;
}


