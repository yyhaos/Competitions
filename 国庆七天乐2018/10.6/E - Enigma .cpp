#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return (b==0)? a : gcd(b,a%b);}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int maxn = 1010;
char s[maxn];
int up[maxn];
int mem[maxn][maxn], ans[maxn][maxn];
int mod,n;


int dfs(int ind,int sum){
    if (ind == n+1) return sum==0;
    int &res = mem[ind][sum];
    if (res>=0) return res;
    res = 0;
    if (up[ind]!=-1){
        ans[ind][sum] = up[ind];
        return res = dfs(ind+1,(sum*10+up[ind])%mod);
    }else {
        if (ind==1){
            for (int j=1;j<=9;j++){
                if (dfs(ind+1,(sum*10+j)%mod)==1){
                    ans[ind][sum] = j;
                    return res = 1;
                }
            }
        }else {
            for (int j=0;j<=9;j++){
                if (dfs(ind+1,(sum*10+j)%mod)==1){
                    ans[ind][sum] = j;
                    return res = 1;
                }
            }
        }
    }
}

int main(){
    //freopen("1.txt","r",stdin);
    memset(up,-1,sizeof(up));
    memset(mem,-1,sizeof(mem));
    scanf("%s%d",s+1,&mod);
    n = strlen(s+1);
    for (int i=1;i<=n;i++) {
        if (s[i]=='?') up[i] = -1;
        else up[i] = s[i] - '0';
    }
    /*for (int i=n,j=1;i>=1;i--,j++){
        if (j==1)
            c[i] = 1;
        else c[i] = c[i+1]*10%mod;
    }
    sum = 0;
    for (int i=1;i<=n;i++){
        if (up[i]!=-1){
            sum=(sum+c[i]*up[i])%mod;
        }
    }*/
    if(dfs(1,0)){
        for (int i=1,m=0;i<=n;i++){
            printf("%d",ans[i][m]);
            m = (m*10 + ans[i][m])%mod;
        }
    }
    else printf("*");
    return 0;
}
