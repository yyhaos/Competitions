
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll q=998244353;
ll ksm(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%q;
        }
        a=a*a%q;
        b/=2;
    }
    return ans%q;
}
int main ()
{
    ll tt;
    cin>>tt;
    while(tt--)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;

        ll ans=0;


        ans=ksm(2,a)*d %q *ksm(2,c) %q;// x 1
        ans+=ksm(2,a)*(ksm(2,c)-1)%q; // x 0
        ans%=q;
        ans+=ksm(2,a)*b%q*(ksm(2,c)-1)%q;// x 1
        ans%=q;
        ans+=ksm(2,a)*ksm(2,b)%q;// 0 x

        cout<<ans%q<<"\n";
    }


    return 0;
}
