#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double d;
        scanf("%lf",&d);
        if(d==1)
        {
            printf("N\n");
            continue;
        }
        double k=d*d-4*d;
        if(k<-0.00005)
        {
             printf("N\n");
            continue;
        }
        k=sqrt(k);
         printf("Y ");
        double a,b;
        a=(d+k)/2.0;
        b=(d-k)/2.0;
        printf("%.10f %.10f\n",a,b);
    }
    return 0;
}
