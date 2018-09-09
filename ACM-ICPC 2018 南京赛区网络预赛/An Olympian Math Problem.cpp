#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n;
    int t;
    scanf("%d",&t);
while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",n-1);
        }
/*
        for(n=1;n<=10;n++)
    {
        long long ans=0;
    for(int i=1;i<n;i++)
    {
        int tem=i;
        for(int j=1;j<=i;j++)
        {
            tem*=j;
        }
        ans+=tem;
        }
        printf("%d %lld %lld\n",n,ans,ans%n);
    }*/
    return 0;
}
