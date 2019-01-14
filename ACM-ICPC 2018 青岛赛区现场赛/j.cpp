#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll p[100005];
int num_books(ll money)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(money>= p[i])
        {
            money-=p[i];
            ans++;
        }
    }
    return ans;
}
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m;
        scanf("%d%d",&n,&m);
        int z=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&p[i]);
            if(p[i]==0)
                z++;
        }
        if(z>m)
        {
            printf("Impossible\n");
            continue;
        }
        else if(m==n)
        {
            printf("Richman\n");
            continue;
        }
        ll ans=0;
        ll minn=99999999999999LL;
        int tar=m-z;
        for(int i=0;i<n;i++)
        {
            if(p[i]>0 && tar>0)
            {
                ans+=p[i];
                tar--;
            }
            else if(tar==0 && p[i]>0)
            {
                minn=min(minn,p[i]);
            }
        }
        ans+=minn-1;
        printf("%lld\n",ans);
        /*
        ll l=0,r=100000LL*1000000003LL,mid;
        //cout<<r;
        while(r>l+1)
        {
            mid=(r+l)/2LL;
            if(num_books(mid)>m)
            {
                r=mid;
            }
            else
                l=mid;
        }
        ll ans=l;
        for(ll i=r;i>=l;i--)
        {
            if(num_books(i)==m)
            {
                ans=i;
                break;
            }
        }
        if(z>m)
            printf("Impossible\n");
        else if(m==n)
            printf("Richman\n");

        else
            printf("%lld\n",ans);
            */
    }
    return 0;
}
