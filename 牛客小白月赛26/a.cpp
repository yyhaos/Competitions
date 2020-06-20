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
ll a[1000005];

    ll sum[1000005];
bool check(ll x){
    //x 本免费的 、x本要1的
    ll has=0;
    ll now=0;

//    printf("x:%lld\n",x);
    for(ll i=0;i<n;i++){

        if(i+1<=x){
            now = sum[i];
        }
        else {
            ll du = (i+1)/x;
            ll dai = x*(du-1)*du/2;
            ll yu = (i+1)%x;
            dai+= yu*du;
            now=sum[i] -dai;
        }
//    printf("i:%lld = %lld\n",i,now);
        has=max(has,now);
    }
    return has>=m;
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
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%lld",a+i);
    }
    sort(a ,a+n);
    mem(sum,0);
    sum[0]=a[n-1];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+a[n-1-i];
    }
    ll l=1,r=n;
    while(l<r){
        ll mid=(r+l)/2;
        if(check(mid)){
            r=mid-1;
        }
        else
            l=mid+1;
    }

    ll ans=-1;
    for(int i=max(1LL,l-5);i<=min(n,l+5);i++){
        if(check(i)){
            ans=i;
            break;
        }
    }

    printf("%lld",ans);


#ifdef use_t
}
#endif // use_t
    return 0;
}

