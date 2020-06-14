
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

ll xx[1000];
ll yy[1000];

ll dp[1000];
ll has[1000];


//        int th=0;


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

    int x,y;
    while(~scanf("%d%d",&x,&y)){
        for(int i=0;i<=x;i++)
            has[i]=0;
        for(int i=0;i<=y;i++){
            dp[i]=-1;
        }
        dp[0]=0;

        if(x>y){
            printf("-1\n");
            continue;
        }
        if(x==0){
            if(y==0){
                printf("0\n");
            }
            else printf("-1\n");
            continue;
        }
        int th=0;


        for(int i=1;i<=x;i++){
            //printf("%d",xx[i]);
            if( i&(1023-x)  ){
                continue;
            }
            has[th++]=i;
        }
//        for(int i=0;i<th;i++){
//            printf("has:%d\n",has[i]);
//        }
        if(x==y){
                printf("1\n");
            continue;
        }
        for(int i=0;i<=y;i++){
            if(dp[i]!=-1){
                for(int j=0;j<th;j++){
                    if(has[j]+i > y)
                        break;
                    if(dp[has[j]+i] ==-1)
                        dp[has[j]+i] = 1+dp[i];
                    else
                        dp[has[j]+i] = min(dp[has[j]+i], 1+dp[i]);
                }
            }
        }


        printf("%d\n",dp[y]);
//        printf("11:%d",(1<<10));
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}
