#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
const double INF=1e18;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(a,b,c) for(int a=b;a<=c;a++)
double dis[1005];
int n,m;
    int s;
    double v;
int cnt;
int ha[1005];
double rab[1005],cab[1005],rba[1005],cba[1005];
int hb[1005];
int vis[1005];
int num[1005];
bool spfa(void)
{
    mem(num,0);
    mem(vis,0);
    mem(dis,0);
    dis[s]=v;
    queue <int> q;
    q.push(s);
    vis[s]=1;
    num[s]++;
    while(!q.empty())
    {
        int tar=q.front();
        //cout<<tar<<endl;
        q.pop();
        vis[tar]=0;
        rep(i,1,m)
        {
            if(ha[i]==tar)
            {
                if(dis[hb[i]]<rab[i]*(dis[tar]-cab[i]))
                {
                    dis[hb[i]]=rab[i]*(dis[tar]-cab[i]);
                    if(vis[hb[i]]==0)
                    {
                        q.push(hb[i]);
                        vis[hb[i]]++;
                        num[hb[i]]++;
                        if(num[hb[i]]>n)
                            return true;
                    }
                }
            }
            else if(hb[i]==tar)
            {
                if(dis[ha[i]]<rba[i]*(dis[tar]-cba[i]))
                {
                    //vis[i]++;
                    dis[ha[i]]=rba[i]*(dis[tar]-cba[i]);
                    if(vis[ha[i]]==0)
                    {
                        q.push(ha[i]);
                        vis[ha[i]]++;
                        num[ha[i]]++;
                        if(num[ha[i]]>n)
                            return true;
                    }
                }
            }
        }
    }
    if(dis[s]>v)return true;
    return false;
}
int main ()
{

    scanf("%d%d%d%lf",&n,&m,&s,&v);
    rep(i,1,m)
    {
        scanf("%d%d%lf%lf%lf%lf",&ha[i],&hb[i],&rab[i],
              &cab[i],&rba[i],&cba[i]);
    }
    if(spfa())
        printf("YES");
    else
        cout<<"NO";
    return 0;
}
