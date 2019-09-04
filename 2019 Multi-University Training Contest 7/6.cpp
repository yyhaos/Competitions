//Problem Web:http://acm.hdu.edu.cn/userloginex.php?cid=854
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
#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 1e18;
const ll maxn=1000;
const ll q=1e9+7;
inline ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a;
        a=a*a;
        b/=2LL;
    }
    return ans;
}
const ll MAXN=50000;
int prime[MAXN+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++)
    {
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
long long factor[100][2];
int fatCnt;
int getFactors(long long x)
{
    fatCnt=0;
    long long tmp=x;
    for(int i=1;prime[i]<=tmp/prime[i];i++)
    {
        factor[fatCnt][1]=0;
        if(tmp%prime[i]==0)
        {
            factor[fatCnt][0]=prime[i];
            while(tmp%prime[i]==0)
            {
                factor[fatCnt][1]++;
                tmp/=prime[i];
            }
            fatCnt++;
        }
    }
    if(tmp!=1)
    {
        factor[fatCnt][0]=tmp;
        factor[fatCnt++][1]=1;
    }
    return fatCnt;
}
ll k;
ll t,n,m;
inline ll get(ll i)
{
    if(k*i<=n)
    return (k*i*(m/i+1));
    else
        return get(1);
}

inline ll chouti(ll i,ll x)
{

    return 1LL+m%i+ (m/i * i);
}
ll fi(ll x)
{
    if(x<k)
        return INF;
    ll y= m/(1+x-k);
    while(y<=m/(1+x-k))
        y++;
    return x*y;
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
scanf("%lld",&t);
ll ans;
ll ati;
ll tmp,now,mici,si;
getPrime();
for(ii=1;ii<=t;ii++)
{
#endif // use_t
//ll k;
    scanf("%lld%lld%lld",&n,&m,&k);
//cout<<n<<" "<<m<<" "<<k<<endl;
    if(n==k || m==0)
    {
        printf("%lld\n",k*(m+1) );
    }
    else
    {

//        cout<<fi(2)<<endl;
//        cout<<fi(3)<<endl;

    }





#ifdef use_t
}
#endif // use_t
    return 0;
}


