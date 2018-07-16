#include<bits/stdc++.h>
using namespace std;
bool isday(int time ,int h,int r,int t)
{
    int hour=time%h;
    if(r<t)
    {
        if(hour>r && hour<t)
            return true;
        else
            return false;
    }
    else
    {
        if(hour<t || hour>r)
            return true;
        else
            return false;
    }
}
int main ()
{
    int h[25],r[25],t[25];
    int n;
    scanf("%d",&n);
    int longest=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
        longest=longest>h[i]?longest:h[i];
        scanf("%d%d",&r[i],&t[i]);
    }
    for(int i=0;i<=1825*longest;i++)
    {
        int flag=1;
        for(int j=1;j<=n;j++)
        {
            if(isday(i,h[j],r[j],t[j]))
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            printf("%d",i);
            return 0;
        }
        else
            continue;
    }
    printf("impossible");
    return 0;
}
