#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int c[1000005];
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        int ans;
        int n,m;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
        }



        ans=m-n+1;
       // cout<<ans<<endl;
        for(int i=ans-1;i>=0;i--)
        {
            //printf("i=%d\n",i);
            int th=ans-1-i;
            int high=m-1-th;
            int low=n-1;

            c[i]=b[high]/a[low];
            //cout<<high<<" "<<c[i]<<endl;
            for(int j=0;j<n;j++)
            {
                b[high-j]=b[high-j]-a[low-j]*c[i];
                //cout<<high-j<<" "<<b[high-j]<<" "<<a[low-j]<<endl;
            }
        }

        printf("%d\n",ans);
        for(int i=0;i<ans-1;i++)
        {
            printf("%d ",c[i]);
        }
        printf("%d",c[ans-1]);
        if(t)
            printf("\n");
    }
    return 0;
}
