//Problem Web:https://ac.nowcoder.com/acm/contest/881/E
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

//ll dp[1000][1000][1000];
ll dp[2005][2005];
//ll C(ll m,ll n)
//{
//    return k[m]*ksm(k[n],q-2)%q*ksm(k[m-n],q-2)%q;
//}
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



    while(~scanf("%lld%lld",&n,&m))
    {
//        if(n==0 && m==0)
//            return 0;
        ll he=2*(n+m);
        ll zn=n+m;
//        if(n>m)
//            swap(m,n);
        //n*=2,m*=2;
        //mem(dp,0);
        dp[0][0]=1;
        for(int i=1;i<=zn;i++)
        {
            if(i>n)
                dp[i][0]=0;
            else
                dp[i][0]=1;
        }
        for(int i=1;i<=zn;i++)
        {
            if(i>m)
                dp[0][i]=0;
            else
                dp[0][i]=1;
        }


        for(int i=1;i<=zn;i++)
        {
            if(i-n>1)
            {
                dp[i][i-n-1]=0;
            }
            for(int j=max(1LL,i-n);j<=zn;j++)
            {
//                if(i-n>1)
//                {
//                    dp[i][i-n]=0;
//                }
                if(j-i>m)
                {
                    dp[i][j]=0;
                    break;
                }
//                if(j-i<=m && i-j<=n)

//                if(j-i>m || i-j>n)
//                    break;


                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                dp[i][j]%=q;
            }
        }

//        for(int i=0;i<=zn;i++)
//        {
//            for(int j=1;j<=zn;j++)
//            {
//                cout<<dp[i][j]<<" ";
//            }
//            cout<<endl;
//        }

        printf("%lld\n",dp[zn][zn]);

//        cout<<C(n+m,n)<<"\n";
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}


