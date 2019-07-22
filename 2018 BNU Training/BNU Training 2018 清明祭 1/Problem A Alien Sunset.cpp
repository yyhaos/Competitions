
#include<bits/stdc++.h>
using namespace std;
struct planet
{
    int day;
    int sunrise;
    int sunset;
};
bool isnight(int time,struct planet plt)
{
    int hour = time%plt.day;
    if(plt.sunrise<plt.sunset)
    {
        //printf("%d \n",hour);
        if(hour<=plt.sunrise || hour >=plt.sunset)
            return true;
        else return false;
    }
    else
    {
        if(hour<=plt.sunrise && hour >= plt.sunset)
            return true;
        else return false;
    }
}
int main ()
{
    int N;
    scanf("%d",&N);
    struct planet planet2[25];
    const int maxn=24*1825;
    for(int i = 0 ; i<N;i++)
    {
        scanf("%d%d%d",&planet2[i].day,&planet2[i].sunrise,&planet2[i].sunset);
    }
    int flag;
    for(int i=0;i<=maxn;i++)
    {
        flag=-2;
        for(int j=0;j<N;j++)
        {
            if(isnight(i,planet2[j])==false)
                flag=-1;
        }
        if(flag!=-1)
        {
            flag=i;
            break;
        }
    }
    if(flag>=0)
        printf("%d",flag);
    else
        printf("impossible");
}
