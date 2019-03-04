#include<iostream>
#include<math.h>
#include<string>
#include<string.h>
using namespace std;
const double INF=1e8;
struct stone
{
    double x,y;
}st[1005];
double di(stone a,stone b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double d[1005];
double dis[1005][1005];
int used[1005];
int main ()
{
    //freopen("test.txt","r",stdin);
    int n;
    int tt=1;
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        memset(used,0,sizeof(used));
        int cnt=0;

       // cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf %lf",&st[i].x,&st[i].y);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=di(st[i],st[j]);
            }
        }
        for(int i=2;i<=n;i++)
        {
            d[i]=dis[1][i];
        }
        //cout<<d[2]<<used[2]<<endl;
        d[1]=0;
        used[1]=1;
        double ans=0;
        while(used[2]==0)
        {
            int minn=0,minn_dis=INF;
            for(int i=2;i<=n;i++)
            {
                if(used[i]==0 && d[i]<minn_dis)
                {
                    minn=i;
                    minn_dis=d[i];
                }
            }
            //cout<<minn<<endl;
            used[minn]=1;
            ans=max(ans,d[minn]);
            for(int i=2;i<=n;i++)
            {
                if(i!=minn && used[i]!=1)
                {
                    d[i]=min(d[i],dis[i][minn]);
                }
            }
        }
        cout<<"Scenario #"<<tt++<<endl;
        cout<<"Frog Distance = ";
        printf("%.3f\n\n",ans);
    }
    return 0;
}
