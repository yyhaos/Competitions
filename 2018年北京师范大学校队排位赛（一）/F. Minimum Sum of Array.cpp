#include<bits/stdc++.h>
using namespace std;
int a[100005];
long long k[1000005];
int used[1000005];
int main ()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        long long n;
        for(long long ii=1LL;ii<=1000000LL;ii++)
        {
            k[ii]=ii;
            used[ii]=0;
        }
        cin>>n;

        long long i;
        for(i=0LL;i<n;i++)
        {
            //cin>>a[i];  //never use cin
            scanf("%d",&a[i]);
            used[a[i]]++;
        }
        //sort(a,a+n);
        long long ans=0LL;
        for(long long ii=1LL;ii<=1000000LL;ii++)
        {
            if(used[ii]>0)
            {
                for(long long j=ii;j<=1000000LL;j+=ii)
                {
                    if(used[j]>0LL)
                    {
                        ans+=1LL*used[j]*ii;
                        used[j]=0;
                    }
                }
            }
        }
            cout<<ans;
            cout<<'\n';

    }
    return 0;
}
