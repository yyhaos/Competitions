
#include<bits/stdc++.h>
using namespace std;
char str[20005];
char str2[20005];
#define ll long long
int main ()
{
     #ifdef yyhao
    freopen("in.txt","r",stdin);
    #endif // yyhao
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        scanf("%s%s",str,str2);
        ll dif=0;
        ll pos1=-1,pos2;
        for(int i=0;str[i];i++){
            if(str[i]!=str2[i])
            {
                if(pos1==-1)
                    pos1=i;
                else
                    pos2=i;
                dif++;
            }
        }
        if(dif == 1 || dif >=3)
            printf("No\n");
        else
        {
            if(dif==0)
            {

                printf("Yes\n");
            }
            else
            {
                if(str[pos1] == str[pos2] && str2[pos2]==str2[pos1])
                    printf("Yes\n");
                else
                    printf("No\n");
            }
        }
    }
    return 0;
}
