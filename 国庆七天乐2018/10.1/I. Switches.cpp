#include<bits/stdc++.h>
using namespace std;
int a[1005];
vector <int> s[1005];
int main ()
{
    memset(a,0,sizeof(a));
    int n,m;
    scanf("%d%d",&n,&m);
    int l;int tmp;
    scanf("%d",&l);
    //printf("%d--",l);
    while(l--)
    {

        scanf("%d",&tmp);
        a[tmp]++;
        //printf("%d+ ",tmp);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&l);
        while(l--)
        {
            scanf("%d",&tmp);
            s[i].push_back(tmp);
        }
    }
    int flag=1;
    for(int i=1;i<=2*n+5;i++)
    {
        int ii=i;
        if(ii>n)
        {
            ii-=n;
        }
        if(ii>n)
            ii-=n;
        int si=s[ii].size();
        flag=1;
        for(int j=0;j<si;j++)
        {

            a[s[ii][j]]=1-a[s[ii][j]];
            // printf("%d-%d ",s[ii][j],a[s[ii][j]]);
        }
        for(int i=1;i<=m;i++)
        {
            if(a[i]==1)
                flag=0;
        }
        if(flag==1)
        {
            printf("%d",i);
            break;
        }
    }
    if(flag!=1)
    {
        printf("-1");
    }
    return 0;
}
