#include<bits/stdc++.h>
using namespace std;
struct p
{
    int t,th;
}ts[2005];
bool cmp(p a,p b)
{
    if(a.t!=b.t)
        return a.t>b.t;
    else
        return a.th<b.th;
}
int main ()
{
    int n,m;
    cin>>n>>m;
    int a[2005];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&ts[i].t);
        ts[i].th=i;
    }
    sort(ts,ts+n,cmp);
    int ans=0;
    for(int i=0;i<m;i++)
    {
        ans+=ts[i].t;
        a[i]=ts[i].th;
    }
    printf("%d\n",ans);
    sort(a,a+m);
    //ans=1;
    for(int i=0;i<m;i++)
    {
        if(m==1)
        {
            printf("%d",n);
            return 0;
        }
        if(i==0)
            printf("%d",1+a[i]);
        else if(i<m-1)
            printf(" %d",a[i]-a[i-1]);
        else
            printf(" %d",n-1-a[i-1]);
    }


    return 0;
}
