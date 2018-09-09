#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,m,dis[maxn];
int tot,head1[maxn],head2[maxn];
bool flag[maxn];
struct edge
{
    int to;
    int w;
    int next;
}e[maxn*2],e2[maxn*2];
int buf[40];
struct node
{
    int f;
    int g;
    int from;
    bool operator < (node a)const
    {
        if(a.f==f)
        return g>a.g;
        return f>a.f;
    }
};

template<class T> inline bool getd(T& x)
{
    int ch=getchar();
    bool neg=false;
    if(ch!=EOF && ch!='-' && !isdigit(ch)) ch=getchar();
    if(ch==EOF) return false;
    if(ch=='-'){
        neg=true;
        ch=getchar();
    }
    x=ch-'0';
    while(isdigit(ch=getchar())) x=x*10+ch-'0';
    if(neg) x=-x;
    return true;
}
void add_edge(int u,int v,int w)
{
    tot++;
    e[tot].to=v;
    e[tot].w=w;
    e[tot].next=head1[u];
    head1[u]=tot;
    e2[tot].to=u;
    e2[tot].w=w;
    e2[tot].next=head2[v];
    head2[v]=tot;
}
void spfa(int t)
{
    for(int i=1;i<=n;i++)
    dis[i]=maxn;
    dis[t]=0;
    stack<int> q;
    q.push(t);
    flag[t]=1;
    while(!q.empty())
    {
        int v=q.top();
        q.pop();flag[v]=0;
        for(int i=head2[v];i;i=e2[i].next)
        if(dis[e2[i].to]>dis[v]+e2[i].w)
        {
            dis[e2[i].to]=dis[v]+e2[i].w;
            if(!flag[e2[i].to])
            {
                q.push(e2[i].to);
                flag[e2[i].to]=1;
            }
        }
    }
}
int a_star(int s,int t,int k)
{
    if(s==t) return 0;
    if(dis[s]==maxn) return -1;
    priority_queue<node> q;
    int cnt=0;
    node tmp,to;
    tmp.from=s;
    tmp.g=0;
    tmp.f=tmp.g+dis[tmp.from];
    q.push(tmp);
    while(!q.empty())
    {
        tmp=q.top();
        q.pop();
        if(tmp.from==t) cnt++;
        if(cnt==k) return tmp.g;
        for(int i=head1[tmp.from];i;i=e[i].next)
        {
            to.from=e[i].to;
            to.g=tmp.g+e[i].w;
            to.f=to.g+dis[to.from];
            q.push(to);
        }
    }
    return -1;
}
int main()
{
    int x,y,z,s,t,k,tim;
    while(~scanf("%d%d",&n,&m)){
        memset(head1,0,sizeof(head1));
        memset(head2,0,sizeof(head2));
        tot = 0;
        getd(s);
        getd(t);
        getd(k);
        getd(tim);
        for(int i=1;i<=m;i++)
        {
            getd(x);
            getd(y);
            getd(z);
            add_edge(x,y,z);
        }
        spfa(t);
        if(dis[s]==maxn)
        {
            printf("Whitesnake!\n");
            continue;
        }
        int ans=a_star(s,t,k);
        if (ans<=tim && ans!=-1){
            printf("yareyaredawa");
        }else printf("Whitesnake!");
        putchar('\n');
    }
    return 0;
}
