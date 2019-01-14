#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll q=1e9+7;
int main ()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll l,r,d;
        scanf("%lld%lld%lld",&l,&r,&d);
        if(d<l)
        {
            printf("%lld\n",d);
            continue;
        }
        else
        {
            printf("%lld\n",(1LL+r/d)*d);
        }
    }
    return 0;
}
