#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = (int)(4e4);
int dx[] = {-3,-2,-1,0,1,2,3,0,0};
const LL maxll = (1ll<<63) -1 ;
int prime[maxn+5];

void init()
{
    for(int i=0;i<=maxn;i++) prime[i]=0;
    for(int i=2;i<=maxn;i++){
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j=1;j<=prime[0]&&prime[j]<=maxn/i;j++){
            prime[i*prime[j]] = 1;
            if(i%prime[j]==0) break;
        }
    }
}

LL mypow(LL x,int n){
    LL ret = 1;
    if(x <= 0 ) return -1;
    while(n--){
        if(maxll/x >= ret)
            ret*=x;
        else return -1;
    }
    return ret;
}

int solve(LL n)
{
    int ans=70;
    for(int i=1;i<=prime[0]&&prime[i]<=n; i++){
        if(n%prime[i]==0){
            int cnt=0;
            while(n%prime[i]==0){
                n/=prime[i];
                cnt++;
            }
            ans = min(ans , cnt);
        }
        if(ans == 1) return ans;
    }
    if(n == 1) return ans;

    LL s4 = (LL) (0.5 + pow(1.0*n,0.25));

    for(int i=0;i<7;i++)
        if( mypow(s4+dx[i],4) == n ) return min(ans , 4);

    LL s3 = (LL) (0.5 + pow(1.0*n,1.0/3));
    for(int i=0;i<7;i++)
        if( mypow(s3+dx[i],3) == n ) return min(ans , 3);

    LL s2 = (LL) (0.5 + pow(1.0*n,0.5));
    for(int i=0;i<7;i++)
        if( mypow(s2+dx[i],2) == n ) return min(ans , 2);
    if(n > 1) return 1;
}

int main(void)
{
//    freopen("data2.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    init();
    //printf("%lld\n",maxll);
    int _;scanf("%d",&_);
    while(_--){
        LL n;scanf("%lld",&n);
        int ans = solve(n);
        printf("%d\n",ans);
    }
}
