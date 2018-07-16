#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    long long a[200005];
    long long ans=0LL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        ans+=a[i];
    }
    int th1=n-1,th2=n;
    long long r=0LL;
    while(ans!=r)
    {
        //printf("%lld-%d %lld-%d\n",ans,th1,r,th2);
        if(ans==0||th1==-1)
        {
            ans=0;
            break;
        }
        if(ans>r)
        {
            ans-=a[th1];
            th1--;
            if(ans==r)
            {
                break;
            }
            else if(ans>r)
            {
                th2--;
                r+=a[th2];
                if(ans==r)
                    break;
            }
        }
        if(ans==r)
            break;
        if(ans<r)
        {
            r-=a[th2];
            th2++;
            if(ans==r)
                break;
        }
    }
    printf("%lld",ans);
    return 0;
}
