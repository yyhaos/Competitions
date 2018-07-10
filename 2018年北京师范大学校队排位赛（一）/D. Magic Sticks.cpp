#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        if(n<m)
        {
            long long t=n;
            n=m;
            m=t;
        }
        if(n%2LL==1LL)
        {
            cout<<(n+1LL)/2LL*m;
        }
        else if(n%2LL==0LL)
        {
            if(m%2LL==0LL)
                cout<<(n+1LL)*m/2LL;
            else
                cout<<(n+1LL)*(m+1LL)/2LL-n/2LL-1LL;
        }
        cout<<'\n';
    }
    return 0;
}
