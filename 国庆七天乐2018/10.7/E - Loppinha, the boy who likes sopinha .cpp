#include<bits/stdc++.h>
using namespace std;

/*
贪心
预处理每个连续块分别切1~n次后的最小值
然后每次改动就相当于加了一次切割
那每次新切割就都选影响最大的那个就好了
（最大有好几个的话，就随便选一个就好）

影响最大 就是说 切之前消耗量-切之后消耗量的最大就行了
*/
char str[500];
int a[500][500];
int nu[500];
int k[5050];
int main ()
{
    memset(a,0,sizeof(a));
    memset(nu,0,sizeof(nu));
    memset(k,0,sizeof(k));
    memset(str,0,sizeof(str));
    k[0]=0;
    for(int i=1;i<=500;i++)
    {
        k[i]=i;
    }
    for(int i=2;i<=500;i++)
    {
        k[i]=k[i-1]+k[i];//运动长度为i的消耗
    }
    int n,sk;
    scanf("%d%d",&n,&sk);
    scanf("%s",str);
    int lian=0;
    int cnt=0;
    for(int i=0;str[i];i++)
    {
        if(str[i]=='1')
        {
            lian++;
        }
        else if(lian>0)
        {
            a[cnt++][0]=lian;
            lian=0;
        }
    }
    if(lian>0)
    {
        a[cnt++][0]=lian;
    }
    for(int i=0;i<cnt;i++)
    {
        int chu=a[i][0];
        for(int j=1;j<=chu;j++)//切成j+1块
        {
            a[i][j]=0;
            int th=1;
            int tc=chu-j;//少了j次锻炼
            int cha=tc/(j+1);
            if(cha==0)
            {
                a[i][j]=tc;
                continue;
            }
            int num_cha_1=tc-cha*(j+1);
            int num_cha=j+1-num_cha_1;
            a[i][j]+=num_cha*k[cha];
            a[i][j]+=num_cha_1*k[cha+1];//预处理。注意分块的方法是让每个快大小都差不多。
        }
    }
    for(int i=0;i<cnt;i++)
    {
        a[i][0]=k[a[i][0]];
    }
    int tk=0;
    for(int i=0;i<cnt;i++)
        tk+=a[i][0];
    int tmp=-1,ti;
    memset(nu,0,sizeof(nu));
    for(int an=0;an<=450;an++)
    {
        tmp=0;
        if(tk<=sk)
        {
            printf("%d",an);
            return 0;
        }
        for(int i=0;i<cnt;i++)
        {
            if(tmp<a[i][nu[i]]-a[i][nu[i]+1])//贪心
            {
                tmp=a[i][nu[i]]-a[i][nu[i]+1];
                ti=i;
            }
        }
        nu[ti]++;
        tk-=tmp;
    }

    return 0;
}
