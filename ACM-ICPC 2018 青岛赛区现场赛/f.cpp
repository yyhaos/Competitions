#include<bits/stdc++.h>
using namespace std;
int a[2005][2005];
int main ()
{
    int n,k;
    int t;
    for(int i=1;i<=1000;i++)
    {
        a[1][i]=i;
        a[2][i*2]=i*2-1;
        a[2][i*2-1]=i*2;
    }
    int th=1;
    for(int i=2;i<=10;i++)
    {
        th*=2;
        for(int k=1;k<=th;k++)
        {
            int f=k+th;
            //printf("f=%d\n",f);
            for(int p=0;p<=1000/th;p++)
            {
                //cout<<"o+"<<p<<endl;
                if(p%2==0)
                {
                    for(int t=1;t<=th;t++)
                    {
                       // cout<<p*th+t<<endl;
                        a[f][p*th+t]=a[k][p*th+th+t];
                    }
                }
                else
                    for(int t=1;t<=th;t++)
                    {
                       // cout<<p*th+t<<endl;
                        a[f][p*th+t]=a[k][p*th-th+t];
                    }
            }
        }
    }
//    for(int i=1;i<=8;i++)
//        {
//            printf("%d: ",i);
//            for(int j=1;j<=8;j++)
//            {
//                printf("%d ",a[i][j]);
//            }
//            printf("\n");
//        }
    scanf("%d",&t);

    while(t--)
    {

        scanf("%d%d",&n,&k);
        int tn=n;
        if(n%2==1)
        {
            printf("Impossible\n");
            continue;
        }
        //int th=1;
        while(tn%2==0)
        {
            //th++;
            tn/=2;
        }
        tn=n/tn;
        //cout<<tn<<endl;
        if(k>tn-1)
        {
            printf("Impossible\n");
            continue;
        }

        for(int i=1;i<=k;i++)
        {
            printf("%d",i+1);
            for(int j=2;j<=n;j++)
            {
                printf(" %d",a[i+1][j]);
            }
            printf("\n");
        }

    }

    return 0;
}
