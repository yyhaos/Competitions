
#include<cstdio>
#include<iostream>

using namespace  std;

int n,m,k;
int k1()
{
    int sum = 0;
    int minn=min(n/2,k);
    sum+=minn;
    return sum;
}

int k3()
{
    int sum = 0;
    int minn = min(n,min(m,k));
    k-=minn;
    n-=minn;
    m-=minn;
    sum+=minn;
    return sum;
}

int main()
{
    freopen("katryoshka.in","r",stdin);
    int T,a = 0;
    scanf("%d",&T);
    while(T--)
    {
       // freopen("standard output","w",stdout);
        scanf("%d%d%d",&n,&m,&k);
        int sum = 0;
        sum+=k3();
        sum+=k1();
        printf("Case %d: %d\n",++a,sum);
    }
    return 0;
}
