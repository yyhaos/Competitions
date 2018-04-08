#include<bits/stdc++.h>
using namespace std;
//Problem : http://www.bnuoj.com/v3/problem_show.php?pid=53080
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,flag=1;
        scanf("%d",&n);
        while(n--)
        {
            char tem[50];
            scanf("%s",tem);
            if(tem[0]!='P')
                flag=0;

        }
        if(flag==0)
            printf("NAIVE Noob\n");
        else
            printf("MILLION Master\n");
    }
}
