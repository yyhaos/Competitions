
#include<bits/stdc++.h>
int main ()
{
    int T,n;
    double ans , i;
    char flag;


    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            ans+=1/i;
        }
        printf("%.2f",ans*n);
    }
    return 0;
}
