#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    scanf("%d",&n);
    double ans=0;
    while(n--)
    {
        double tem;
        scanf("%lf",&tem);
        if(tem==0)
            ans+=2;
        else
            ans+=1/tem;
    }
    printf("%lf",ans);
    return 0;
}
