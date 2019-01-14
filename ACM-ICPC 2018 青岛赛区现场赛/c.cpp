#include<bits/stdc++.h>
using namespace std;
char a[10000005];
char b[10000005];
void tr(char &a)
{
    if(a=='1')
        a='0';
    else
        a = '1';
}
int main ()
{
    int n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",a);
        scanf("%s",b);
        for(int i=0;i<n;i++)
            if(b[i]=='1')
                tr(a[i]);
        int k=0,th=0,flag=0;
        int k1=k;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='1' && flag==0)
            {
                th++;
                flag=1;
                k++;
            }
            else if(flag==1 && a[i]=='1')
            {
                k++;
            }
            else if(a[i]=='0' && flag==1)
            {
                flag=0;
                k1=k;
                k=0;
            }
        }
        //cout<<th<<" "<<k1<<endl;
        if(th==1)
        {
            printf("%d\n",2*(n-1));
        }
        else if(th==2)
            printf("6\n");
        else if(th==0)
            printf("%d\n",n*(n+1)/2);
        else
            printf("0\n");
    }
}
