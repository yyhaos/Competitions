#include<bits/stdc++.h>
using namespace std;
struct se
{
    int peo,ra;
}s[5005];
struct building
{
    int p,r,ra;
}b[5005];
int used[5005];
int start[5005];
int n,m;
int ans[5005];
bool cmp(building a,building b)
{
    return a.r<b.r;
}
bool cmp2(se a ,se b)
{
    return a.peo<b.peo;
}
bool find(int th)
{
    for(int i=start[th];i<m;i++)
    {
        //printf("%d %d\n",th,i);
        if(b[i].p<s[th].peo)
            continue;
        else if(used[i]==-1)
        {
            used[i]=th;
            start[th]=i+1;
            ans[s[th].ra]=i;
            return true;
        }
        else if(find(used[i]))
        {
            used[i]=th;
            ans[s[th].ra]=i;
            start[th]=i+1;
            return true;
        }
    }
    return false;
}
int main ()
{
   // memset(used,0,sizeof(used));
    for(int i=0 ;i<=5000;i++)
    {
        used[i]=-1;
        start[i]=0;
    }
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i].peo);
        s[i].ra=i;
    }
    sort(s,s+n,cmp2);
    for(int i=0;i<m;i++)
    {
        b[i].ra=i;
        scanf("%d",&b[i].p);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i].r);
    }
    sort(b,b+m,cmp);
    for(int i=0;i<n;i++)
    {
        if(find(i)==false)
        {
            printf("impossible");
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i)
            printf(" ");
        printf("%d",1+b[ans[i]].ra);
    }
    return 0;
}
