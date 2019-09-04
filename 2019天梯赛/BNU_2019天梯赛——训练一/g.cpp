//Problem Web:https://vjudge.net/contest/288637#problem/G

#include<stdio.h>

char tr(char a)
{
    if(a=='A')
        return '1';
    if(a=='B')
        return '2';
    if(a=='C')
        return '$';
    if(a=='D')
        return 10;
    return a;
}
int t,n,m;
char a[2000];
char b[2000];
int main ()
{
    //freopen("in.txt","r",stdin);
int i;

    gets(a);
    //printf("1122$21$1\n12");
    //return 0;
    for( i=0;a[i]!='\0';i++)
    {
        if(a[i]=='A')
            b[i]='1';
        else if(a[i]=='B')
            b[i]='2';
        else if(a[i]=='C')
            b[i]='$';
        else if(a[i]=='D')
            b[i]='\n';
        //else b[i]=a[i];
        //printf("%c",a[i]);
    }
    b[i]='\0';
    if(i==0)
    {
 printf("\n");
        return 0;

    }

    for(i=0;b[i]!='\0';i++)
    {
        putchar(b[i]);
    }
  // printf("\n");

    return 0;
}
