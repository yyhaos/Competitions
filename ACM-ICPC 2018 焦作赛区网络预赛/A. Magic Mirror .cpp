#include<bits/stdc++.h>
using namespace std;
char str[100];
char ned[100];
int main ()
{
    int t;
    scanf("%d",&t);
    memset(ned,0,sizeof(ned));
    ned[0]='j';
    ned[1]='e';
    ned[2]='s';
    ned[3]='s';
    ned[4]='i';
    ned[5]='e';
    ned[6]='\0';
    while(t--)
    {
        scanf("%s",str);
        int n=strlen(str);
        for(int i=0;i<n;i++)
        {
            if(str[i]>='A' && str[i]<='Z')
                str[i]=str[i]+'a'-'A';
        }
        int flag=1;
        if(n!=6)
            flag=0;

        for(int i=0;i<=n;i++)
        {
            if(str[i]!=ned[i])
                flag=0;
        }
        if(!flag)
            printf("Dare you say that again?\n");
        else
            printf("Good guy!\n");
    }
    return 0;
}
