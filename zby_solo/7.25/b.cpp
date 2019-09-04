
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main ()
{
    ll a[3];
    while(cin>>a[0]>>a[1]>>a[2])
    {
        ll yu=0;
        ll ans=0;
        sort(a,a+3);
        ll sum=a[0]+a[1]+a[2];
        if(a[0]>=2)
        {
            yu=sum-6;
            ans=15+yu*6;
        }
        else if(a[0]==0)
        {
            if(a[1]>=2)
            {
                yu=sum-4;
                ans= 6 +yu*4;
            }
            else if(a[1]==1)
            {
                if(a[2]>=2)
                {
                    yu=sum-3;
                    ans=3+3*yu;
                }
                else
                {
//                    yu=sum-2;
                    ans=1;
                }
//                ans=0+yu*2;
            }
            else
            {
                if(a[2]<=1)
                {
                    ans=0;
                }
                else
                {
                    yu=sum-2;
                    if(yu<0)
                        yu=0;
                    ans=1+2*yu;
                }

            }
        }
        else if(a[0]==1)
        {
            if(a[1]>=2)
            {
                ll yu=sum-5;
                ans= 1+2+3+4 +yu*5;
            }
            else if(a[1]==1)
            {
//                cout<<"-12"<<endl;
                if(a[2]>=2)
                {
                    yu=sum-4;
                    ans=1+2+3+4*yu;
                }
                else
                {
                    ans=3;
                }
//                ans=0+yu*2;
            }
            else
            {
                ll yu=sum-2;
                ans=1+2*yu;
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}
