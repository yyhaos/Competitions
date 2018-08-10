#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1e6+7;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n;
        scanf("%lld",&n);
        if( n%3 == 0)
            printf("%lld\n",1ll*(n/3)*(n/3)*(n/3));
        else if(n%4 == 0)
        {
            long long k = n/4;
            printf("%lld\n",1ll*k*k*2*k);
        }
        else
            printf("-1\n");
    }
    return 0;
}
