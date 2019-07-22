#include<iostream>
#include<cstdio>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int k;
        scanf("%d",&k);
        if(k == 1)
            printf("5\n");
        else
            printf("%d\n",7+k-2);
    }
    return 0;
}
