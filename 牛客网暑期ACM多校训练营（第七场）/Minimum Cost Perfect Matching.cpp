#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt;
int bi[500005];
void dfs(int n)
{
    //printf("%d\n",n);
    if(n<=0)
        return ;
    int th;
    th=lower_bound(bi+1,bi+1+cnt,n)-bi;
   // printf("%d %d\n",th,bi[th]);
    if(bi[th-1]==n)
    {
        a[n]=0;
        a[0]=n;
        n--;
    }
    int star=bi[th-1];
    for(int i=star;i<n;i++)
    {
        int cha=star-(i-star)-1;
        a[i]=cha;
        a[cha]=i;
    }

    dfs(bi[th]-n);
    return ;
}
int main ()
{
    int n;
    bi[1]=1;
    cnt=0;
    for(int i=1;bi[i]<500000;i++)
    {
        bi[i+1]=bi[i]*2;
        cnt++;
    }
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    dfs(n);
    if(a[0]<=0)
        a[0]=0;
    for(int i=0;i<n;i++)
    {
        if(i!=0)
            printf(" ");
        printf("%d",a[i]);
    }
    return 0;
}
