//Problem Web:https://ac.nowcoder.com/acm/contest/882#countdown
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
double p[1205];
ll k;
double fi(ll x)
{

    if(x<0)
        return 0;
    if(p[x]!=0)
        return p[x];
    else
    {
//        cout<<x<<endl;
        double tt=1.0/k,tmp=0;
//        cout<<tt<<" . "<< tmp<<endl;
        for(ll i=1;i<=k;i++)
        {
            if(i<=x)
            {
                tmp+= tt*fi(x-i);
            }
            else
                break;
        }
//        cout<<tt<<" + "<< tmp<<endl;
        return p[x]=tmp;
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

    //double p=1;
    for(int i=0;i<1200;i++)
        p[i]=0;
    p[0]=1;
    k=3;


    for(k=2;k<=10;k++)
    {
        for(int i=0;i<1200;i++)
            p[i]=0;
        p[0]=1;
        cout<<"k=:"<<k<<endl;
//        for(int i=1;i<=5;i++)
//        {
//            cout<<i<<" : "<<fi(i)<<" \n";
//        }
        cout<<1000<<" : "<<fi(1000)<<"\n";
    }






#ifdef use_t
}
#endif // use_t
    return 0;
}

