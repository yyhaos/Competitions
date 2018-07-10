#include<stdio.h>
#include<string.h>
int main ()
{
    freopen("test.txt","r",stdin);
    int n,tem_th,sum[10000],flag=1;
    char str[10000][105],tem;
    while(~scanf("%d",&n))
    {
        if(flag!=1)
            printf("\n");
        flag=0;
        //printf("n=%d\n",n);
        if(n<0 || n>100)
            continue;
        scanf("%c",&tem);
        int i=0;
        for(i=1;i<=n;i++)
        {
            tem_th=0;
            while(~scanf("%c",&tem))
            {
                if(tem=='\n')
                {
                    str[i][tem_th]='\0';
                    break;
                }
                else
                {
                    str[i][tem_th++]=tem;
                }
            }
            sum[i]=tem_th;
            //printf("%d len = %d \ str = %s\n",i,sum[i],str[i]);
            if(strcmp(str[i],"stop")==0)
            {
                //printf("stop at %d\n",i);
                n=i-1;
                break;
            }
        }
        //printf("true n = %d\n",n);
        for(i=1;i<=n;i++)
        {
            int min = 99999,min_th=0;
            int j=0;
            for (j=1;j<=n;j++)
            {
                if(sum[j]<=min)
                {
                    min_th=j;
                    min=sum[min_th];
                }
            }
            //printf("%d len = %d str = %s\n",min_th,sum[min_th],str[min_th]);
            printf("%s",str[min_th]);
            if(i!=n)
                printf("\n");
            sum[min_th]=999999;
        }
        n=0;

    }
    return 0;
}
