#include<iostream>
#include<string.h>

using namespace std;
const long long INF=0x7fffffff;
#define rep(a,b,c) for(long long a=b;a<=c;a++)
#define mem(a,b) memset(a,b,sizeof(a))
long long d[1005][1005];
long long dis[1005],used[1005];
int main ()
{
    long long tt;
    cin>>tt;
    long long ans=0;
    rep(ii,1,tt)
    {
        mem(used,0);
        rep(i,1,1000)
            rep(j,1,1000)
                d[i][j]=INF;
        ans=0;
        //cout<<ii<<endl;
        long long n,k,ts,te,w;
        scanf("%lld%lld",&n,&k);
        //cout<<"k"<<k<<endl;
        while(k--)
        {
            scanf("%lld%lld%lld",&ts,&te,&w);
            //cout<<ts<<te<<w<<endl;
            d[ts][te]=w;
            d[te][ts]=w;
        }
        dis[1]=0;
        rep(i,2,n)
            dis[i]=d[1][i];
        used[1]=1;
        while(used[n]==0)
        {
            long long minn,mi=INF;
            rep(i,2,n)
            {
                if(used[i]==0 && dis[i]<mi)
                {
                    minn=i,mi=dis[i];
                }
            }
            ans=max(ans,mi);
            used[minn]=1;
            rep(i,2,n)
            {
                if(used[i]==0)
                {
                    dis[i]=min(dis[i],d[i][minn]);
                    //if(dis[i]<=ans)
                    //    dis[i]=0;
                }
            }
        }
        printf("Scenario #%lld:\n%lld\n\n",ii,ans);
    }
    return 0;
}
