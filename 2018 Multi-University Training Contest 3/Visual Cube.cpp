#include<bits/stdc++.h>
using namespace std;
int main ()
{
    //freopen("test.txt","r",stdin);
    int t;
    cin>>t;
    int a,b,c;


    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        for(int i=1;i<= 2*c+1+2*b;i++)
        {
            if(i!=1)
                printf("\n");
            for(int j=1;j<=b*2+2*a+1;j++)
            {
                if(i<=2*b)
                {
                    if(j<=2*b-i+1)
                        printf(".");
                    else if(i%2==1 )
                    {
                        if( j>2*b+2*a+2- i+2*c && i>2*c+1)
                            printf(".");
                       else if(j<= 2*a+1+2*b-i)
                        {
                            if(j%2==1)
                            printf("+");
                            else
                                printf("-");
                        }
                        else
                        {
                            if(j%2==0)
                            printf(".");
                            else
                                printf("+");
                        }
                    }
                    else
                    {
                        if( j>2*b+2*a+2- i+2*c && i>2*c+1)
                            printf(".");
                        else if(j<= 2*a+1+2*b-i)
                        {
                            if(j%2==1)
                                printf(".");
                            else
                                printf("/");
                        }
                        else
                        {
                            if(j%2==0)
                                printf("/");
                            else
                                printf("|");
                        }
                    }

                }
                else
                {
                    if(j<=2*a+1)
                    {
                        if(i%2==1)
                        {
                            if(j%2==1)
                            {
                                printf("+");
                            }
                            else
                                printf("-");
                        }
                        else
                        {
                            if(j%2==1)
                            {
                                printf("|");
                            }
                            else
                                printf(".");
                        }
                    }
                    else
                    {
                        if( j>2*b+2*a+2- i+2*c && i>2*c+1)
                            printf(".");
                        else
                        {
                            if(i%2==1)
                            {
                                if(j%2==1)
                                {
                                    printf("+");
                                }
                                else
                                    printf(".");
                            }
                            else
                            {
                                if(j%2==1)
                                {
                                    printf("|");
                                }
                                else
                                    printf("/");
                            }
                        }
                    }
                }
            }

        }
        printf("\n");
    }
    return 0;
}
