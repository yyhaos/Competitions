#include<bits/stdc++.h>
using namespace std;
double k[2*131072+100];
int main ()
{
    int ans=1;
    for(int i=1;i<=18;i++)
    {
        //printf("%d:%d ",i,ans);
        ans*=2;
    }

    //freopen("test.txt","rb",stdin);
    memset(k,0,sizeof(k));
    int n;
    scanf("%d",&n);
    for(int i=131072;i<=131072+n-1;i++)
    {
        //printf("%d",i);
        scanf("%lf",&k[i]);
    }
    int l=131072;
    int r=2*131072-1;
    while(l<r)
    {
        //printf("lr=%d %d\n",l,r);
        for(int j=l;j<=r;j++)
        {
            k[j/2]+=k[j];
        }
        r=l-1;
        l=l/2;
    }
    /*
    for(int i=1;i<=2*n-1;i++)
    {
        printf("%d:%llf\t",i,k[i]);
    }
    */
    int m;
    int type;
    scanf("%d",&m);
    int t1,t2;
    double tem;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&type);
       // printf("%type=%d\n",type);
        if(type==1)
        {
            scanf("%d %lf",&t1,&tem);
            t1+=131072-1;
            double cha=-k[t1]+tem;
            while(t1>0)
            {
                k[t1]+=cha;
                t1/=2;
            }
        }
        else
        {
            scanf("%d%d",&t1,&t2);
            double cc=t2-t1+1.0;
            t1=131072-1+t1;
            t2=131072-1+t2;
            if(t1==t2)
            {
                printf("%lf\n",k[t1]);
                continue;
            }

            double a1=0,a2=k[t2];
            while(t1>0)
            {
                //printf("%d\n",t1);
                if(t1%2==1)
                {
                    a1+=k[t1-1];
                }
                t1/=2;
            }
            while(t2>0)
            {
                if(t2%2==1)
                {
                    a2+=k[t2-1];
                }
                t2/=2;
            }
            //printf("%lf %lf ",a1,a2);
            printf("%lf\n",(a2-a1)/cc);
        }
    }
    /*
    for(int i=1;i<=2*n-1;i++)
    {
        printf("%d:%llf\t",i,k[i]);
    }
    */
    return 0;
}
