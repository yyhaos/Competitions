#include<cstdio>
#include<iostream>
using namespace std;

char a[4] = {'(',')',')'};

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(n % 2 == 1 && m % 2 == 1)
            for(int i = 1;i<=n;i++)
            {
                for(int j = 1;j<=m;j++)
                    printf("(");
                printf("\n");
            }
        else if(n % 2 == 0 && m % 2 == 1)
            while(n != 0)
            {
                if(n % 2 == 0)
                    for(int i = 1;i<=m;i++)
                        printf("(");
                else
                    for(int i = 1;i<=m;i++)
                        printf(")");
                printf("\n");
                n--;
            }
        else if(n % 2 == 1 && m % 2 == 0)
            while(n--)
            {
                int t = m;
                for(int i = 1;i<=t;i+=2)
                    printf("()");
                printf("\n");
            }
        else
        {
            if(min(n,m)==4)
            {
                if(m == 4)
                {
                    while(n--)
                    {
                        if(n % 2 == 0)
                            printf("(())\n");
                        else
                            printf("()()\n");
                    }
                }
                else
                {
                    for(int i = 1;i<=m;i++)
                        printf("(");
                    printf("\n");
                    for(int i = 1;i<=m;i+=2)
                        printf("()");
                    printf("\n");
                    for(int i = 1;i<=m;i+=2)
                        printf(")(");
                    printf("\n");
                    for(int i = 1;i<=m;i++)
                        printf(")");
                    printf("\n");
                }
            }
            else if(min(n,m) != 2){
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(i==n)
                            printf(")");
                        else if(i==1 && j<=m/2)
                            printf("(");
                        else if(i==1)
                            printf("(");
                        else if(i%2==0)
                        {
                            if(j==1)
                                printf("(");
                            for(int k=1;k<=(m-2)/2;k++)
                                printf("()");
                            printf(")");
                            break;
                        }
                        else
                        {
                            if(j==1)
                                printf("(");
                            for(int k=1;k<=(m-2)/2;k++)
                                printf(")(");
                            printf(")");
                            break;
                        }
                    }
                    printf("\n");
                }
            }
            else{
                if(n==2)
                {
                    for(int i = 1;i<=m;i++)
                        printf("(");
                    printf("\n");
                    for(int i = 1;i<=m;i++)
                        printf(")");
                    printf("\n");
                }
                else
                {
                    for(int i = 1;i<=n;i++)
                        printf("()\n");
                }
            }
        }
    }
    return 0;
}
