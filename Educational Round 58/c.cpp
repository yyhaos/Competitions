#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll q=1e9+7;

ll ksm(ll a,ll k)
{
    if(a==0)
        return 0;
    ll ans=1;
    while(k>0)
    {
        if(k%2==1)
        {
            ans=ans*a%q;
        }
        a=a*a%q;
        k/=2;
    }
    return ans;
}
int main ()
{
    int t;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {

    }
    return 0;
}

