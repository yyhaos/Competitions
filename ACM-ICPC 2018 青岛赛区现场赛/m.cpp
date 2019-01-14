#include<bits/stdc++.h>
using namespace std;
int e[10]={1,0,0,0,1,0,1,0,2,1};
int f(int x)
{
    if(x==0)
        return 1;
    int tx=x,ans=0;
    while(tx>0)
    {
        int th=tx%10;
        tx/=10;
        ans+=e[th];
    }
    return ans;
}
int g(int x,int k)
{
    //cout<<"x:"<<x<<" "<<k<<endl;
    if(k==0)
        return x;
    if(x==0)
    {
        if(k%2==1)
            return 1;
        else
            return 0;
    }
    return g(f(x),k-1);
}
int main ()
{

    int k;
    scanf("%d",&k);
    while(k--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",g(x,y));
    }
}
