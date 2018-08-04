#include<bits/stdc++.h>
using namespace std;
char str[2005][2005];
int main ()
{
    int n,m;
    int t;
    cin>>t;

    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%s",str[i]);
        }
        int maxn1=n/2,maxn2=m/2;
        for(int i=n/2;i<n;i++)
        {
            if(strcmp(str[i],str[n/2-(i-n/2+1)])!=0)
                maxn1=i;
        }
        for(int i=m/2;i<m;i++)
        {
            int flag=1;
            for(int j=0;j<n;j++)
            {
                if(str[j][i]!=str[j][m/2-(i-m/2+1)])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
                maxn2=i;
        }
        maxn1=n-1-maxn1;
        maxn2=m-1-maxn2;
        int ans=maxn2*maxn1;
        if(ans<=0)
            ans=0;
        printf("%d\n",ans);
    }
    return 0;
}
