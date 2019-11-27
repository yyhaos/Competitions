//Problem Web:
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

ll t,n,m;
char ans[105][105];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
    freopen("kotlin.in","r",stdin);
    freopen("kotlin.out","w",stdout);
#endif

#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

ll k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        ans[i][j]='.';
        ans[i][m]=0;
    }
    for(int i=1;i<=(1+n)/2;i++)
    {
        for(int j=1;j<=(m+1)/2;j++)
        {
            if(i*j==k)
            {
                for(int ti=1;ti<i;ti++)
                {
                    for(int tj=0;tj<m;tj++)
                    ans[ti*2-1][tj]='#';
                }
                for(int tj=1;tj<j;tj++)
                {
                    for(int ti=0;ti<n;ti++)
                    {
                        ans[ti][tj*2-1]='#';
                    }
                }
                for(int i=0;i<n;i++)
                {
                    printf("%s\n",ans[i]);
                }
                return 0;
            }
        }
    }
    printf("Impossible");
#ifdef use_t
}
#endif // use_t
    return 0;
}


