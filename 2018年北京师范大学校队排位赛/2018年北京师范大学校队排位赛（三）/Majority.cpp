#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t,num[10005];

    int maxn=-1,ma=0;
    scanf("%d",&t);
    while(t--)
    {
        maxn=-1;

        for(int i=1;i<=1005;i++)
        {
            num[i]=0;
        }
        int n;
        cin>>n;
        int tem;
        while(n--)
        {
            cin>>tem;
            num[tem]++;
        }
        for(int i=1000;i>=1;i--)
        {
            if(num[i]>=maxn)
            {
                ma=i;
                maxn=num[i];
            }
        }
        printf("%d\n",ma);
    }
    return 0;
}
