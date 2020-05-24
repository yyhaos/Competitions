//Problem Web:≤‚∆¿ŒﬁÃ‚ƒø
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
ll a[1000];
ll b[1000];
ll ta[10005];
ll tb[10005];
ll lcm(ll &x,ll &y){
    return x*y/__gcd(x,y);
}
ll dp[55][55];
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
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>b[i];
    ll ga=a[0];
    ll gb=b[0];
    for(int i=0;i<n;i++){
        ga=__gcd(ga,a[i]);
    }
    for(int i=0;i<m;i++){
        gb=__gcd(gb,b[i]);
    }
    for(int i=0;i<n;i++){
        a[i]/=ga;
    }
    for(int i=0;i<m;i++)
        b[i]/=gb;
    ll ans=0;
    for(int t1=0;t1<n;t1++){
        for(int t2=0;t2<m;t2++){
            ll tlcm=lcm(a[t1],b[t2]);
            for(int i=0;i<n;i++){
                ta[i]=a[i]*tlcm/a[t1] ;
            }
            for(int i=0;i<m;i++){
                tb[i]=b[i]*tlcm /b[t2] ;
            }

            memset(dp,0,sizeof(dp));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){

                    if(i!=0){
                        dp[i][j]=max(dp[i-1][j],dp[i][j]);
                    }
                    if(j!=0){
                        dp[i][j]=max(dp[i][j-1],dp[i][j]);
                    }

                    if(ta[i]==tb[j])
                    {
                        if(i==0 || j==0){
                            dp[i][j]=1;
                            //continue;
                        }
                        else
                            dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
                    }
                     ans=max(ans,dp[i][j]);
                }
            }


        }
    }

    cout<<n+m-ans;



#ifdef use_t
}
#endif // use_t
    return 0;
}

