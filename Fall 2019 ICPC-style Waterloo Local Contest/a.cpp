#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main ()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll gc=__gcd(a,b);
    ll lcm=a*b/gc;
    gc=__gcd(lcm,c);
    lcm=lcm*c/gc;
//    gc=__gcd(lcm,3LL);
//    lcm=lcm*3/gc;
    ll pice=__gcd(a,__gcd(b,c));

    cout<<lcm/pice<<"\n";
    ll fen[5];
    fen[1]=lcm/a/pice;
    fen[2]=lcm/b/pice;
    fen[3]=lcm/c/pice;

    for(int i=1;i<=lcm/pice;i++)
    {
        printf("%lld",1LL);
        for(int j=1;j<=3;j++)
        {
            printf(" %lld",(i-1)/fen[j]+1);
        }
        printf("\n");
    }
    return 0;
}
