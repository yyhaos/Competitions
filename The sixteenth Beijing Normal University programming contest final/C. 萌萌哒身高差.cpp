#include<bits/stdc++.h>
using namespace std;
//Problem   :   http://www.bnuoj.com/v3/problem_show.php?pid=53073
int main ()
{
    int t;
    //freopen("test.txt","r",stdin);
    scanf("%d",&t);
    double a[1066];
    int th=1;
    //memset(a,0,sizeof(a));
    for(int i=0;i<=105;i++)
        a[i]=0;
    a[2]=1;
    a[3]=2;
    int n;
    for(int i = 4 ; i<=1005;i++)
    {
        if((i-1)%3==0)
        {
            th+=2;
        }
        a[i]=a[i-1]+th;
    }
    for(int i = 1; 3*i<105;i++)
    {
        a[i*3]+=2.0/3.0;
    }
    while(t--)
    {
        scanf("%d",&n);
        printf("%.12lf\n",a[n]);
    }
    return 0;
}



