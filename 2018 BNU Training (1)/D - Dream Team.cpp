
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 10007;

typedef struct
{
    int u,v;
    int w;
}edge;

int pre[maxn];
int find(int X)
{
    if(X == pre[X])
        return X;
    return pre[X] = find(pre[X]);
}

void init(int N)
{
    for(int i = 1;i<=N;i++)
        pre[i] = i;
}

int gcd(int a,int b)
{
    if(b!=0)
        return gcd(b,a%b);
    return a;
}

int cmp(edge X,edge Y)
{
    return X.w>Y.w;
}

int pd(int N)
{
    int sum = 0;
    for(int i = 1;i<=N;i++)
    {
        if(pre[i] == i)
            sum++;
        if(sum == 2)
            return 0;
    }
    return 1;
}

int main()
{
    freopen("dream.in","r",stdin);
    int T,K = 0;
    cin>>T;
    while(T--)
    {
        int N;
        scanf("%d",&N);
        int a[N+1];
        for(int i = 1;i<=N;i++)
            scanf("%d",&a[i]);
        init(N);
        edge E[maxn];
        int len = 0;
        for(int i = 1;i<=N-1;i++)
            for(int j = i+1;j<=N;j++)
            {
                E[len].u = i;
                E[len].v = j;
                E[len++].w = gcd(a[i],a[j]);
            }
        sort(E,E+len,cmp);
        int sum = 0;
        for(int i = 0;i<len;i++)
        {
            int u = E[i].u;
            int v = E[i].v;
            if(find(u) != find(v))
            {
                pre[pre[u]] = pre[v];
                sum += E[i].w;
            }
            if(pd(N) == 1)
                break;
        }
        printf("Case %d: %d\n",++K,sum);
    }
    return 0;
}
