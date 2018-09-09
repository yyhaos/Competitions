#include<bits/stdc++.h>
using namespace std;
char str[1000005];
int main  ()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        scanf("%d",&n);
        char tt;
        char stt[10];
        scanf("%s",stt);
        tt=stt[0];

        scanf("%s",str);
        int ans=0;
        int first=0;
            for(int i=0;i<n;i++)
            {
               // printf("%d-%d\n",tt-str[i],first);
                if(first==0)
                {
                    if(tt==str[i])
                        continue;
                    if(0+tt-str[i]<10 && 0+tt-str[i]>-10)
                    {
                        first=1;
                        ans+=1;
                    }
                    else
                    {
                        ans+=2;
                        first=1;
                    }
                }
                else
                    ans+=2;
            }
            if(ans==0)
                ans=1;
            printf("%d\n",ans);
    }
    return 0;

}
