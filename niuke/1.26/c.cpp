#include<bits/stdc++.h>
using   namespace std;
int main ()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n-1;i++)
    {
        int k=0;
        cin>>k;
        if(ans!=0)
            continue;
        if(k!=i)
        {
            ans=i;
        }
    }
    if(ans==0)
        ans=n;
    cout<<ans;
    return 0;
}
