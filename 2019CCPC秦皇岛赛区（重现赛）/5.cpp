#include<bits/stdc++.h>
using namespace std;
#define typec int
const int MAXN = 100010;//点数的最大值
const int MAXM = 400010;//边数的最大值
const int INF = 0x3f3f3f3f; struct Edge {  int to,next,cap,flow; }edge[MAXM];//注意是MAXM
int tol; int head[MAXN]; int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
void init()
{
 tol = 0;  memset(head,-1,sizeof(head));
}
//加边，单向图三个参数，双向图四个参数
void addedge(int u,int v,int w,int rw=0) {
printf("lian:%d %d %d %d\n",u,v,w,rw);
 edge[tol].to = v;edge[tol].cap = w;edge[tol].next = head[u];  edge[tol].flow = 0;head[u] = tol++;  edge[tol].to = u;edge[tol].cap = rw;edge[tol].next = head[v];  edge[tol].flow = 0;head[v]=tol++;
}
//输入参数：起点、终点、点的总数
//点的编号没有影响，只要输入点的总数
int sap(int start,int end,int N)
{  memset(gap,0,sizeof(gap));  memset(dep,0,sizeof(dep));  memcpy(cur,head,sizeof(head));  int u = start;  pre[u] = -1;  gap[0] = N;  int ans = 0;  while(dep[start] < N)
 {
  if(u == end)
        {             int Min = INF;             for(int i = pre[u];i != -1; i = pre[edge[i^1].to])                 if(Min > edge[i].cap - edge[i].flow)                         Min = edge[i].cap - edge[i].flow;             for(int i = pre[u];i != -1; i = pre[edge[i^1].to])
            {                 edge[i].flow += Min;                 edge[i^1].flow -= Min;
            }             u = start;             ans += Min;             continue;
        }         bool flag = false;         int v;         for(int i = cur[u]; i != -1;i = edge[i].next)
        {             v = edge[i].to;             if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u])
            {                 flag = true;                 cur[u] = pre[v] = i;                 break;
            }         }         if(flag)         {             u = v;             continue;
        }         int Min = N;         for(int i = head[u]; i != -1;i = edge[i].next)             if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
            {
                Min = dep[edge[i].to];                 cur[u] = i;
            }         gap[dep[u]]--;         if(!gap[dep[u]])return ans;         dep[u] = Min+1;         gap[dep[u]]++;         if(u != start) u = edge[pre[u]^1].to;
 }
 return ans;
}

char str[205][205];
int ss[235],ee[205];

        int n,m,s,e;
int ge(int off,int i,int j)
{
    return off+i*(1+m)+j;
}
int main ()
{
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    init();
//    addedge(3,1,1,1);
//    addedge(4,1,1,1);
//    addedge(1,2,1,1);
//    addedge(5,2,1,1);
//    addedge(6,2,1,1);
//    printf("%d\n",sap(3,5,7));
//    printf("%d\n",sap(3,4,7));
//    printf("%d\n",sap(3,6,7));
//    printf("%d\n",sap(4,5,7));
//    printf("%d\n",sap(4,6,7));
//    printf("%d\n",sap(5,6,7));
//    printf("%d\n",sap(6,5,7));
    while(t--)
    {
        init();
//        ne=2;
//        memset(head,0,sizeof(head));
        scanf("%d%d%d%d",&n,&m,&s,&e);
        for(int i=0;i<n;i++)
        {
            scanf("%s",str[i]);
//            printf("%s\n",str[i]);
        }
        for(int i=0;i<s;i++)
        {
            scanf("%d",&ss[i]);
        }
        for(int i=0;i<e;i++)
            scanf("%d",&ee[i]);
//        printf("%d\n",ee[0]);
        int shang=(n+2)*(m+2)+55;
        int zuo=shang*2;
        int off1=shang*3;
        int off2=shang*4;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char now=str[i][j];
                if(now=='1')
                {
                    continue;
                }
                else
                {
    printf("i:%d j:%d | sh:%d zuo:%d o1:%d o2:%d\n",i,j,ge(shang,i,j),ge(zuo,i,j),ge(off1,i,j),ge(off2,i,j));
//                    printf("%d %d\n",i,j);
                    addedge(ge(shang,i,j),ge(off1,i,j),1,1);
                    addedge(ge(off1,i,j),ge(off2,i,j),1,1);
                    addedge(ge(zuo,i,j),ge(off2,i,j),1,1);
                    if(i+1 >=n || str[i+1][j] =='0')
                    addedge(ge(off2,i,j),ge(shang,i+1,j),1,1);
                    if(j+1 >=m || str[i][j+1]=='0')
                    {
//                        printf("lian: ")
                        addedge(ge(off1,i,j),ge(zuo,i,j+1),1,1);
                    }
                }
            }
        }
        int st=0;int ed=shang*5+1;
//        for(int i=0;i<s;i++)
//        {
//            addedge(ge(shang,n,ss[i]-1),ed,1);
//        }
//        for(int i=0;i<e;i++)
//            addedge(st,ge(shang,0,ee[i]-1),1);
        for(int i=0;i<e;i++)
        {
            addedge(st,ge(shang,0,ee[i]-1),1);
//            printf("s:%d ",ss[i]-1);
        }
        for(int i=0;i<s;i++)
            addedge(ge(shang,n,ss[i]-1),ed,1);

        printf("n:%d m:%d s:%d e:%d st:%d ed:%d\n",n,m,s,e,st,ed);
        int ans=sap(st,ed,ed+3);
        printf("ANS=%d\n",ans);
//        printf("%d %d %d %d %d %d\n",n,m,s,e,st,ed);
        if(ans==e)
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
    return 0;
}
