#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    scanf("%d",&t);
    int ans=0;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n==1)
            ans--;
        ans++;
    }
    printf("%d\n",ans);
}
