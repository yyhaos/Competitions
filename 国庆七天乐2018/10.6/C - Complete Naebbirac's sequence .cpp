#include<bits/stdc++.h>
using namespace std;
int k,n;
int a[10005];
int main ()
{
   // freopen("test.txt","r",stdin);
    //m.clear();
    int out=0;
    memset(a,0,sizeof(a));
    int oud;
    scanf("%d%d",&k,&n);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);

        a[t]++;
    }

        int cd=1;
        int cd2=1;
        int type=1;
        for(int th=0;th<=10000;th++)
        {
//printf("th=%d\n",th);
            if(th*k-1<=n && th*k+1>=n)
            {
               // printf("ddd th=%d\n",th);
                int flag=1;
                if(n==th*k-1)
                {
                    for(int i=1;i<=k;i++)
                    {
                        if(a[i]==th)
                            continue;
                        else if(a[i]>th)
                        {
                            flag=0;
                        }
                        else if(a[i]==th-1 && flag>0)
                        {
                            type=1;
                            cd=i;
                            //flag=1;
                        }
                    }
                }
                if(n==th*k)
                {
                    int cnt=0;
                    int cnt2=0;
                    for(int i=1;i<=k;i++)
                    {
                        if(a[i]==th)
                        {

                            continue;
                        }
                        else if(a[i]>th+1 || a[i]<th-1)
                        {
                            flag=0;
                        }
                        else if(a[i]==th+1 && flag>0)
                        {
                            if(cnt>=1)
                                flag=0;
                            cnt++;
                            type=2;
                            cd=i;
                            //flag=1;
                        }
                        else if(a[i]==th-1 && flag>0)
                        {
                            if(cnt2>=1)
                                flag=0;
                            cnt2++;
                            type=2;
                            cd2=i;
                            //flag=1;
                        }
                    }
                }
                if(n==th*k+1)
                {
                    for(int i=1;i<=k;i++)
                    {
                        if(a[i]==th)
                            continue;
                        else if(a[i]<th)
                        {
                            flag=0;
                        }
                        else if(a[i]==th+1 && flag>0)
                        {
                            type=3;
                            cd=i;
                            //flag=1;
                        }
                    }
                }
                if(flag==1)
                {
                    if(type==1)
                    {
                        printf("+%d",cd);
                    }
                    else if(type==2)
                    {
                        printf("-%d +%d",cd,cd2);
                    }
                    else
                        printf("-%d",cd);
                    return 0;
                }

            }

        }
        printf("*");
    return 0;
}
