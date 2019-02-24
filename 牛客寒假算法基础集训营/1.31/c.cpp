#include <bits/stdc++.h>
#define N 1050
#define lodou long double
#define lll __int128
#define INmF 0x3f3f3f3f
#define lbt(x) (x&(-x))
#define mes(a,b) memset(a,b,sizeof(a))
#define qwq(a,b) for(int i=a ;i<=b;i++)
#define qeq(a,b) for(int j=a ;j<=b;j++)
#define IOS ios::sync_with_stdio(false)
#define  UPCASE( c ) ( ((c) >= 'c' && (c) <= 'z') ? ((c) - 0x20) : (c) )
using namespace std;
const double Eps = 1e-8 ;
const double pi  = acos(-1) ;
const long long MOD = 1e9+7 ;
const long long mod = 998244353 ;
typedef long long int ll;
ll powmod (ll a,ll b) {ll res=1;a%=mod; if(b<0) return -1; for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod2(ll a,ll b) {ll res=1;a%=MOD; if(b<0) return -1; for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}



int n , m , k ;
int vis[N][N] ;
int room[N][N];
int dx[4] = {  0 , 0 , 1 , -1 } ;
int dy[4] = { -1 , 1 , 0 ,  0 } ;

void dfs( int x , int y , int step )
{
    vis[x][y] = 1 ;
    if( step == k ) { printf("%d %d\n",x,y) ; return ; }
    qwq( 0 , 3 )
    {
        int cx = x+dx[i] ;
        int cy = y+dy[i] ;
        if( (cx>=1&&cx<=n&&cy>=1&&cy<=m) && !vis[cx][cy] && room[cx][cy] )
        {
            vis[cx][cy] = 1 ;
            dfs( cx , cy , step+1 ) ;
        }
    }
}
void run_1()//如果比较宽
{
    qwq( 1 , m ) if( i&1 ) qeq( 1 , n ) room[j][i]=1 ;
                 else{
                        if( (i/2)&1 ) { qeq( 1 , n-1 ) room[j][i]=0 ; room[n][i]=1 ; }
                        else          { qeq( 2 , n )   room[j][i]=0 ; room[1][i]=1 ; }
                 }

 }
 void run_2()//如果比较长
{
    qwq( 1 , n ) if( i&1 ) qeq( 1 , m ) room[i][j]=1 ;
                 else{
                        if( (i/2)&1 ) { qeq( 1 , m-1 ) room[i][j]=0 ; room[i][m]=1 ; }
                        else          { qeq( 2 , m )   room[i][j]=0 ; room[i][1]=1 ; }
                 }
 }
int main()
{
cin>>n>>m>>k;
    if( (int)(n/2)*(m-1) > (int)(m/2)*(n-1) ) run_1() ;//判断奇数
    else    /*决定构造方法*/  run_2() ;
    printf ("1 1\n") ; //
    dfs( 1 , 1 , 0 ) ;
    qwq( 1 , n ) {
        qeq( 1 , m ) if( room[i][j]==0 ) printf("x") ; else printf(".") ;
        printf("\n");
    }
}
