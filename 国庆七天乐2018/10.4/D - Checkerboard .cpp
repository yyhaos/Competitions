#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll n,a,b,c,d;
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&c,&d);
    ll e = abs(c-a)+abs(d-b);
    ll ans;
    if (n<e){
        printf("0\n");
        exit(0);
    }
    if (e==0){
        printf("%I64d\n",n/2);
        exit(0);
    }
    ans = (n-e)/2+1;
    printf("%I64d\n",ans);
    return 0;
}