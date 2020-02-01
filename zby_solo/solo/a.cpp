//Problem Web:https://vjudge.net/contest/353524
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
float tt;
#define ull unsigned long long
ull dp[40000][15];
int tk[200]={10000,5000,2000,1000,500,100,200,50,20,10,5};
int cnt=11;
ull sum=0;
void fin(int now,int th)
{
    if(now==0)
        sum++;
    else if(th<cnt)
    {
        if(now >= tk[th])
        {
            fin(now-tk[th],th);
        }
        fin(now,th+1);
    }
    return ;
}

ull call(int x)
{
    sum=0;fin(x,0);return sum;
}

ull fi(int now, int th)
{
   // cout<<":"<<now<<" "<<th<<endl;
    if(dp[now][th]!=0)return dp[now][th];
    if(now<0 || th>=cnt)return 0;
    if(now==0)return dp[now][th]=1;
    ull tmp=0;
    if(now>=tk[th])
    {
        tmp+=fi(now-tk[th],th);
    }
    tmp+=fi(now,th+1);
    return dp[now][th]=tmp;
}
ull call2(int x)
{
    return fi(x,0);
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
    memset(dp,0,sizeof(dp));
   // call2(5);
   // printf("---)\n");

//    for(int i=5;i<=30000;i+=5)
//    {
//        printf("%d ",i  );
//        printf(" %lu \n",call2(i)  );
//    }
    while(cin>>tt)
    {
        if(tt==0)break;
        int nn=tt*100.00001;
//        printf("%d\n",nn);
        if(nn%5!=0)
        {

        printf("%6.2f%17lu\n",tt,0);
        }
        else
        printf("%6.2f%17lu\n",tt,call2(nn));
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}

