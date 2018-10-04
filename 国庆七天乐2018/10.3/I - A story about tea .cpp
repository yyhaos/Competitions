#include<bits/stdc++.h>
using namespace std;
int first=1;
void trans(char a,char b,char c,int n)
{
    if(n==1)
    {
        if(first==1)
        {
            first=0;
            printf("%c %c\n",a,b);
            printf("%c %c\n",b,c);
        }
        else
            printf("%c %c\n",a,c);
        return ;
    }

    trans(a,c,b,n-1);

    trans(a,b,c,1);

    trans(b,a,c,n-1);
    return ;
}
int main ()
{
    //trans('A','B','C',1);
    int n,m;
    scanf("%d%d",&n,&m);
    if(m<(1<<n)-1)
        printf("N");
    else
    {
        printf("Y\n");
        int cha=m-(1<<n)+1;
        int k=cha/2;
        while(k--)
        {
            printf("A B\n");
            printf("B A\n");
        }
        if(cha%2==1)
        {
            first=1;
        }
        else
            first=0;
        trans('A','B','C',n);
    }
}
