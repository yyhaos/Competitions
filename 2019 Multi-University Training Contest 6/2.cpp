//Problem Web:http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1002&cid=853
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
const ll INF = 100000000;
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

ll t,n,m;
const ll maxn=50010;
ll a[maxn],b[maxn];
ll p[maxn];
ll used[maxn];
int Search(ll num,ll low,ll high)
{
    ll mid;
    while(low<=high)
    {
        mid=(low+high/2);
        if(num>=b[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}
ll DP(ll n)
{
    ll i,len,pos;
    b[1]=a[1];
    p[1]=1;
    len=1;
    for(i=2;i<=n;i++)
    {
        if(a[i]>=b[len])
        {
            p[len]=i;
            b[len++]=a[i];
        }
        else
        {
            pos=Search(a[i],1,len);
            p[pos]=i;
            b[pos]=a[i];
        }
    }
    mem(used,0);
    for(int i=1;i<len;i++)
    {
        used[p[i]]=1;
    }
    return len;
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






#ifdef use_t
}
#endif // use_t
    return 0;
}

