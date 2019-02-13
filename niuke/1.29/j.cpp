#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1);
int main ()
{
    double a,b;
    cin>>a>>b;
    double ar;
    cin>>ar;
    double kk=ar*PI/180.0;
    printf("%.10f",sqrt(a*a+b*b+2.0*a*b*cos(kk)));
    //cout<<);
    return 0;
}
