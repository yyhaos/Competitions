#include<string>
#include<string.h>
#include<iostream>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a));
const int INF=999999999;
int n;
#define rep(a,b,c) for(int a=b;a<=c;a++)
int maze[105][105];
int vis[1005];
int dis[1005];
int dige()
{
    int ans=0;
    mem(vis,0);
    rep(i,1,100)
        dis[i]=INF;
    dis[1]=0;

    rep(i,1,n)
    {
        int mi=INF,mi_th;
        rep(j,1,n)
        {
            if(mi>dis[j] && vis[j]==0)
            {
                mi_th=j;
                mi=dis[j];
            }
        }
       // cout<<mi_th<<" ";
       // cout<<dis[mi_th]<<endl;
        vis[mi_th]=1;
        ans+=dis[mi_th];
        rep(j,1,n)
        {
            if(vis[j]==0)
            {
                dis[j]=min(dis[j]-dis[mi_th],maze[j][mi_th]);
            }
        }
    }
    return ans;
}
int main ()
{
   // freopen("test.txt","r",stdin);
    mem(maze,0);

    //int n;
    string tem;
    scanf("%d",&n);
    rep(i,2,n)
    {
        rep(j,1,i-1)
        {
            cin>>tem;
            if(tem[0]=='x')
            {
                maze[i][j]=maze[j][i]=INF;
            }
            else
            {
                maze[i][j]=maze[j][i]=atoi(tem.c_str());
            }
        }
    }
//    rep(i,1,n)
//    {
//        rep(j,1,n)
//        cout<<maze[i][j]<<"\t";
//        cout<<endl;
//    }
    cout<<dige();
    return 0;
}
