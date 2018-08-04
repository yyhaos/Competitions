#include<bits/stdc++.h>
using namespace std;
bool a[3000][3000];
int main ()
{
    int n=47,N=2000;
    printf("2000\n");
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                a[i*n+j][k*n+(j*k+i)%n]=1;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            printf("%d",a[i][j]);
        if(i!=N-1)
            printf("\n");
    }

    return 0;
}

