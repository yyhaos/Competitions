#include<iostream>
#include<string.h>
#include<stdio.h>
#include<map>
using namespace std;
int n;
int main ()
{
    int t,len;
    scanf("%d",&t);
    //cstring ;
    char s1[105],s2[105],tem[205],s3[205];
    map<string,int> m;
    int ans,cnt;
    for(int ii=1;ii<=t;ii++)
    {
        ans=-1;
        m.clear();
        scanf("%d",&n);
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s3);
        len=0,cnt=0;
        while(1)
        {
            len=0;
            cnt++;
            for(int i=0;i<n;i++)
            {
                tem[len++]=s2[i];
                tem[len++]=s1[i];
            }
            tem[len]='\0';
            //printf("%d %s\n",cnt,tem);
            if(strcmp(tem,s3)==0)
            {
                ans=cnt;
                break;
            }
            if(m[tem]>0)
            {
                ans=-1;
                break;
            }
            m[tem]=1;
            for(int i=0;i<n;i++)
            {
                s1[i]=tem[i];
                s2[i]=tem[i+n];
            }
        }
        printf("%d %d\n",ii,ans);
    }
    return 0;
}
