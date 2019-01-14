#include<bits/stdc++.h>
using namespace std;
int a[1000];
int used[10000];
int main ()
{
    memset(used,0,sizeof(used));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>=n)
            a[i]=n-1;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
    }
    if(sum<2*(n-1))
    {
        printf("NO");
        return 0;
    }
    else
    {
        int len=0;int cha=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=2)
                len++;
            else
                cha++;
        }
        if(cha>=2)
            printf("YES %d\n",len+2-1);
        else
            printf("YES %d\n",len+cha-1);
        printf("%d\n",n-1);
        int pre=-1;
        int first=-1;
        int last=-1;
        if(len>=2)
            for(int i=1;i<=n;i++)
            {
               //cout<<i<<endl;
                if(a[i]<=1)
                    continue;
                if(pre==-1)
                {
                    first=i;
                    pre=i;
                    last=pre;
                }
                else
                {
                    printf("%d %d\n",pre,i);
                    used[pre]++;
                    pre=i;
                    last=pre;
                    used[i]++;
                }
            }


        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                if(used[first]==1)
                {
                    used[first]++;
                    printf("%d %d\n",first,i);
                }
                else if(used[last]==1)
                {
                    used[last]++;
                    printf("%d %d\n",last,i);
                }
                else
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(a[j]-used[j]>=1 && a[j]>=2)
                        {
                            printf("%d %d\n",j,i);
                            used[j]++;
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
