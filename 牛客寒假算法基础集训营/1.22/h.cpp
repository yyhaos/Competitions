//Problem Web:
#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;

#define ll long long
#define LL long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
//#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
//#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-8;
const ll INF = 100000000;

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
ll exten_gcd(long long a,long long b,long long &x,long long &y)
{
    if(a==0&&b==0) return -1;//无最大公约数
    if(b==0){x=1;y=0;return a;}
    long long d=exten_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
//*********求逆元素*******************
//ax = 1(mod n)
long long mod_reverse(long long a,long long n)
{
    long long x,y;
    long long d=exten_gcd(a,n,x,y);
    if(d==1) return (x%n+n)%n;
    else return -1;
}
ll jie[2000005];ll p;
ll C(ll a, ll b)
{
    if(b>a)
        return 0;
    return jie[a]* mod_reverse(jie[b],p) %p *mod_reverse(jie[a-b],p)%p;
}

const int MAXN = 2000005;
bool ispri[MAXN];
int prime[MAXN];
int priCnt;
void CalPrime()
{
    priCnt = 0;
    memset(ispri,false,sizeof(ispri));
    for(int i = 2;i < MAXN; ++i)
    {
        if(ispri[i] == false)
        {
            prime[priCnt++] = i;
            for(int j = i+i;j < MAXN; j += i)
                ispri[j] = true;
        }
    }
}
LL DivideByPrime(LL N,LL P)
{
    LL ans = 0;
    while(N)
        ans += N/P,N /= P;
    return ans;
}
LL QuickMod(LL a,LL b,LL m)
{
    LL ans = 1;
    a %= m;
    while(b)
    {
        if(b&1)
            ans = ans*a%m,b--;
        b >>= 1;
        a = a*a%m;
    }
    return ans;
}


//C(N,M) % P
LL CalCnmModP(LL N,LL M,LL P)
{
    if(M>N)
        return 0;
    LL ans = 1;
    for(int i = 0 ;i < priCnt && prime[i] <= N; ++i)
    {
        LL x = DivideByPrime(N,prime[i]);
        LL y = DivideByPrime(N-M,prime[i]);
        LL z = DivideByPrime(M,prime[i]);
        x -= (y+z);
        ans *= QuickMod(prime[i],x,P);
        ans %= P;
    }
    return ans;
}

int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
int ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    ll k;
    cin>>n>>k>>p;
CalPrime();
    cout<<(CalCnmModP(2*n,n,p)-  CalCnmModP(2*n,n+k,p) +p)%p;
#ifdef use_t
}
#endif // use_t
    return 0;
}
