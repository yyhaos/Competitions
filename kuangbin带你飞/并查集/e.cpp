#include<iostream>
#include<string.h>
#include<string>
#include<iterator>
using namespace std;
int f[150005];
const int N=50000;
int fi(int a)
{
    int fa=f[a];
    if(fa!=a)
        return f[a]=fi(fa);
    return a;
}
bool u(int aa,int bb)
{
    for(int k=0;k<=2*N;k+=N)
    {
        int a=(aa+k) %150000;
        int b=(bb+k) %150000;
        if(fi(a)!=fi(b))
        {
            f[fi(a)]=fi(b);
        }
        fi(a);
        fi(b);
    }
    return true;
}
int main ()
{
    //memset(f,0,sizeof(f));
    for(int i=0;i<150000;i++)
    {
        f[i]=i;
    }
    int n,k,ta,tb,ty;
    cin>>n>>k;
    int ans=0;
    while(k--)
    {
        scanf("%d%d%d",&ty,&ta,&tb);
        if(ta>n || ta<=0 || tb>n || tb<=0)
        {
            ans++;
            continue;
        }
        if(ty==1)
        {
            if(fi(ta)==fi(tb+N) || fi(ta)==fi(tb+2*N) || fi(ta+N)==fi(tb) || fi(ta+2*N)==fi(tb))
                ans++;
            else
                u(ta,tb);
        }
        else
        {
            if(fi(ta)==fi(tb) || fi(ta)== fi(tb+N))
                ans++;
            else
            {
                u(ta,tb+2*N);
            }
        }
    }
    cout<<ans;
    return 0;
}
