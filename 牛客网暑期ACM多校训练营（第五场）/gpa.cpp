#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100005;
const double eps = 1e-6;
double s[maxn],c[maxn],d[maxn],a[maxn];
int n,k;
bool check(double x){
    for(int i = 1;i<=n;i++)
        d[i] = a[i]-x*s[i];
    sort(d+1,d+n+1);
    double sum = 0;
    for(int i = k+1;i<=n;i++)
        sum+=d[i];
    if(sum >= 0.0)
        return true;
    return false;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
        scanf("%lf",&s[i]);
    for(int i = 1;i<=n;i++){
        scanf("%lf",&c[i]);
        a[i] = s[i]*c[i];
    }
    double l = 0,r = 1e9,m;
    while((r-l)>eps){
        m = (l+r)/2;
        if(check(m)) l = m;
        else r = m;
    }
    printf("%.11f\n",l);
}
