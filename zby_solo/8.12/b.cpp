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

const int MAXN = 20000000;
bool check[MAXN+10];
int prime[MAXN+10];
int mu[MAXN+10];
void Moblus()
{
    memset(check,false,sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= MAXN; i++)
    {
        if( !check[i] )
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; j ++)
        {
            if( i * prime[j] > MAXN)
                break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}
int sum[MAXN+10]; //找[1,n],[1,m]内互质的数的对数
long long solve(int n,int m)
{
    long long ans = 0;
    if(n > m)swap(n,m);
    for(int i = 1, la = 0; i <= n; i = la+1)
    {
        la = min(n/(n/i),m/(m/i));
        ans += (long long)(sum[la] - sum[i-1])*(n/i)*(m/i);
    }
    return ans;
}
int main()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    Moblus();
    sum[0] = 0;
    for(int i = 1;i <= MAXN;i++)
        sum[i] = sum[i-1] + mu[i];
    int a,b,c,d,k;
    int T;
//    scanf("%d",&T);
//    while(T--)
//    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d);
        k=1;
    long long ans = solve(b/k,d/k) - solve((a-1)/k,d/k) - solve(b/k,(c-1)/k) + solve((a-1)/k,(c-1)/k);
    printf("%lld\n",ans);
//    }
    return 0;
}


