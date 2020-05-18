//Problem Web:https://ac.nowcoder.com/acm/contest/5808/B
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
ll kk[100050];
//const ll q=1e9+7;
ll c(ll tn,ll tm){
    ll now=tn-1;
    if(now==0)return 1;
    else {
        ll tx=now+tm;
        return kk[tx]%q *ksm(kk[tm],q-2)%q *ksm(kk[tx-tm],q-2)%q;
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
    kk[0]=kk[1]=1;
    for(ll i=2;i<=100005;i++){
        kk[i]=kk[i-1]*i%q;
//        cout<<kk[i]<<endl;
    }
    ll k;
    cin>>n>>m>>k;
    if(k<=1 || k>=n+m+1){
        printf("0");
        return 0;
    }
    if(n>m)swap(n,m);
    ll duo= n+n+1 ;
    if(duo>n+m)
        duo=n+m;
    if(k>duo){
        printf("0");
        return 0;
    }
ll ans=0;
   // cout<<n<<" "<<m<<" "<<k<<endl;
    if(k%2==0){
        k/=2;
        n-=k;
        m-=k;
        //ll ans=0;
        ans+= c(k,n)*c(k,m)%q *2LL%q;

    }
    else {
        k/=2;
        if(n>=k+1){
            ll tn=n-k-1;
            ll tm=m-k;
            //cout<<tn<<" "<<tm<<" ="<<k<<endl;
            ans+= c(k+1,tn)*c(k,tm)%q ;
        }
        if(m>=k+1){
            ll tn=n-k;
            ll tm=m-k-1;
           // cout<<tn<<" "<<tm<<" ="<<endl;
            ans+= c(k,tn)*c(k+1,tm)%q ;
        }
    }
    cout<<ans<<endl;



#ifdef use_t
}
#endif // use_t
    return 0;
}


