#include<bits/stdc++.h>
using namespace std;
long long n,m;

int main ()
{
    long long ans;
    cin>>n>>m;
    n=n-6*m;
    if(n<0)
    {
        ans=-1;
    }
    else if(n>3*m)
    {
        ans=-1;
    }
    else
    {
        if(n<m)
        {
            ans=m-n;
        }
        else ans=0;
    }
    if(ans==-1)
        cout<<"jgzjgzjgz";
    else
        cout<<ans;
    return 0;
}
