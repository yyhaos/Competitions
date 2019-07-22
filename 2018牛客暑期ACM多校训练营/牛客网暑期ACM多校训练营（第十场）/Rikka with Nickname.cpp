#include<bits/stdc++.h>
using namespace std;
int th[28][1000005];
int len;
char str[1000005];
char ans[1000005];
int tem;
int k[28];
bool check(char tar,int start)
{
    int num=tar-'a';
    if (k[tar-'a']==0)
    {
        return true;
    }
    else if(th[tar-'a'][k[tar-'a']-1]<start)
    {
        return true;
    }
    int l=0;
    int r=k[num]-1;
    while(r-l>1)
    {
        int mid=(r+l)/2;
        if(th[num][mid]<start)
        {
            l=mid;
        }
        else
            r=mid;
    }
    if(th[num][l]>=start)
    {
        tem=th[num][l];
        return false;
    }
    else
    {
        tem=th[num][r];
        return false;
    }
}
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(k,0,sizeof(k));
        len=0;
        int n;
        scanf("%d\n",&n);
        for(int i=1;i<=n;i++)
        {
            int start=0;
            scanf("%s",str);
           // printf("%s\n",str);
            if(i==1)
            {
                for(int j=0;str[j];j++)
                {
                    ans[len++]=str[j];
                    int num=str[j]-'a';
                    th[num][k[num]]=len-1;
                    k[num]++;
                }
                continue;
            }

            for(int s=0;str[s];s++)
            {
                if(check(str[s],start))
                {
                    for(int j=s;str[j];j++)
                    {
                        ans[len++]=str[j];
                        int num=str[j]-'a';
                        th[num][k[num]]=len-1;
                        k[num]++;
                    }
                    break;
                }
                else
                {
                    check(str[s],start);
                    start=tem+1;
                    start=tem+1;
                }
            }
        }
        ans[len]='\0';
        printf("%s\n",ans);

    }
    return 0;
}
