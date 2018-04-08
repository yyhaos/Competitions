#include<bits/stdc++.h>
int main ()
{
    int T,x,y,ans;
    char flag;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&x,&y);
        if((x-y+60)%60>=(y-x+60)%60)
        {
            flag='+';
            ans=((y-x)+60)%60;
        }
        else if((x-y+60)%60<(y-x+60)%60)
        {
            flag='-';
            ans=((x-y)+60)%60;
        }
        if(ans==0)
        {
            printf("%d\n",ans);
        }
        else
            printf("%c%d\n",flag,ans);
    }
    return 0;
}
