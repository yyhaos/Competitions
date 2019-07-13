//Problem Web:https://codeforces.com/gym/247719/problem/D
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
 ll q=1e9+7;
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
const int MAXN = 100010;
const int MAXM = 100010;
struct Query
{
    int L,R,id;
}node[MAXM];
long long gcd(long long a,long long b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
struct Ans
{
    long long a,b;//分数a/b
    void reduce()//分数化简
    {
        long long d = gcd(a,b);
        a /= d; b /= d;
    }
}ans[MAXM];
int a[MAXN];
int num[MAXN];
int n,m,unit;
bool cmp(Query a,Query b)
{
    if(a.L/unit != b.L/unit)
        return a.L/unit < b.L/unit;
    else return a.R < b.R;
}
void work()
{
    long long temp = 0;
    memset(num,0,sizeof(num));
    int L = 1;  int R = 0;
    for(int i = 0;i < m;i++)
    {
        while(R < node[i].R)
        {
            R++;
            temp -= (long long)num[a[R]]*num[a[R]];
            num[a[R]]++;
            temp += (long long)num[a[R]]*num[a[R]];
        }
        while(R > node[i].R)
        {
            temp -= (long long)num[a[R]]*num[a[R]];
            num[a[R]]--;
            temp += (long long)num[a[R]]*num[a[R]];
            R--;
        }
        while(L < node[i].L)
        {
            temp -= (long long)num[a[L]]*num[a[L]];
            num[a[L]]--;
            temp += (long long)num[a[L]]*num[a[L]];
            L++;
        }
        while(L > node[i].L)
        {
            L--;
            temp -= (long long)num[a[L]]*num[a[L]];
            num[a[L]]++;
            temp += (long long)num[a[L]]*num[a[L]];
        }
        ans[node[i].id].a = temp - (R-L+1);
        ans[node[i].id].b = (long long)(R-L+1)*(R-L);ans[node[i].id].reduce();
    }
}


int main()
{
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
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    for(int i = 0;i < m;i++)
    {
        node[i].id = i;
        scanf("%d%d",&node[i].L,&node[i].R);
    }
    unit = (int)sqrt(n);
    sort(node,node+m,cmp);
    work();
    for(int i = 0;i < m;i++)
        printf("%lld/%lld\n",ans[i].a,ans[i].b);

#ifdef use_t
}
#endif // use_t
    return 0;
}
