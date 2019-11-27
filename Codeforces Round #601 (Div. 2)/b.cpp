
#include<bits/stdc++.h>
using namespace std;
int t;
int main ()
{
    cin>>t;
    while(t--)
    {
        int ans=0;
        int tmp;
        int m,n;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            ans+=tmp*2;
        }
        if(m==n && n!=2)
        {
            printf("%d\n",ans);
            for(int i=1;i<=n;i++)
            {
                printf("%d %d\n",i, i+1 > n? 1 :i+1 );
            }
        }
        else
        {
            printf("-1\n");
        }

    }
}

