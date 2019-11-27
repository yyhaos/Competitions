//https://codeforces.com/contest/1256/problem/E

#include<bits/stdc++.h>
using namespace std;
#define ll long long
//ll a[200015];
ll dp[200015];
ll pa[200015];
ll pre[200015];
struct dui
{
    ll pos,v;
    dui(){}
    dui(ll _p,ll _v){pos=_p;v=_v;}
    friend bool operator<(dui a, dui b){
        return a.v<b.v;
    }
}a[200005];
ll ans[200005];
ll cnt=1,INF=3e14;
int main ()
{

//printf("%lld\n",INF);
    ll n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i].v);
        a[i].pos=i;
    }

    sort(a+1,a+n+1);
    dp[0]=0;
    pa[1]=1;
    pre[1]=0;
    for(int i=1;i<=2;i++){
        dp[i]=INF;
        if(i>0)
            pa[i]=i-1,pre[i]=i-1;
    }
    for(int i=3;i<=n;i++){
        ll cost=0;
        ll suit=INF,suit_j;
        for(int j=i-1;j>=max(1,i-10);j--){
            cost=a[i].v-a[j].v;
            if(j<=i-2){
                if(suit>cost+dp[j-1]){
                    suit=cost+dp[j-1];
                    suit_j=j;
                }
            }
        }
//        printf("%d %lld %lld\n",i,suit,suit_j);
        dp[i]=suit;
        pre[i]=suit_j;
        for(int k=suit_j;k<=i;k++){
            pa[k]=suit_j;
        }
    }
cnt=0;
    for(int i=n;i>=1;)
    {
            cnt++;
        for(int j=pre[i];j<=i;j++)
        {
            ans[a[j].pos]=cnt;
        }

        i=pre[i]-1;
    }
    printf("%lld %lld\n",dp[n],cnt);
    for(int i=1;i<=n;i++)
    {
        if(i-1)
            printf(" ");
        printf("%lld",ans[i]);
    }
    printf("\n");

    return 0;
}
