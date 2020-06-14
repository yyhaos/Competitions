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
char M[105][105];
ll fx[8]={0,1,1,1,0,-1,-1,-1};
ll fy[8]={1,1,0,-1,-1,-1,0,1};
int dis[105][150];
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

    cin>>n>>m;
    getchar();
    for(int i=1;i<=n;i++){
        scanf("%s", M[i]+1 );
    }

    for(int i=0;i<=n+1;i++){
        M[i][0]=M[i][m+1]='z';
    }
    for(int i=0;i<=m+1;i++){
        M[0][i]=M[n+1][i]='z';
    }

     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(M[i][j]=='*'){
                for(int k=0;k<8;k++){
                    int ni=i+fx[k];
                    int nj=j+fy[k];
                    if(M[ni][nj]!='*')
                        M[ni][nj]='z';
                }
            }
        }
    }

    memset(dis,0,sizeof(dis));

    queue<int>q;
    int off=100;
    int ok=0;int ei,ej;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(M[i][j]=='S')
            {ok++;
                q.push(i*off+j);
                dis[i][j]=1;
            }
            if(M[i][j]=='E'){
                    ei=i;ej=j;
                ok++;
            }
        }
    }




//        for(int i=0;i<=n+1;i++){
//        printf("%s\n",M[i]);
//    }

    if(ok<2){
        printf("Impossible");
        return 0;
    }
    else {
        while(!q.empty()){
//                for(int i=1;i<=n;i++){
//                        for(int j=1;j<=m;j++)
//                    printf("%d",dis[i][j]);
//                printf("\n");
//                }
            int top=q.front();
            q.pop();
            int i=top/off;
            int j=top%off;
            for(int k=0;k<8;k+=2){
                int ni=i+fx[k];
                int nj=j+fy[k];
                if(( M[ni][nj]=='.' || M[ni][nj]=='E') && dis[ni][nj] == 0){
                    dis[ni][nj]=dis[i][j]+1;
                    q.push(ni*off+nj);
                }
            }
        }
    }
    if(dis[ei][ej]!=0){
        printf("%d",dis[ei][ej]-1);
    }
    else {
        printf("Impossible");
    }



#ifdef use_t
}
#endif // use_t
    return 0;
}

