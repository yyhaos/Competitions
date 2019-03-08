//Problem Web:  http://fastvj.rainng.com/contest/239087#problem/P
//#include<bits/stdc++.h>
//#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define crep(i,x,y) for(int i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
#define use_t 1
//const double PI=acos(-1.0);
const double eps=1e-8;
const int INF = 100000000;
const int maxn=1000;
const int q=1e9+7;

const int CE=100001;
int t,n,m,c;
vector <pr<int,int>> M[200005];
int dis[CE*2+5];
int ceng[CE+5];
int cc[CE+5];
struct node
{
    int t,d;
    node (int tt, int dd)
    {
        t=tt;
        d=dd;
    }
    friend bool operator <(node a, node b)
    {
        return a.d>b.d;
    }
};
bool vis[CE*2+5];
void Di()
{
    mem(vis,0);
    rep(i,1,2*CE)
    {
        dis[i]=1090000001;
    }
   // cout<<dis[0]<<" "<<dis[1]<<endl;
    priority_queue<node> pq;
    while(!pq.empty())
        pq.pop();
    pq.push(node(1,0));
    while(!pq.empty())
    {
        node top=pq.top();
        pq.pop();
        if(vis[top.t])
            continue;
        vis[top.t]=1;
//        cout<<top.t<<" "<<top.d<<endl;
//        rep(i,1,n)
//        {
//            cout<<dis[i]<<" ";
//        }
//        cout<<endl;

        dis[top.t]=min(dis[top.t],top.d);
        for(int i=0;i<M[top.t].size();i++)
        {
            int v=M[top.t][i].first;
            int cost=M[top.t][i].second;
            if(dis[v]>dis[top.t]+cost && vis[v]==0)
            {
                dis[v]=dis[top.t]+cost;
                pq.push(node(v,dis[v]));
            }
        }
    }
}
int ksm(int a,int b)
{
    int ans=1;
    while(b>0)
    {
        if(b&1)
            ans=ans*a%q;
        a=a*a%q;
        b/=2;
    }
    return ans;
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
int ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t
    cin>>n>>m>>c;
    mem(cc,0);
    mem(ceng,0);
    rep(i,1,2*CE+1)
    {
        M[i].clear();
    }
    rep(i,1,n)
    {
        scanf("%d",ceng+i);
        cc[ceng[i]]++;
        M[ceng[i]+CE].push_back(mp(i,0));

        if(ceng[i]>1)
        {
            M[i].push_back(mp(CE+ceng[i]-1,c));
           // M[ceng[i]+CE-1].push_back(mp(ceng[i]+CE,c));  // memory exceed
          //  M[ceng[i]+CE].push_back(mp(ceng[i]-1+CE,c));
        }
        if(ceng[i]<n)
        {
            M[i].push_back(mp(CE+ceng[i]+1,c));
         //   M[ceng[i]+CE+1].push_back(mp(ceng[i]+CE,c));
        //    M[ceng[i]+CE].push_back(mp(ceng[i]+CE+1,c));
        }
    }
    rep(i,1,CE-1)
    {
        if(cc[i] && cc[i+1])
        {
            M[i+CE].push_back(mp(i+1+CE,c));
            M[i+CE+1].push_back(mp(i+CE,c));
        }
    }
    int u,v,w;
    rep(i,1,m)
    {
        scanf("%d%d%d",&u,&v,&w);
        M[u].push_back(mp(v,w));
        M[v].push_back(mp(u,w));
    }
    Di();

    int ans=dis[n];
    if(dis[n]>1090000000)
        ans=-1;
    printf("Case #%d: %d\n",ii,ans);

#ifdef use_t
}
#endif // use_t
    return 0;
}
