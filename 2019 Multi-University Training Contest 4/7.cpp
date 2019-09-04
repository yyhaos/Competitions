//Problem Web:http://acm.hdu.edu.cn/contests/contest_show.php?cid=851
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
ll a[4][4];
ll aa[20];
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
ll ceng;
ll cnt=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            scanf("%lld",&a[i][j]);
            if(a[i][j]==0)
    ceng=i;
            else
            {
                aa[cnt++]=a[i][j];
            }
        }
    }

    ll ni=0;
    for(int i=0;i<15;i++)
    {
//        cout<<aa[i]<<" ";
        for(int j=i+1;j<15;j++)
        {
            if(aa[i]>aa[j])
                ni++;
        }
    }
ll fa=0;
    if(ceng%2==1)//2 4 对应 偶数
    {
        if(ni%2==0)
        {
            fa=1;
        }
        else
            fa=0;
    }
    else// 1 3 对应奇数
    {
        if(ni%2)
            fa=1;
        else
            fa=0;
    }
    if(fa)
    {
        cout<<"Yes\n";
    }
    else
        cout<<"No\n";





#ifdef use_t
}
#endif // use_t
    return 0;
}


