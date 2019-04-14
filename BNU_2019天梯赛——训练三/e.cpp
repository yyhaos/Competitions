//Problem Web:  //Problem Web:  https://vjudge.net/contest/290417?tdsourcetag=s_pcqq_aiomsg#problem/C
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
ll a[15];
ll tp[15];
void dfs(int th,int ma)
{

    if(th==m)
    {
        for(int i=0;i<m;i++)
        {
            printf("%lld",tp[i]);
            if(i!=m-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    //cout<<th<<endl;
    for(int i=ma+1;i<=n;i++)
    {
        if(a[i]==0)
        {
            a[i]=1;
            tp[th]=i;
            dfs(th+1,i);
            tp[th]=0;
            a[i]=0;
        }
    }
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

    cin>>n>>m;
    //cout<<n<<m<<endl;
    dfs(0,0);




#ifdef use_t
}
#endif // use_t
    return 0;
}
