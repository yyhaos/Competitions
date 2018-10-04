#include<bits/stdc++.h>
using namespace std;
int n;
char a[15][15][15];
int ka[300][15];
char ans[15][256];
bool has(char *tar,char *place)
{
    int now=0;
    int l2=strlen(place);
    for(int i=0;i<l2;i++)
    {
        if(place[i]==tar[now])
        {
            now++;
        }
        else
            continue;
    }
    if(now==strlen(tar) && now>0)
        return true;
    else
        return false;
}
int main ()
{
    memset(ka,0,sizeof(ka));
    for(int th=1;th<=8;th++)
    {
        int k=1<<th;
        for(int i=1;i<=256;i+=k)
        {
            for(int j=0;j<k/2;j++)
                ka[i+j][th]=1;
        }
    }
    for(int i=1;i<=256;i++)
    {
        for(int j=1;j<=8;j++)
            ka[i][j]=1-ka[i][j];
    }
    /*
    for(int i=1;i<=256;i++)
    {
        for(int j=1;j<=8;j++)
            printf("%d ",ka[i][j]);
        printf("\n");
    }*/
    while(~scanf("%d",&n))
    {
        memset(ans,0,sizeof(ans));
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",a[i][1]);
            for(int k=2;k<=strlen(a[i][1]);k++)
            {
                for(int j=0;j<strlen(a[i][1]);j++)
                {
                    int tk=k-1;
                    a[i][k][j]=a[i][1][(j+tk )% strlen(a[i][1])];
                }
                a[i][k][strlen(a[i][1])]='\0';
                //if(has("abs",a[i][k]))
                //printf("ok %s\n",a[i][k]);
            }
        }
        int le=strlen(a[1][1]);
        //printf("%d\n",le);
        for(int i=1;i<=le;i++)
        {
            for(int th=1;th<=(1<<le);th++)
            {
               // printf("%d-th=%d\n",i,th);
                char tm[10];
                int cnt=0;
                for(int k=1;k<=le;k++)
                {
                    if(ka[th][k]==1)
                        tm[cnt++]=a[1][i][k-1];
                    else
                        continue;
                }
                tm[cnt]='\0';
               // printf("%s\n",tm);
                int aa=1;
                for(int ii=2;ii<=n;ii++)
                {
                    if(aa==0)
                        break;
                    int flag=0;
                    int l2=strlen(a[ii][1]);
                    for(int k=1;k<=l2;k++)
                    {
                        if(has(tm,a[ii][k]))
                        {
                            //printf("%d -- %d\n",ii,k);
                            flag=1;
                        }
                    }
                    if(flag==0)
                        aa=0;
                }
                if(aa==1)
                {
                    ans[i][th]=1;
                    //printf("%d-%s ok\n",i,tm);
                }
            }
        }
       // printf("finish\n");
       int over=1;
    int ml=0;
    char an[10]="";
    for(int i=8;i>=1 && over;i--)
    for(int j=256;j>=1&& over;j--)
    {
        if(ans[i][j]==1)
        {
            char tm[10];
            int cnt=0;
            for(int k=1;k<=le;k++)
            {
                if(ka[j][k]==1)
                    tm[cnt++]=a[1][i][k-1];
                else
                    continue;
            }
            tm[cnt]='\0';
            if(cnt>ml)
            {
                for(int i=0;i<=cnt;i++)
                    an[i]=tm[i];
                ml=cnt;
            }
            //printf("%s Vs %s %d\n",an,tm,cnt);
            if(cnt == ml && strcmp(an,tm)>0)
            {
                for(int i=0;i<=cnt;i++)
                    an[i]=tm[i];
            }
        }
    }
    if(strlen(an)>0)
    printf("%s\n",an);
    else
        printf("0\n");
}
    return 0;
}
