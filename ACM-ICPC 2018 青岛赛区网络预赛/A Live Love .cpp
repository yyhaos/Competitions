#include <bits/stdc++.h>
using namespace std;
int main ()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n,m;
    scanf("%d%d",&n,&m);
    if(n==m)
        printf("%d %d\n",n,n);
    else if(m==0)
        printf("0 0\n");
    else
    {
        int ans;
        for(ans=0;ans<=m;ans++)
        {
            if((ans+1)*(n-m+1)<=n)
                continue;
            else break;
        }
        //ans--;
        if(ans==0)
            ans=1;
        printf("%d %d\n",m,ans);
    }
  }
}
