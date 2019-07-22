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
double p[55];
double p2[55];
//double k[55];
int main ()
{
    p[1]=1;
    p[0]=0;
    for(ll i=2;i<=50;i++)
    {
        p[i]=1.0/i;
        double dd=1.0/i;
        //cout<<dd<<endl;
        for(ll j=2;j<i;j++)
        {
            p[i]+=dd*p[i-j+1];
        }
        //cout<<i<<" "<<p[i]<<endl;
    }
    p2[1]=1;
    for(ll i=2;i<=50;i++)
    {
        p2[i]=0;
        for(ll st=1;st<=i;st++)
        {
            p2[i]+=p[st]/i;
        }
        //cout<<i<<" "<<p2[i]<<endl;
    }
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
    cout<<"Case #"<<ii<<": ";

    double a1,a2;

    printf("%.6f %.6f\n",p[n],p2[m]);





#ifdef use_t
}
#endif // use_t
    return 0;
}
