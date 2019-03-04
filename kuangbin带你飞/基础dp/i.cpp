#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <cstdio>
using namespace std;
int a[500000];
int dao[50000];
int main ()
{
    int n;
    while(~scanf("%d",&n))
    {
        int cnt=0,tem;
        memset(dao,0,sizeof(dao));
        //int ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&tem);

                if(cnt==0)
                {
                    dao[cnt++]=tem;
                    //ans++;
                }
                else
                {
                    int minn=999999999;
                    int used=-1;
                    for(int j=0;j<cnt;j++)
                    {
                        int cha=dao[j]-tem;
                        if(cha<0)
                        {
                            continue;
                        }
                        minn=min(minn,cha);
                        if(minn==cha)
                        {
                            used=j;
                        }
                    }
                    if(used==-1)
                    {
                        dao[cnt++]=tem;
                      //  ans++;
                        continue;
                    }
                    else
                    {
                        dao[used]=tem;
                     //   printf("dao : %d %d %d\n",i,used,dao[used]);
                        continue;
                    }
                }

        }
        printf("%d\n",cnt);
    }
    return 0;
}
