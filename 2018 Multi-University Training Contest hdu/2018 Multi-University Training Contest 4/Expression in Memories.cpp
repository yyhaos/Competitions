#include<bits/stdc++.h>
using namespace std;
char str[505];
int type[505];
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int bt=0;
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]=='+'||str[i]=='*')
            {
                type[i]=2;
            }
            else if(str[i]=='0')
                type[i]=0;
            else if(str[i]=='?')
                type[i]=3;
            else
            {
                type[i]=1;
            }
         //   printf("%d-",type[i]);
        }
        int ans=1;
        //printf("%d\n",strlen(str));
        for(int i=0;i<strlen(str);i++)
        {
          //  printf("(%d %d)",bt,type[i]);
            if(bt==0)
            {
                if(type[i]==2)
                {
                    ans=-1;
                    break;
                }
                else if(type[i]==1)
                {
                    bt=1;
                }
                else if(type[i]==0)
                {
                    bt=2;
                }
                else if(type[i]==3)
                {
                    str[i]='1';
                    bt=1;
                }
            }
            else if(bt==1)
            {
                if(type[i]==2)
                {
                    bt=0;
                }
                else if(type[i]==1||type[i]==0)
                {
                    bt=1;
                }
                else
                {
                    str[i]='1';
                    bt=1;
                }
            }
            else if(bt==2)
            {
                if(type[i]==2)
                {
                    bt=0;
                }
                else if(type[i]==3)
                {
                    bt=0;
                    str[i]='+';
                }
                else
                {
                    ans=-1;
                    break;
                }
            }
        }
        if(bt==0)
            ans=-1;
        if(ans==-1)
            printf("IMPOSSIBLE\n");
        else
            printf("%s\n",str);
    }
}
