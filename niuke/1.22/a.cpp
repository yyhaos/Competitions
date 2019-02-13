#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k[2][1000005];
int main ()
{
    ll cnt=0;
    ll n,x,o,z;
    cin>>n>>x;
    while(n--)
    {
        cin>>o>>z;
        k[0][cnt]=o;
        k[1][cnt++]=z;
    }
    for(ll i=cnt-1;i>=0;i--)
    {
        switch(k[0][i])
        {
            case 1: x-=k[1][i];
            break;
            case 2: x+=k[1][i];
            break;
            case 3: x/=k[1][i];
            break;
            case 4: x*=k[1][i];
            break;
        }
    }
    cout<<x;
    return 0;
}
