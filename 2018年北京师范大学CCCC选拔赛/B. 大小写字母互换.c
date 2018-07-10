
#include<stdio.h>
int main ()
{
    char tem;
    while(~scanf("%c",&tem))
    {
        if(tem=='\n')
            break;
        if(tem<='z' &&tem>='a')
            printf("%c",tem+'A'-'a');
        else if(tem<='Z' &&tem>='A')
            printf("%c",tem-'A'+'a');
        else
            printf("%c",tem);
    }
    return 0;
}
