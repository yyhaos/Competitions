#include<iostream>
#include<math.h>
#include<string>
#include<string.h>
#define rep(a,b,c) for(long long a=b;a<=c;a++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int INF=1000000;
struct stone
{
    double x,y;
}st[1005];
int di(stone a,stone b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int dis[1005];
int d[1005][1005];
int used[1005];
int main ()
{
    //freopen("test.txt","r",stdin);
    int n,k;
    int tt=1;
    int tb;
    cin>>tb;
    while(tb--)
    {
        //scanf("%d",&n);
        mem(used,0);
        rep(i,1,1000)
            rep(j,1,1000)
                d[i][j]=0;

       // cin>>n;
        scanf("%d%d",&n,&k);
        //cout<<"k"<<k<<endl;
        int ts,te,w;
        while(k--)
        {
            scanf("%d%d%d",&ts,&te,&w);
            //cout<<ts<<te<<w<<endl;
            d[ts][te]=w;
            d[te][ts]=w;
        }
        for(int i=2;i<=n;i++)
        {
            dis[i]=d[1][i];
        }
        //cout<<d[2]<<used[2]<<endl;
        dis[1]=0;
        used[1]=1;
        int ans=INF;
        rep(th,1,n)
        {
            int minn=0,minn_dis=0;
            for(int i=2;i<=n;i++)
            {
                if(used[i]==0 && dis[i]>minn_dis)
                {
                    minn=i;
                    minn_dis=dis[i];
                }
            }
            //cout<<minn<<endl;
            used[minn]=1;
            ans=min(ans,dis[minn]);
            for(int i=2;i<=n;i++)
            {
                if(used[i]==0)
                {
                    dis[i]=max(dis[i],min(dis[i],d[i][minn]));
                }
            }
        }
        cout<<"Scenario #"<<tt++<<endl;
        printf("%d:\n\n",dis[n]);
    }
    return 0;
}
