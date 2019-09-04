//Problem Web:  https://vjudge.net/contest/288922#problem/F
//#include<bits/stdc++.h>
//#include<ext/rope>
#include<map>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair

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
struct pp
{
    int a,b;
    friend bool operator <(pp x,pp y)
    {
        return x.a<y.a;
    }
}p[1005];
ll t,n,m;
#define use_t 1
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

cin>>n;
int a,b;
    rep(i,1,n)
    {
        scanf("%d%d",&p[i].a,&p[i].b);
    }
    sort(p+1,p+1+n);
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=p[j].b;i++)
        {
            printf(">+");
            for(int k=1;k<=p[j].a-2;k++)
                printf("-");
            printf("+>");
                printf("\n");
        }
        printf("\n");
    }







#ifdef use_t
}
#endif // use_t
    return 0;
}
