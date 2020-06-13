//Problem Web:http://45.32.27.130/domjudge/team/problems/16/text
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll t,n,m;
int ans[1005][1005];
int fx[10],fy[10];
int nxfa[10];
bool dfs(int x,int y,int th1,int th2,int fa){
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
    string s;
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
            printf("%c",s[ans[i][j]] );
        }
        printf("\n");
    }
    return 0;
}


