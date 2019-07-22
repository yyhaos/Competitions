#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long n,p2,p3;
    scanf("%lld%lld%lld",&n,&p2,&p3);
    long long sum = 0;
    if(n<=2)
        sum = min(p2,p3);
    else{
    if(3*p2<2*p3){
        long long k = n/2;
        sum+=k*p2;
        n-=k*2;
        if(n==1){
            sum=min(sum+p2,sum-p2+p3);
        }
    }
    else if(3*p2>2*p3){
        long long k = n/3;
        sum+=k*p3;
        n-=k*3;
        if(n == 1){
                sum = min(sum-p3+2*p2,sum+min(p2,p3));
        }
        else if(n == 2){

            sum=min(sum+min(p2,p3),sum-p3+3*p2);
        }
    }
    else{
        long long k = n/2;
        sum = k*p2;
        n -= 2*k;
        if(n == 1)
            sum = sum-p2+p3;
    }
    }
    printf("%lld\n",sum);
    return 0;
}
