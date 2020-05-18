//Problem Web:
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
    double a,b,c;
double f(double x){
    return pow(x,a)+ b*log(x) -c;
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
    cin>>a>>b>>c;
    double l=0,r=3e9;
    double pre=0;
    while(r-l>1e-7){
          //  printf("%.10f %.10f\n",l,r);
        double mid=r+l;
        if( fabs(mid-pre)<1e-7) break;
        pre=mid;
        mid/=2.0;
        if(f(mid)>0){
            r=mid;
        }
        else
            l=mid;
    }
 //   if(l > 1e-9 && l<1e18-1e-9){
        printf("%.10f",l);
  //  }
   // else cout<<-1;





#ifdef use_t
}
#endif // use_t
    return 0;
}


