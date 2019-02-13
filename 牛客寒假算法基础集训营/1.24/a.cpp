#include<bits/stdc++.h>
using namespace std;
double x[1005];
double y[1005];
double ar[1000005];
double x1,x2,x3,y11,y2,y3;
int n,k;
        double a,b,c,s,p;
int cnt=0;
bool cmp(double a,double b)
{
    return a>b;
}
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {


        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&x[i],y+i);
        }

        cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    x1=x[i];
                    x2=x[j];
                    x3=x[k];
                    y11=y[i];
                    y2=y[j];
                    y3=y[k];
                    a =sqrt((x1-x2)*(x1-x2)+(y11-y2)*(y11-y2));
         b =sqrt((x1-x3)*(x1-x3)+(y11-y3)*(y11-y3));
        c =sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        p = (a + b + c)/2;
        s =sqrt(p*(p-a)*(p-b)*(p-c));
                if(s>0.000001)
                    ar[cnt++]=s;
                }
            }
        }
//        for(int i=0;i<cnt;i++)
//        {
//            cout<<ar[i]<<endl;
//        }
        sort(ar,ar+cnt,cmp);
     //   cout<<ar[k-1];
        if(k-1<cnt)
        printf("%.2f\n",ar[k-1]);
        else
            printf("0.00\n");
    }
    return 0;
}
