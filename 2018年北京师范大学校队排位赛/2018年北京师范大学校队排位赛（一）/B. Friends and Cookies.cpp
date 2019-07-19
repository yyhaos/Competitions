#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x,n;
        cin>>x>>n;
        long long th=n*2-2;
        if(n==1LL)
        {
              cout<<x;
              if(t)
                cout<<' ';
              continue;
        }

        long long ans[10005];
        memset(ans,0,sizeof(ans));
        long long round=x/th;
        for(long long i=1 ;i<=n;i++)
        {
            if(i==1||i==n)
                ans[i]=round;
            else
                ans[i]=round*2;
        }
        long long r=x%th;
        if(r<=n)
        {
            for(long long i=1;i<=r;i++)
            {
                ans[i]++;
            }
        }
        else
        {
            for(long long i=1;i<=n;i++)
            {
                ans[i]++;
            }
            for(long long i=n+1;i<=r;i++)
            {
                ans[n-(i-n)]++;
            }
        }
        for(long long i=1;i<=n;i++)
        {
            if(i!=1)
            {
                cout<<' '<<ans[i];
            }
            else
                cout<<ans[i];
        }
        if(t)
            printf("\n");
    }
    return 0;
}
