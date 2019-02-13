#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main ()
{
    double n,m,d,x;
    cin>>n>>m>>d>>x;
    if(d!=0)
    {
        double  ans=((d/2.0-n)+sqrt((n-d/2.0)*(n-d/2.0)+2.0*d*m))/d;
        int a=floor(ans+0.99999999);
        cout<<a;
    }
    else
    {
        double ans=(m/n);
        int a=floor(ans+0.9999999);
        cout<<a;
    }
    return 0;
}
