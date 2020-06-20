//Problem Web:https://ac.nowcoder.com/acm/contest/6013
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
const ll q=10007;
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
ll x;

ll M[15][15];
ll si[15];
ll used[10];
ll d(ll x){
    used[x]=1;

    ll tx=1;
    for(int i=0;i<=9;i++){
        if(i!=x && M[x][i]==1 && used[i]==0){
            tx+=d(i);
        }
    }
    return tx;
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
mem(M,0);
    cin>>x>>n;
    ll a,b;
//    printf("xx%lld %lld\n",x,n);
//    for(int i=0;i<10;i++)
//        f[i]=i;
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&a,&b);
        M[a][b]=1;
    }
    mem(si,0);
    for(int i=0;i<10;i++){
            mem(used,0);
        si[i]= d(i);
    }
//    for(ll i=0;i<10;i++){
////        si[ i ] = si[fi(i)];
//        printf("si:%lld  %lld\n",si[i],i);
////        printf("f:%lld  %lld\n",f[i],i);
//    }

    ll ans=1;
    while(x){
        ll now=x%10;
        x/=10;
        ans*=si[now];
        ans%=q;
    }
    printf("%lld",ans);





#ifdef use_t
}
#endif // use_t
    return 0;
}


