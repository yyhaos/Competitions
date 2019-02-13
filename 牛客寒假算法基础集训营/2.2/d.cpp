#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100005];
int main ()
{
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    long long ans=0;
    long long cnt=0;
    for(long long i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            cnt+=a[i];
        }
        else
        {
            ans+=cnt/2;
            cnt=0;
        }
    }
    ans+=cnt/2;
    cout<<ans;
    return 0;
}
