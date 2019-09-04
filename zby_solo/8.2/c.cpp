//Problem Web:www.bnuoj.com/contest_show.php?cid=9519#info
#include <bits/stdc++.h>

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
#define MAXN 100    // pre-calc max n for phi(m, n)
#define MAXM 100010 // pre-calc max m for phi(m, n)
#define MAXP 666666 // max primes counter
#define MAX 10000010    // max prime
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
// compressed bool flag for sieve prime. (i >> 1) because even numbers are omitted.
#define setbit(ar, i) (((ar[(i) >> 6]) |= (1 << (((i) >> 1) & 31))))
#define chkbit(ar, i) (((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))))
#define isprime(x) (( (x) && ((x)&1) && (!chkbit(ar, (x)))) || ((x) == 2))
//#define MAXN 1000005;
//const ll maxn=1000;
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

//ll t,n,m;
ll eular(ll n)
{
    ll ans=n;
    for(ll i=2; i*i<=n;i++)
    {
        if(n%i == 0)
        {
            ans-=ans/i;
            while(n%i == 0)
            {

            }
        }
    }
}
namespace pcf{
    long long dp[MAXN][MAXM];
    unsigned int ar[(MAX >> 6) + 5] = {0};
    int len = 0, primes[MAXP], counter[MAX];

    void Sieve(){
        setbit(ar, 0), setbit(ar, 1);
        for (int i = 3; (i * i) < MAX; i++, i++){
            if (!chkbit(ar, i)){
                int k = i << 1;
                for (int j = (i * i); j < MAX; j += k) setbit(ar, j);
            }
        }

        for (int i = 1; i < MAX; i++){
            counter[i] = counter[i - 1];
            if (isprime(i)) primes[len++] = i, counter[i]++;
        }
    }

    void init(){
        Sieve();
        for (int n = 0; n < MAXN; n++){
            for (int m = 0; m < MAXM; m++){
                if (!n) dp[n][m] = m;
                else dp[n][m] = dp[n - 1][m] - dp[n - 1][m / primes[n - 1]];
            }
        }
    }

    long long phi(long long m, int n){
        if (n == 0) return m;
        if (primes[n - 1] >= m) return 1;
        if (m < MAXM && n < MAXN) return dp[n][m];
        return phi(m, n - 1) - phi(m / primes[n - 1], n - 1);
    }

    long long Lehmer(long long m){
        if (m < MAX) return counter[m];

        long long w, res = 0;
        int i, a, s, c, x, y;
        s = sqrt(0.9 + m), y = c = cbrt(0.9 + m);
        a = counter[y], res = phi(m, a) + a - 1;
        for (i = a; primes[i] <= s; i++) res = res - Lehmer(m / primes[i]) + Lehmer(primes[i]) - 1;
        return res;
    }
}

long long solve(long long n){
    int i, j, k, l;
    long long x, y, res = 0;

    for (i = 0; i < pcf::len; i++){
        x = pcf::primes[i], y = n / x;
        if ((x * x) > n) break;
        res += (pcf::Lehmer(y) - pcf::Lehmer(x));
    }

    for (i = 0; i < pcf::len; i++){
        x = pcf::primes[i];
        if ((x * x * x) > n) break;
        res++;
    }

    return res;
}

ll a,b,k;
ll getsu(ll x, ll jian)
{
    ll cnt=pcf::Lehmer(x/k);
    if(x>=k)
        cnt++;

    if(cnt<=jian)
        return 0;
//        if(!x%k)
//cout<<x<<":"<<pcf::Lehmer(x/k+1)<<endl;
//else
//cout<<x<<":"<<cnt<<" "<<cnt-jian<<endl;

//cout<<ans<<endl;
//    if(!x%k)
//        return pcf::Lehmer(x/k+1) + getsu(x/k) ;
//    else
        return cnt-jian+getsu(x/k,jian);
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
pcf::init();
    cin>>a>>b>>k;
    for(ll i=2;i*i<=k;i++)
    {
        if(k%i == 0)
        {
            printf("0");
            return 0;
        }
    }
//    for(ll i=2;i<=20;i++)
//    {
//        cout<<i<<" : "<<pcf::Lehmer(i)<<endl;
//    }
//cout<<solve(5)<<endl;

//    cout<<  max(0LL,       getsu(b/k-1)-max(k-1,getsu(a/k-2))  ) ;

//ll yu=pcf::Lehmer(k);
////cout<<yu-1<<endl;
//    ll bb=getsu(b,yu);
//    if(b>=k)
//        bb++;
//    ll aa=getsu(a-1,yu);
//    if(a-1>=k)
//        aa++;
//    cout<<bb<<" "<<aa<<" ";
//    cout<<bb-aa<<endl;
    if(k==2)

        cout<<(b-a+1)/k/(k-1)<<endl;
    else
    {
        cout<<(b-a+1)/k/3<<endl;
    }
    ll bao=0;
    for(int i=a/k;i<=b/k;i++)
    {
        ll now=k*i;
        if(now<a || now>b)
            continue;
        ll fa=1;
        for(int j=2;j<k;j++)
        {
            if(now%j ==0)
            {
                fa=0;
                break;
            }
        }
        if(fa)
        {
//            cout<<now<<endl;
        }
        bao+=fa;
    }
    cout<<bao<<" "<<(b-a+1)/bao/k<<endl;
#ifdef use_t
}
#endif // use_t
    return 0;
}
