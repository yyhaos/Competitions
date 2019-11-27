//https://codeforces.com/contests/1257
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll q=1e9+7;
ll ksm(ll a, ll b){
    ll ans=1;while(b){
        if(b&1){
            ans=ans*a%q;
        }a=a*a%q;b/=2;
    }return ans;
}
int a[5][200005];
int tmp[200005];
int cnt=0;
int dp[200005];
int main ()
{
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    #endif // yyhao
    int k[5];
    const int INF = 300000;
//    memset(dp,-1,sizeof(dp));
    for(int i=0;i<200000;i++){
        dp[i]=INF;
    }
    for(int i=1;i<=3;i++)scanf("%d",i+k);
    for(int i=1;i<=3;i++){
        for(int j=1;j<=k[i];j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=1;i<=3;i++){
        sort(a[i]+1,a[i]+1+k[i]);
        for(int j=1;j<=k[i];j++){
//            printf("%d ",a[i][j]);
            tmp[cnt++]=a[i][j];
        }
//        printf("\n");
    }

//    for(int i=0;i<cnt;i++)
//    {
//        printf("%d ",tmp[i]);
//    }
//    printf("\n");

    int kk=0;
    for(int i=0;i<cnt;i++)
    {
        int pos=lower_bound(dp,dp+kk,tmp[i])-dp;
        if(pos==kk){
            dp[pos]=tmp[i];
            kk++;
        }
        else
            dp[pos]=tmp[i];
    }
    printf("%d",cnt-kk);


    return 0;
}



