#include<bits/stdc++.h>
using namespace std;
struct ss
{
    int s,th;
}a[16500][14];
bool cmp (ss aa,ss bb)
{
    return aa.s<bb.s;
}
int main ()
{

    int t;
    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {
        memset(a,0,sizeof(a));
        int n;
        scanf("%d",&n);
        for(int j=0;j<1<<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                scanf("%d",&a[j][k].s);
                a[j][k].th=j;
            }
            sort(a[j],a[j]+n,cmp);
        }
        int sum=1<<n;
        while(sum>1)
        {
            sum/=2;
            n-=1;
            for(int i=0;i<sum;i++)
            {
                int t1=2*i;
                int t2=2*i+1;
                int winer,lo;
                if(a[t1][n].s>a[t2][n].s)
                    lo=t2,winer=t1;
                else
                    lo=t1,winer=t2;
               // printf("w=%d %d %d\n",winer,a[winer][0].th,n);

                int sing=0;
                for(int j=0;j<=n;j++)
                {
                    if(a[winer][j].s>a[lo][n].s)
                    {
                        sing=j;
                        break;
                    }
                }
                int tt=0;
                for(int j=0;j<=n;j++)
                {

                    if(j==sing && n!=0)
                        continue;
                    a[winer/2][tt].s=a[winer][j].s;
                    a[winer/2][tt++].th=a[winer][j].th;
                }
            }
        }
        printf("Case #%d: %d\n",ii,a[0][0].th+1);
    }
    return 0;
}
