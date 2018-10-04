#include<bits/stdc++.h>
int main ()
{
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        if(a%2==1 && b%2==1 && c%2==1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
