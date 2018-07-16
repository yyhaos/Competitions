#include<bits/stdc++.h>
using namespace std;
long long h(char str[8])
{
    //printf("%s:%d\n",str,a)
    long long th=1;
    long long a=0;
    for(int i=0;i<8;i++)
    {
        a+=str[i]*th;
        th*=27LL;
    }
    return a;
}
map<long long,int> m;
char n1[1000005][8];
char n2[1000005][8];
bool used[1000005];
int main ()
{
    int t;
    scanf("%d",&t);
    int N;
    int first;
    for(int ii=1;ii<=t;ii++)
    {
        m.clear();
        memset(n1,0,sizeof(n1));
        memset(n2,0,sizeof(n2));
        if(ii!=1)
            printf("\n");
        scanf("%d",&N);
        first=1;
        for(int i=0;i<N;i++)
        {
            used[i]=false;
        }
        for(int i=0;i<N;i++)
        {
            scanf("%s",n1[i]);
            m[h(n1[i])]=i;
        }
        for(int i=0;i<N;i++)
        {
            scanf("%s",n2[i]);
        }
        int cnt=0;
        int ans=0;
        int th2=0;
        for(int i=0;i<N;i++)
        {
            used[m[h(n1[i])]]=true;
            cnt++;
            ans++;
            while(used[m[h(n2[th2])]])
            {
                cnt--;
                th2++;
                if(cnt==0)
                {
                    if(first==1)
                        printf("%d",ans);
                    else
                        printf(" %d",ans);
                    first=0;

                    ans=0;
                }
                if(th2>N)
                    break;
            }
            if(th2>N)
                    break;
        }
        //printf("\n");
    }
    return 0;
}
