//Problem Web:https://vjudge.net/contest/330734#problem/A
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
int cnt[10]={6,2,5,5,4,5,6,3,7,6};
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
freopen("alarm.in","r",stdin);
freopen("alarm.out","w",stdout);


#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    cin>>n;
    for(int i=0;i<=1;i++)
    {
        for(int j=0;j<=9;j++)
        {

            for(int k=0;k<=5;k++)
            {
                for(int o=0;o<=9;o++)
                {
                    if(cnt[k]+cnt[o]+cnt[i]+cnt[j]==n)
                    {
                        printf("%d%d:%d%d",i,j,k,o);
                        return 0;
                    }
                }
            }
        }
    }
    for(int j=0;j<=3;j++)
    {
       for(int k=0;k<=5;k++)
            {
                for(int o=0;o<=9;o++)
                {
                    if(cnt[k]+cnt[o]+cnt[2]+cnt[j]==n)
                    {
                        printf("%d%d:%d%d",2,j,k,o);
                        return 0;
                    }
                }
            }
    }

    printf("Impossible");


#ifdef use_t
}
#endif // use_t
    return 0;
}

