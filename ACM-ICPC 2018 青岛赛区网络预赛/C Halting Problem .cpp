#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod = 256;
const int maxn = 1e4 + 2;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

//const char *op[3] = {"add","beq","bne","blt","bgt"};

struct bili{
    int op,v,k;
}ins[maxn];
bool vis[maxn][mod+1];

int main(){
    int T,n;
    char s[4];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=n;i++){
            scanf("%s",s);
            if (strcmp(s,"add")==0){
                scanf("%d",&ins[i].v);
                ins[i].op = 1;
                ins[i].k = 0;
            }
            else if (strcmp(s,"beq")==0){
                ins[i].op = 2;
                scanf("%d%d",&ins[i].v,&ins[i].k);
            }else if (strcmp(s,"bne")==0){
                ins[i].op = 3;
                scanf("%d%d",&ins[i].v,&ins[i].k);
            }else if (strcmp(s,"blt")==0){
                ins[i].op = 4;
                scanf("%d%d",&ins[i].v,&ins[i].k);
            }else if (strcmp(s,"bgt")==0){
                ins[i].op = 5;
                scanf("%d%d",&ins[i].v,&ins[i].k);
            }
        }
        int r = 0;
        int cnt = 1;
        bool flag = false;
        while(1){
            if (cnt==n+1){
                flag = true;
                break;
            }
            if (ins[cnt].op==1){
                r = (r+ins[cnt].v)%mod;
                cnt++;
            }else if (ins[cnt].op==2){
                if (r == ins[cnt].v){
                    if (vis[cnt][r]){
                        break;
                    }else{
                        vis[cnt][r] = true;
                    }
                    cnt = ins[cnt].k ;
                }else cnt++;
            }else if (ins[cnt].op==3){
                if (r != ins[cnt].v){
                    if (vis[cnt][r]){
                        break;
                    }else{
                        vis[cnt][r] = true;
                    }
                    cnt = ins[cnt].k;
                }else cnt++;
            }else if (ins[cnt].op==4){
                if (r < ins[cnt].v){
                    if (vis[cnt][r]){
                        break;
                    }else{
                        vis[cnt][r] = true;
                    }
                    cnt = ins[cnt].k ;
                }else cnt++;
            }else if (ins[cnt].op==5){
                if (r > ins[cnt].v){
                    if (vis[cnt][r]){
                        break;
                    }else{
                        vis[cnt][r] = true;
                    }
                    cnt = ins[cnt].k ;
                }else cnt++;
            }
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
