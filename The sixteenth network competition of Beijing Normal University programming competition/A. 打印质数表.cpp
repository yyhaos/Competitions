#include<bits/stdc++.h>
int a[100005];
int main ()
{
    int n ,i ,j ,th;

    scanf("%d",&n);
    memset(a,0,sizeof(a));
    th=1;
    for(i=2;i<=100005 && th<=n ;i++)
    {
        if(a[i]==0)
        {
            printf("%d",i);
            th++;
            if(th<=n)
                printf("\n");
        }
        for(j=1;i*j<=100000;j++)
        {
            a[i*j]=1;
        }

    }
    return 0;
}
