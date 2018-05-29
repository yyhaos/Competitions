#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://www.bnuoj.com/v3/problem_show.php?pid=53077
bool isb(char a)
{
    return a>='A'&&a<='Z';
}
int main ()
{
    int t;
    //freopen("test.txt","r",stdin);
    int th =1,i;
    char s[10]="123";
    char kk=s[3];
    scanf("%d",&t);
    while(t--)
    {
        char tem[50],ans[50];
        for(i= 0 ; i<50;i++)
            ans[i]=kk;
        scanf("%s",tem);
        int flag=0,th=0;
        for(i=0;i<=20;i++)
        {
            if(tem[i]==kk)
            {
                if(i==1)
                    flag=0;
                break;
            }
            else if(i==0)
            {
                if(isb(tem[0]))
                    ans[th++]=tem[0]-'A'+'a';
                else
                    ans[th++]=tem[0];
                continue;
            }
            else if(i==1)
            {
                if(isb(tem[i]))
                {
                    flag=0;
                    break;
                }
            }
            if(isb(tem[i]))
            {
                if(tem[i+1]==kk)
                {
                    flag=0;
                    break;
                }
                else if(isb(tem[i+1]))
                {
                    flag=0;
                    break;
                }
                else
                {
                    //printf("i=%d\n",i);
                    flag=1;
                    ans[th++]='_';
                    ans[th++]=tem[i]-'A'+'a';
                }
            }
            else
            {
                ans[th++]=tem[i];
            }
        }
        //printf("flag=%d\n",flag);
        if(flag==0)
        {
            printf("%s\n",tem);
        }
        else
            printf("%s\n",ans);
    }
}
