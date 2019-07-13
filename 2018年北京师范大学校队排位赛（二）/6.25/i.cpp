//Problem Web:https://codeforces.com/gym/225575
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
const ll qq=1e9+7;


ll t,n,m;
ll q;
ll exgcd(ll a, ll b, ll &x,ll &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    ll g=exgcd(b,a%b,x,y),tmp=x;
    x=y;y=tmp-a/b*y;
    return g;
}
ll Min_x(ll a,ll b,ll c){
  ll x,y,g=exgcd(a,b,x,y),tmp=b/g;
  x*=c/g;
  x=x%tmp+tmp;
  return x>tmp?x-tmp:x;
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
    ll k;
    cin>>n>>k>>q;
    ll d,c;
    ll yilun=n/__gcd(n,k);

    while(q--)
    {
        scanf("%lld%lld",&d,&c);
        ll tmp=0;

       // printf("\n");
        ll ans,lunci=d/yilun;
        ll shengyu=d-lunci*yilun;
       // cout<<"ddddddd"<<shengyu<<endl;
//        for(int i=1;i<=shengyu;i++)
//        {
//          //  if(tmp==c)
//         //       printf("i::%d ",i);
//            tmp=tmp+k;
//            tmp%=n;
//
//        }
        if(c%__gcd(n,k)!=0)
            ans=0;
        else
        {
            ans=lunci;
            //ll off=0;
            ll th=0;
            //shengyu*k + y*n = 1
            //exgcd(k,n,th,off);
            th=Min_x(k,n,c/__gcd(n,k));
            //cout<<"c:"<<c<<endl;
            //cout<<"th:"<<th<<" "<<th*k%n<<endl;
            th%=n;
            if(shengyu>th)
            {
               // cout<<"you"<<endl;
                ans++;
            }
        }
        printf("%lld\n",ans);

    }



#ifdef use_t
}
#endif // use_t
    return 0;
}


