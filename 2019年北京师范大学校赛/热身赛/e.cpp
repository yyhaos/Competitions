//Problem Web:
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
ll a[100005];
ll ans=0;
int fl=1;
ll cnt=0;
ll S;
ll dfs(ll k, ll sum, ll st)
{
    //cout<<k<<" "<<sum<<" "<<st<<endl;
    if(k==0)
    {
        if(fl)
            ans^=sum*sum;
        else
        {
            ans^=(S-sum)*(S-sum);
        }
        cnt++;
       // cout<<sum<<endl;
        return 0;
    }
    if(st>n)
        return 0;
    if(k-1 <= n-st+1);
        dfs(k-1,sum+a[st],st+1);
    if(k<=n-st+1)
        dfs(k,sum,st+1);
}
int main ()
{
#ifdef yyhao
    freopen("out.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
//cout<<1<<"\n10000 10\n";
//for(int i=1;i<=10000;i++)
//{
//    cout<<i<<" ";
//}
//return 0;
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
    S=0;
    ans=0;
#endif // use_t
ll k;
fl=1;

    cin>>n>>k;
    if(k>n/2)
{
    k=n-k;
    fl=0;
}
    rep(i,1,n){
    scanf("%lld",a+i);
    S+=a[i];
          }

    dfs(k,0,1);
    cout<<ans<<endl;
//cout<<cnt<<endl;

#ifdef use_t
}
#endif // use_t
    return 0;
}


