#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x;
ll a[2005];
ll mi[2005][2005];
int main ()
{
    cin>>n>>x;
    for(ll i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        mi[i][0]=a[i];
    }
    ll jin,cnt;

    for(ll j=1;j<n;j++)
    {
        for(ll i=0;i<n;i++)
        {
            jin=(i-j+n)%n;
            mi[i][j]=min(mi[i][j-1],mi[jin][0]);
        }
    }
    ll tmp=0;
    ll ans=99999999999999LL;
    for(ll k=0;k<n;k++)
    {
        tmp=0;
        for(int i=0;i<n;i++)
        {
            tmp+=mi[i][k];
        }
        ans=min(ans,k*x+tmp);
    }
    cout<<ans;
    return 0;

}
