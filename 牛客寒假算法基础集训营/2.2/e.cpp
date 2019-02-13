#include<bits/stdc++.h>
using namespace std;
//int h[tr(i,j)];
int h[1000005];
int n,m,d;
int k[1000005];
int tr(int i,int j)
{
    return i*m+j;
}
int fi(int i ,int j)
{
    i--;
    j--;
    if(i==-1 || j==-1)
    {
        return 0;
    }
    else return k[tr(i,j)];
}
int main ()
{
    cin>>n>>m>>d;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&h[tr(i,j)]);
            if(h[tr(i,j)]>=d)
            {
                h[tr(i,j)]=1;
            }
            else
                h[tr(i,j)]=0;
        }
    }
    k[tr(0,0)]=h[tr(0,0)];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j>0)
            {
                k[tr(i,j)]=k[tr(i,j-1)]+h[tr(i,j)];
            }
            if(i>0 && j==0)
            {
                k[tr(i,j)]=k[tr(i-1,j)]+h[tr(i,j)];
            }
            if(i>0 && j>0)
            {
                k[tr(i,j)]=k[tr(i-1,j)]+h[tr(i,j)]+k[tr(i,j-1)]-k[tr(i-1,j-1)];
            }
        }
    }
    int q;
    cin>>q;
    int x,y,a,b;
    while(q--)
    {
        scanf("%d%d%d%d",&x,&y,&a,&b);
        printf("%d\n",fi(a,b)-fi(a,y-1)-fi(x-1,b)+fi(x-1,y-1));
    }

    return 0;
}
