#include<bits/stdc++.h>
using namespace std;
struct it
{
    int a,b;
}c[3005];
int q[3005];
bool cmp(it x,it y)
{
    return x.a<y.a;
}
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        int cnt=0;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            c[cnt].a=tmp;
            c[cnt++].b=i;
            scanf("%d",&tmp);
            c[cnt].a=tmp;
            c[cnt++].b=i;
            scanf("%d",&tmp);
            c[cnt].a=tmp;
            c[cnt++].b=i;
        }
        sort(c,c+cnt,cmp);
        for(int i=0;i<=1000;i++)
        {
            q[i]=2;
        }
        int ans=0;
        for(int i=0;k&&i<cnt;i++)
        {
            if(q[c[i].b])
            {
                //printf("%d %d\n",c[i].b,c[i].a);
                k--;
                q[c[i].b]--;
                ans+=c[i].a;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
