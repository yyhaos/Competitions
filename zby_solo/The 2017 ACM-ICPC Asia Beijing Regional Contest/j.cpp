//Problem Web:https://vjudge.net/contest/318541
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
const ll INF = 1e18;
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
ll a[105];
ll sa[105];
ll L,R;
ll dp[105][105][105];
inline ll cha(ll l,ll r)
{
    return sa[r]-sa[l-1];
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

    while(cin>>n>>L>>R)
    {
        a[0]=sa[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",a+i);
            sa[i]=sa[i-1]+a[i];
        }
//        cout<<cha(3,4);
        for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=n+1;j++)
            {
                for(int s=0;s<=n+1;s++)
                    dp[i][j][s]=INF;
            }
            if(i && i<=n)
            dp[i][i][1]=0;
        }
        for(ll len=2;len<=n;len++)
        {
            for(ll st=1;st<=n;st++)
            {
                ll ed=st+len-1;
                if(ed>n)
                    break;
                for(ll k=2;k<=min(len,ed);k++ )// ¶ÑÊý
                {
                    for(ll di = st+k-2;di<ed;di++) // ·Ö¸îµã
                    {
                        dp[st][ed][k]=min(dp[st][ed][k],dp[st][di][k-1]+dp[di+1][ed][1]);
                    }
                }

                for(ll k=L-1;k<=R-1;k++)
                {
                    for(ll di=st+k-1;di<ed;di++)
                    {
                        dp[st][ed][1]=min(dp[st][ed][1],dp[st][di][k]+dp[di+1][ed][1]+cha(st,ed));
                    }
                }
            }
        }

        if(dp[1][n][1]<INF)
        printf("%lld\n",dp[1][n][1]);
        else
            printf("0\n");





//        for(int i=1;i<=n;i++)
//        {
//            for(int j=i;j<=n;j++)
//            {
//                for(int s=0;s<2;s++)
//                    cout<<"i:"<<i<<" j:"<<j<<" s:"<<s<<" = "<<dp[i][j][s]<<"\n";
//            }
//        }
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}


