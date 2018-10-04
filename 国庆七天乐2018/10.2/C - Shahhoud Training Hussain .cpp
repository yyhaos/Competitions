#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long t;
    scanf("%lld",&t);
    while(t--)
    {
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a>b)
            printf("%lld\n",(a-b)*c);
        else

            printf("0\n");
    }
}
