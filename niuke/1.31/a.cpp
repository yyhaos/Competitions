#include<bits/stdc++.h>
using namespace std;
double l1,l2;
double lea(double x1,double x2)
{
    return sqrt(x1*x1+x2*x2);
}
int main ()
{
    cin>>l1>>l2;
    int t;
    cin>>t;
    double len=l1+l2;
    double mi=l1-l2;
    if(mi<0)
        mi*=-1.0;
        double x1,x2;
        double tmp;
    while(t--)
    {
        scanf("%lf%lf",&x1,&x2);
        //cout<<x1<<x2;
        tmp=lea(x1,x2);
        //cout<<tmp<<endl;
        if(tmp<=len && tmp>=mi)
        {
            printf("0.00000000000\n");
        }
        else if(tmp>len)
        {
            printf("%.10f\n",tmp-len);
        }
        else
        {
            printf("%.10f\n",mi-tmp);

        }

    }
    return 0;
}
