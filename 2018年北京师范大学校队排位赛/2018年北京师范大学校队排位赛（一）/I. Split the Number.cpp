#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,n;
        cin>>x>>n;
        int th=x/n;
        int s=x%n;
        int flag=1;
        if(th==0)
        {
            printf("-1\n");
            continue;
        }
        for(int i=1;i<=n-s;i++)
        {
            if(flag==1)
            {
                printf("%d",th);
                flag=0;
            }
            else
                printf(" %d",th);
        }
        for(int j=1;j<=s;j++)
        {
            if(flag==1)
            {
                printf("%d",th+1);
                flag=0;
            }
            else
                printf(" %d",th+1);
        }
        printf("\n");
    }
}
