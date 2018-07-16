#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    while(n--)
    {
        long long tem;
        cin>>tem;
        if(tem%2LL==0)
            tem--;
        printf("%d",tem);
        if(n!=0)
            printf(" ");
    }
    return 0;
}
