#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct pp
{
    ll s,k;
    friend bool cmp(pp a,pp b);
}p[100005];
ll sum=0;
bool cmp(pp a, pp b)
{
    if((sum-a.k)*a.s==(sum-b.k)*b.s)
    {
        return a.s>b.s;
    }
    return (sum-a.k)*a.s<(sum-b.k)*b.s;
}

int main ()
{
    ll n;
    cin>>n;

    for(ll i=0;i<n;i++)
    {
        scanf("%lld%lld",&p[i].s,&p[i].k);
        sum+=p[i].k;
    }
    ll ans=0;
    sort(p,p+n,cmp);
    for(ll i=0;i<n;i++)
    {
        cout<<p[i].s<<" "<<p[i].k<<endl;
        sum-=p[i].k;
        ans+=sum*p[i].s;
    }
    cout<<ans;
}
