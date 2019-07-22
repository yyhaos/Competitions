#include<bits/stdc++.h>
using namespace std;
int c[100005];
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int ans=sqrt(abs(a[n]-a[1]));
        printf("%d\n",ans);
    }
    return 0;
}
