#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,X,hour,minn;
        double tem;
        int Y;
        char str[50];
        scanf("%d %d %s",&a,&b,str);

        int th=1;
        if(str[3]=='-')
            th=-1;

        //scanf("%c",str);
        //printf("tem=%lf\t",tem);
        int r=5;
        X=str[4]-'0';
        if(str[5]>='0' && str[5]<='9')
        {
            X=X*10;
            X+=str[5]-'0';
            r=6;
        }

        if(str[r]=='.')
            Y=str[r+1]-'0';
        else
            Y=0;
        X=X-th*8;
        minn=th*(X*60+Y*6);
       // printf("th=%d\n",th);
        int mi=a*60+b;
        int fi=mi+minn;
       // printf("%d\n",minn);
        if(fi<0)
            fi+=1440;
        fi%=1440;
        a=fi/60;
        b=fi%60;
        //printf("%d:%d UTF(%d)%d.%d",a,b,th,X,Y);
        printf("%02d:%02d\n",a,b);
    }
return 0;
}
