#include<bits/stdc++.h>
using namespace std;
struct num{
    int n,tar;
}a[15];
//int a[15];
int first[15];
int f(int x)
{
    printf("ff%d %d %d\n",x,a[x].tar,first[a[x].n]);
    int fa;
    if(a[x].tar==first[a[x].n])
        return a[x].tar;
    fa=a[x].tar;
    return a[x].tar=f(fa);
}
char str[15];
int len=0;
void se(int kk)
{
    int maxn=a[0].n;
    int flag=-1,pos=0;
    for(int j=0;j<len;j++)
    {

        flag=-1;
        pos=j;
        maxn=a[j].n;
        for(int i=j+1;i<len;i++)
        {
            if(maxn<=a[i].n && a[i].n>a[j].n)
            {
                pos=i;
                maxn=a[i].n;
                flag=1;
            }
        }
        if(f(pos)==f(j))
        {
            swap(a[pos],a[j]);
            continue;
        }
        else
            a[f(j)].tar=f(pos);
        f(j);
        swap(a[j],a[pos]);
            for(int i=0;i<len;i++)
            {
                    for(int k=0;k<len;k++)
                    {
                        if(f(i)!=f(k))
                            continue;
                        if(k>i)
                        {
                            if(a[k].n>a[i].n&& (i!=0 || a[k].n!=0) &&(k!=0 || a[i].n!=0))
                            {
                                swap(a[i],a[k]);
                            }
                        }
                        if(k<i)
                        {
                            if(a[k].n<a[i].n && (i!=0 || a[k].n!=0) &&(k!=0 || a[i].n!=0))
                            {
                                swap(a[i],a[k]);
                            }
                        }
                    }

            }

        kk--;
        if(kk==0)
            break;
    }
    return ;
}
void se2(int kk)
{

    int maxn;
    int flag=-1,pos=0;
    for(int j=0;j<len;j++)
    {
        for(int i=0;i<strlen(str);i++)
        {
            printf("%d",a[i].n);
        }
        printf("\n");

        flag=-1;
        pos=j;
        maxn=a[j].n;
        for(int i=j+1;i<len;i++)
        {
            if(j==0 && a[i].n==0)
                continue;
            if(maxn>=a[i].n && a[i].n<a[j].n)
            {
                pos=i;
                maxn=a[i].n;
                flag=1;
            }
        }
        printf("%d-%d-%d %d\n",j,pos,f(j),f(pos));
        if(f(pos)==f(j))
        {
            swap(a[j],a[pos]);
            continue;
        }
        else
            a[f(j)].tar=f(pos);
        f(j);
        swap(a[j],a[pos]);
        printf("\n%d %d %d\n",f(j),f(pos),999);
            for(int i=0;i<len;i++)
            {
                    for(int k=0;k<len;k++)
                    {
                        printf("%d-%d\n",i,k);
                        if(f(i)!=f(k))
                            continue;

                        if(k>i)
                        {
                            if(a[k].n<a[i].n && (i!=0 || a[k].n!=0) &&(k!=0 || a[i].n!=0))
                            {
                                swap(a[i],a[k]);
                            }
                        }
                        if(k<i)
                        {
                            if(a[k].n>a[i].n && (i!=0 || a[k].n!=0) &&(k!=0 || a[i].n!=0))
                            {
                                swap(a[i],a[k]);
                            }
                        }
                    }
            }
        printf("0000\n");
        kk--;
        if(kk==0)
            break;
    }
    return ;
}
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k;
        scanf("%s%d",str,&k);
        len=strlen(str);
        //int first[15];
        memset(first,-1,sizeof(first));
        for(int i=0;i<strlen(str);i++)
        {
            a[i].n=str[i]-'0';
            //a[i].tar=i;
            if(first[a[i].n]==-1)
            {
                first[a[i].n]=i;
            }
            a[i].tar=first[a[i].n];
        }
        se2(k);
        memset(first,-1,sizeof(first));
        for(int i=0;i<strlen(str);i++)
        {
            printf("%d",a[i].n);
        }
        printf(" ");
        for(int i=0;i<strlen(str);i++)
        {

            a[i].n=str[i]-'0';
            if(first[a[i].n]==-1)
            {
                first[a[i].n]=i;
            }
            a[i].tar=first[a[i].n];
        }
        se(k);
        for(int i=0;i<strlen(str);i++)
        {
            printf("%d",a[i].n);
        }
        printf("\n");
    }
    return 0;
}
