#include<bits/stdc++.h>
using namespace std;
int a,b;
int k[100005];
int main ()
{
    int n;
    cin>>n;
    int h=0,t=n-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&k[i]);
    }
    a=b=0;
    while(t>h)
    {
        if(k[t]>k[h])
        {
            a+=k[t];
            t--;
        }
        else
        {
            a+=k[h];
            h++;
        }

        if(k[t]>k[h])
        {
            b+=k[t];
            t--;
        }
        else
        {
            b+=k[h];
            h++;
        }
    }
    cout<<"Applese";
    return 0;
    if(a>b)

    else cout<<"Bpplese";
    return 0;
}
