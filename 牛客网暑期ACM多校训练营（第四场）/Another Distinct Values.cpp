#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n%2==1)
        {
            printf("impossible\n");
            continue;
        }
        printf("possible\n");
        for(int i=1;i<=n;i++)
        {
            if(i<=n/2)
            {
                printf("-1");
                for(int j=2;j<=n/2;j++)
                    printf(" -1");
                for(int j=n/2+1;j<=n-i+1;j++)
                    printf(" 0");
                for(int j=n-i+2;j<=n;j++)
                    printf(" 1");
                printf("\n");
            }
            else
            {
                for(int j=1;j<=n-i;j++)
                    printf("0 ");
                for(int j=n-i+1;j<=n/2;j++)
                    printf("-1 ");
                for(int j=n/2+1;j<=n-1;j++)
                    printf("1 ");
                printf("1\n");

            }
        }
    }
return 0;
}
