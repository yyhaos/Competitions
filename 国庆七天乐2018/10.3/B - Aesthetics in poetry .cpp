#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b[1005];
int main ()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int flag=-1;
    for(int th=2;th<=n;th++)
    {
       // printf("th=%d\n",th);
        if(n%th==0)
        {
            flag=0;
            memset(b,0,sizeof(b));
            for(int i=1;i<=n;i++)
            {
                b[a[i]%th]++;
            }
            for(int i=0;i<th;i++)
            {
                if(b[i]!=n/th)
                {
                    //printf("%d",i);
                    flag=-1;
                }
            }
            if(flag==0)
                flag=th;
        }
        if(flag>0)
            break;
    }
    printf("%d",flag);
}
