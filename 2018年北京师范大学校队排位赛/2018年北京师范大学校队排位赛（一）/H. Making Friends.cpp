#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t,ma;
    int h[2005];
    scanf("%d",&t);
    while(t--)
    {
        ma=-1;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++)
        {
            scanf("%d",h+i);
        }
        for(int i=1;i<=n;i++)
        {
            if(ma<h[i]+h[2*n-i+1])
                ma=h[i]+h[2*n-i+1];
        }
        printf("%d\n",ma);
    }
    return 0;
}
