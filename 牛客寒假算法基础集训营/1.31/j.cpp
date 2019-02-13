#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll q=998244353LL;
ll fi(ll n)
{

    ll ans=0;
    for(int i=0;i<(1<<n);i++)
    for(int j=i+1;j<(1<<n);j++)
    {
        if(i==j)
            continue;
        if((i+j)==(i|j))
        {
          //  cout<<i<<" "<<j<<endl;
            ans++;
        }
    }
    ans*=2LL;
    for(int i=0;i<(1<<n);i++)
       // for(int i=0;i<(1<<n);i++)
    {
        if(i+i==(i|i))
        {
            ans++;
        }
    }
    return ans;
}
ll ksm(ll m)
{
    ll ans=1;
    ll di=1LL;
    for(ll i=0;i<m;i++)
    {
        di=di*3LL%q;
    }
    return di;
}
int main ()
{
    ll ai=7;
    ll k;
    cin>>k;
    cout<<ksm(k);

    return 0;
}
