//Problem Web:  http://www.bnuoj.com/contest_show.php?cid=9146#problem/D
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
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
ll dp[105][105][20][20];
ll t,n,m;

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
    ll n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    mem(dp,0);
    dp[1][0][1][0]=1;
    dp[0][1][0][1]=1;
    rep(i,0,n1)
    {
        rep(j,0,n2)
        {
            if(i==j && i==0)
            {
                continue;
            }
            dp[i][j][k1+1][0]=0;
            dp[i][j][0][k2+1]=0;
            rep(num,1,10)
            {
                //cout<<"dp["<<i<<"]["<<j<<"] 01="<<dp[i][j][0][num]<<"  "<<num<<endl;
                //cout<<"dp["<<i<<"]["<<j<<"] 10="<<dp[i][j][num][0]<<"  "<<num<<endl;
                if(num+1<=k2)
                    dp[i][j+1][0][num+1]+=dp[i][j][0][num];
                dp[i+1][j][1][0]+=dp[i][j][0][num];

                if(num+1<=k1)
                    dp[i+1][j][1+num][0]+=dp[i][j][num][0];
                dp[i][j+1][0][1]+=dp[i][j][num][0];

                dp[i][1+j][0][num+1]%=100000000LL;
                dp[i+1][j][1][0]%=100000000LL;
                dp[i+1][j][num+1][0]%=100000000LL;
                dp[i][j+1][0][1]%=100000000LL;
            }
        }
    }

    ll ans=0;
    rep(i,1,k1)
    {
        ans+=dp[n1][n2][i][0];
        ans%=100000000LL;
        //cout<<dp[n1][n2][i][0]<<" r "<<i<<endl;
        //ans+=dp[n1][n2][i][0];
    }
    rep(i,1,k2)
    {
        ans+=dp[n1][n2][0][i];
        ans%=100000000LL;
        //ans+=dp[n1][n2][i][0];

       // cout<<dp[n1][n2][i][0]<<" "<<i<<endl;
    }
cout<<ans;


#ifdef use_t
}
#endif // use_t
    return 0;
}
