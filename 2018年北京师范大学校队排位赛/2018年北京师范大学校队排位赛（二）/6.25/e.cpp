//Problem Web:https://codeforces.com/gym/225575
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
ll a[1003][1005];
ll dp[1003][1005];

struct G
{
    ll i,j,v;
    G ( ll _i,ll _j,ll _v)
    {
        i=_i;
        j=_j;
        v=_v;
    }
    friend bool operator < (G a, G b)
    {
        return a.v<b.v;
    }
};

ll wa[10005];
ll pushed[100005];
priority_queue<G> gg;

void push(ll th)
{
    if(pushed[th]==1)
    {
        return ;
    }
    else
    {

        for(int i=1;i<=n;i++)
        {
            if(i==th || wa[i]!=0)
                continue;
            gg.push(G(th,i,a[th][i]));
        }
        pushed[th]=1;
    }
}

int main ()
{
    mem(pushed,0);
    mem(wa,0);
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
    //mem(wa,0);
    cin>>n;
    int th=0;
    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<=i;j++)
        {
            scanf("%lld",&a[i+1][j]);
            a[j][i+1]=a[i+1][j];
        }
    }
    //sort(g,g+th);

    ll ans=0;
    push(1);
    wa[1]=1;
    while(!gg.empty())
    {
        G top=gg.top();
        gg.pop();
        if(wa[top.j]!=0)
            continue;
        else
        {
            ans+=top.v;
            push(top.j);
            wa[top.j]=top.i;
        }
    }

    printf("%lld\n",ans);
    for(int i=2;i<=n;i++)
    {
        printf("%lld\n",wa[i]);
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}



