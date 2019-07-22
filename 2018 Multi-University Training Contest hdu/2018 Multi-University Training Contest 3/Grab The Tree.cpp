#include<bits/stdc++.h>
using namespace std;
int w[100005];
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int flag=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&w[i]);
            start=start^w[i];
        }
        int t1,t2;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d",&t1,&t2);
        }
        if(start>0)
        {
            printf("Q\n");
        }
        else
            printf("D\n");
    }
    return 0;

}
