
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("lazy.in","r",stdin);
    //freopen("standard output","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int tem;
        int ans=0;
        scanf("%d",&tem);
        while(tem!=1)
        {
            ans+=tem/2;
            if(tem%2==1)
                tem=tem/2+1;
            else
                tem=tem/2;
        }
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
