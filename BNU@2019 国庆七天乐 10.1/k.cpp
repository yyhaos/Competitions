//Problem Web:https://vjudge.net/contest/330734#problem/A
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
ll qq[1005];
ll x[1005];

ll dp[10005][255][2];

int getid(int x)
{
    return x%9997;
}

ll ri[1005];
ll le[1005];
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#else
freopen("kebab.in","r",stdin);
freopen("kebab.out","w",stdout);

#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
ll t;
    cin>>n;
    cin>>t;
t++;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",qq+i,x+i);
    }

    ri[0]=0;
    for(int i=1;i<=n;i++)
    {
        ri[i]=ri[i-1]+qq[i];
    }
    le[1]=1;
    for(int i=2;i<=n;i++)
    {
        le[i]=le[i-1]+qq[i-1];
//        printf("%lld ",le[i]);
    }
    mem(dp,0);

//    dp[0][i][1]=1;
    dp[1][ qq[1]-x[1] ][1]=1;
    if(qq[1]-x[1])
        dp[1][ qq[1]-x[1] ][0]=1;
    for(int i=2;i<=ri[n];i++)
    {
        for(int j=250;j>=0;j--)
        {
            dp[getid(i)][j][0]=dp[getid(i)][j][1]=0;
        }
        ll pos=upper_bound(le+1,le+n+1,i)-le-1;
        ll prepos=upper_bound(le+1,le+n+1,i-t)-le-1;
        ll prepos2=upper_bound(le+1,le+n+1,i-1)-le-1;
//        printf("i:%d %lld %lld\n",i,pos,prepos);
        ll maxn=qq[pos]-x[pos];
        for(int j=maxn;j>=0;j--)
        {
            if(prepos == 0) //最前面
            {
                if(maxn>0)
                    dp[getid(i)][maxn][0]=1;
//                else
//                    dp[getid(i)][j][0]=0;
                //dp[getid(i)][j][1]=dp[getid(i-1)][j+1][0]+dp[getid(i-1)][j][1];
            }
            else if(prepos==pos) // 同段位
            {
                if(j)
                    dp[getid(i)][j][0]=dp[getid(i-t)][1+j][0]+dp[getid(i-t)][j][1];
//                else
//                    dp[getid(i)][j][0]=0;
               // dp[getid(i)][j][1]=dp[getid(i-1)][j+1][0]+dp[getid(i-1)][j][1];
            }
            else // 不同段
            {
//                ll sum=0;
                if(maxn)
                if(j==maxn)
                {
                    ll maxn2=qq[prepos]-x[prepos];
                    for(int tj=maxn2;tj>=0;tj--)
                    {
                        dp[getid(i)][maxn][0]+=dp[getid(i-t)][tj][0]+dp[getid(i-t)][tj][1];
                    }
                }
             //   dp[getid(i)][j][1]=dp[getid(i-1)][j+1][0]+dp[getid(i-1)][j][1];
            }

            dp[getid(i)][j][0]%=q;
            if(prepos2 == pos)
            {
                    dp[getid(i)][j][1]=dp[getid(i-1)][j+1][0]+dp[getid(i-1)][j][1];
            }
            else
            {
                if(j==maxn)
                {
                    ll maxn2=qq[prepos2]-x[prepos2];
                    for(int tj=maxn2;tj>=0;tj--)
                    {
                        dp[getid(i)][maxn][1]+=dp[getid(i-1)][tj][0]+dp[getid(i-1)][tj][1];
                    }
                }

            }
            dp[getid(i)][j][1]%=q;
        }
    }

//    for(int i=1;i<=ri[n];i++)
//    {
//        ll pos=upper_bound(le+1,le+n+1,i)-le-1;
//        ll maxn=qq[pos]-x[pos];
//        for(int j=0;j<=maxn;j++)
//        {
//
//            printf("%lld_%lld ",dp[getid(i)][j][0],dp[getid(i)][j][1]);
//        }
//        printf("\n");
//    }


ll ans=0;
    for(int i=0;i<=250;i++)
        ans+=dp[getid(ri[n])][ i ][0]+dp[getid(ri[n])][i][1];
    printf("%lld",ans%q);



#ifdef use_t
}
#endif // use_t
    return 0;
}



