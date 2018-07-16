#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    int tem;
    int wa=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tem);
        wa+=tem;
        if(wa<0)
            if(-wa>ans)
                ans=-wa;
    }
    printf("%d",ans);
    return 0;
}
