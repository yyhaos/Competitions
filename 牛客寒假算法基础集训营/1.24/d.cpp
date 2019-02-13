#include<bits/stdc++.h>
using namespace std;
double x[1005];
double y[1005];
double ar[1000005];
double x1,x2,x3,y11,y2,y3;
int n,k;
        double a,b,c,s,p;
int cnt=0;
bool cmp(double a,double b)
{
    return a>b;
}
int main ()
{
    int n;
    int cnt=0;
    cin>>n;
    int k;
    while(n--)
    {
        scanf("%d",&k);
        if(k<60)
            cnt++;
    }
    cout<<cnt*400;
    return 0;
}
