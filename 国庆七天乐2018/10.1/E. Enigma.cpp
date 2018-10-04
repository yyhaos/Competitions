#include<bits/stdc++.h>
using namespace std;
char str[10005];
char tar[10005];
int main ()
{
    int ans=0;
    scanf("%s%s",str,tar);
    for(int i=0;str[i];i++)
    {
        int flag=0;
        for(int j=0;tar[j] && str[i+j];j++)
        {
            if(str[i+j]==tar[j])
                break;
            if(str[i+j]=='\0')
                break;
            if(tar[j+1]=='\0')
                flag=1;
        }
        ans+=flag;
    }
    printf("%d",ans);
    return 0;
}
