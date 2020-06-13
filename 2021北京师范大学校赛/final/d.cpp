//Problem Web:http://45.32.27.130/domjudge/team/problems/16/text
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
int ans[1005][1005];
int fx[10],fy[10];
int nxfa[10];
bool dfs(int x,int y,int th1,int th2,int fa){

//cout<<x<<" "<<y<<" "<<th1<<" "<<th2<<" "<<fa<<endl;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            printf("%3d",ans[i][j]);
//          //  printf("%c",s[ans[i][j]] );
//        }
//        printf("\n");
//    }
    int nx,ny;
    nx=x+fx[fa];
    ny=y+fy[fa];
    int fa2=nxfa[fa];
    if(ans[nx][ny]!=0){
        nx=x+fx[fa2];
        ny=y+fy[fa2];
        if(th2==th1+1){
            ans[x][y]=th1;
ans[ fx[fa2]+x ] [ fy[fa2]+y ]=th2;
            return true;
        }
        else {
            ans[x][y]=th1;
//            ans[ fx[fa2]+x ] [ fy[fa2]+y ]=th2+1;
            dfs(nx,ny,th1+1,th2+1,fa2);
        }
    }
    else
    {
        ans[x][y]=th1;
        ans[ fx[fa2]+x ] [ fy[fa2]+y ]=th2;
        dfs(nx,ny,th1+1,th2-1,fa);
        return true;
    }
}

enum fangxiang{zuo,you,shang,xia};

int main ()
{
    nxfa[xia]=zuo;
    nxfa[zuo]=shang;
    nxfa[shang]=you;
    nxfa[you]=xia;
    fx[xia]=1;
    fy[xia]=0;
    fx[shang]=-1;
    fy[shang]=0;
    fx[zuo]=fx[you]=0;
    fy[zuo]=-1;
    fy[you]=1;
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
    string s;
   // int n,m;
    cin>>n>>m;

    cin>>s;
    memset(ans,0,sizeof(ans));
    for(int i=0;i<=n+1;i++)
    {
        ans[i][0]=ans[i][m+1]=-1;
    }
    for(int i=0;i<=m+1;i++)
    {
        ans[0][i]=ans[n+1][i]=-1;
    }






    if(m%2==1)
    {
        printf("QAQ\n");
        return 0;
    }
    printf("QQQ\n");

 dfs( 1,m, 0,n*m-1 ,xia );

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
//            printf("%3d",ans[i][j]);
            printf("%c",s[ans[i][j]] );
        }
        printf("\n");
    }




#ifdef use_t
}
#endif // use_t
    return 0;
}

