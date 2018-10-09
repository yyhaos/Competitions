#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int a[10];
    for(int i=1;i<=6;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i=1;i<=3;i++)
    {
        if(a[i+3]>a[i])
            ans+=a[i+3]-a[i];
    }
    printf("%d",ans);
    return 0;
}
