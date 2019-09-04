//Problem Web:https://vjudge.net/contest/288637#problem/E
//#include<bits/stdc++.h>
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
ll a[205];
ll b[205];
ll c[205];
ll t,n,m;
string sa,sb;
ll la,lb;
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
    cin>>sa>>sb;
    ll la=sa.length();
    ll lb=sb.length();
    for(int i=0;i<la;i++)
        a[i]=sa[i]-'0';
    for(int j=0;j<lb;j++)
        b[j]=sb[j]-'0';
    ll jin=0;
    //cout<<la<<" "<<lb<<endl;
    ll cnt=max(la,lb);
    while(la >0 && lb>0)
    {
        ll ta=la-1;
        ll tb=lb-1;
        //cout<<a[ta]+b[tb]+jin<<endl;
        if(a[ta]+b[tb]+jin>=10)
        {

            c[max(ta,tb)]=(a[ta]+b[tb]+jin)%10;
            jin=1;
        }
        else
        {

            c[max(ta,tb)]=a[ta]+b[tb]+jin%10;
            jin=0;
        }
        la--;
        lb--;
    }
    while(la>0)
    {
        ll ta=la-1;
        if(a[ta]+jin>=10)
        {

            c[ta]=(a[ta]+jin)%10;
            jin=1;
        }
        else
        {

            c[ta]=a[ta]+jin%10;
            jin=0;
        }
        la--;
    }
    while(lb>0)
    {
        ll tb=lb-1;
        if(b[tb]+jin>=10)
        {

            c[tb]=(b[tb]+jin)%10;
            jin=1;
        }
        else
        {

            c[tb]=b[tb]+jin%10;
            jin=0;
        }
        lb--;
    }
    ll qian=1;
    if(jin)
    {
        cout<<"1";
        qian=0;
    }
    for(int i=0;i<cnt;i++)
    {
        if(qian && c[i]==0)
            continue;
        else
        {
            qian=0;
            cout<<c[i];
        }
    }
    if(qian)
        cout<<0;
#ifdef use_t
}
#endif // use_t
    return 0;
}
