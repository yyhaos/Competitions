#include<bits/stdc++.h>
using namespace std;
int is(int i)
{
    if(i>=0)
        return i;
    else
        return 0;
}
struct aa
{
    int y,n;
}a[505];
bool cmp(aa t1,aa t2)
{
    if(t1.n+t1.y!=t2.n+t2.y)
        return t1.n+t1.y<t2.n+t2.y;
    else
        return t1.y>t2.y;
}
int used[505];
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(used,0,sizeof(used));
        int n,m,tem,t1,t2,ans=0;
        scanf("%d%d",&n,&m);
        int zu=m;
        int j;
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i].y,&a[i].n);
        sort(a,a+n,cmp);
        while(zu>0)
        {
            for(j=0;j<n;j++)
            {
                if(a[j].n<zu && used[j]==0)
                {
                    used[j]=1;
                    break;
                }
            }
            if(j==n)
                break;
            t1=a[j].y;
            t2=a[j].n;
            //printf("%d %d %d\n",t1,t2,zu);
            if(zu>t2)
                ans++;
            int z=zu;
            zu=zu/(t1+t2);
            if(z%(t1+t2)>t2)
                zu++;
            //printf("%d %d %d\n",t1,t2,zu);
        }
        printf("%d\n",ans);
    }
    return 0;
}
