//Problem Web:
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<string>
#include<map>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))

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
double hui[35][35];
ll t,n,m;
map<string,ll> mp;
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
int ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    string name[35];
    ll ii=1;
    while(~scanf("%lld%",&n))
    {
        if(n==0)
            break;
        rep(i,1,n)
        {
            rep(j,1,n)
            {
                hui[i][j]=0;
            }
            hui[i][i]=1.0;
        }
        rep(i,1,n)
        {
            cin>>name[i];
            mp[name[i]]=i;
        }
        cin>>m;
        string t1,t2;
        double th;
        rep(i,1,m)
        {
            cin>>t1>>th>>t2;
            hui[mp[t1]][mp[t2]]=th;
        }
        rep(k,1,n)
        rep(i,1,n)
        rep(j,1,n)
        {
            hui[i][j]=max(hui[i][k]*hui[k][j],hui[i][j]);
        }
        ll flag=0;
        rep(i,1,n)
        {
           if(hui[i][i]>1.0+0.0000000000001)
           {
               flag=1;
           }
        }
        if(flag)
        {
           cout<<"Case "<<ii++<<": Yes"<<endl;
        }
        else
           cout<<"Case "<<ii++<<": No"<<endl;
    }





#ifdef use_t
}
#endif // use_t
    return 0;
}
