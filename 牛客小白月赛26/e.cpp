//Problem Web:https://ac.nowcoder.com/acm/contest/6013
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
char M[505][505];
ll dis1[505][505];
ll dis2[505][505];
const ll off=5000;
ll fx[4]={1,0,0,-1};
ll fy[4]={0,-1,1,0};
void bfs(ll sx,ll sy,ll dis[505][505]){
    queue<ll> q;
    while(!q.empty())q.pop();
    dis[sx][sy]=1;
    q.push(sx*off + sy);
//printf("re:%lld %lld\n",sx,sy);
    while(!q.empty()){
        ll top = q.front();q.pop();
        ll x= top/off;
        ll y= top%off;
//        printf("now:%lld %lld\n",x,y);
        for(int i=0;i<4;i++){
            ll nx=x+fx[i];
            ll ny=y+fy[i];
//printf("nxt:%lld %lld\n",nx,ny);
            if(nx<0 || nx>=n || ny<0 || ny>=m)
                continue;
            if(M[nx][ny]=='1'){
                continue;
            }
            if(dis[nx][ny]==0){
                dis[nx][ny]=dis[x][y]+1;
                q.push(nx*off+ny);
            }
        }
    }
}

char ans[4]={'D','L','R','U'};
ll used[505][505];
void show(ll x,ll y){
    used[x][y]=1;
    if(x==n-1 && y==m-1)return ;
    for(int i=0;i<4;i++){
        ll nx,ny;
        nx=x+fx[i];
        ny=y+fy[i];

        if(nx<0 || nx>=n || ny<0 || ny>=m || used[nx][ny]==1)
                continue;
        if(dis1[nx][ny] <= dis1[x][y])
            continue;
        if(dis1[nx][ny] + dis2[nx][ny]-1 == dis1[n-1][m-1] ){
//                cout<<"pre:"<<x<<" "<<y<<endl;
//                cout<<"nxt:"<<nx<<" "<<ny<<endl;
            printf("%c",ans[i]);
            show(nx,ny);
            break;
        }
    }
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
for(ii=1;ii<=t; ii++)
{
#endif // use_t
mem(used,0);
    mem(dis1,0);
    mem(dis2,0);
    cin>>n>>m;getchar();
    for(int i=0;i<n;i++){
        scanf("%s",M[i]);
    }
    bfs(0,0,dis1);
    bfs(n-1,m-1,dis2);

//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            printf("%lld ",dis1[i][j]);
//        }
//        printf("\n");
//    }printf("\n");
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            printf("%lld ",dis2[i][j]);
//        }
//        printf("\n");
//    }

    if(dis1[n-1][m-1]==0){
        printf("-1\n");
        return 0;
    }

    printf("%lld\n",dis1[n-1][m-1]-1);
    show(0,0);



#ifdef use_t
}
#endif // use_t
    return 0;
}


