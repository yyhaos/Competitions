
#include<bits/stdc++.h>
using namespace std;
#define ll long long
char str[20005];
char str2[20005];
ll cnt[300];
//            char tar[525];
int op[2][205];
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
        memset(cnt,0,sizeof(cnt));
        int n;
        cin>>n;
        scanf("%s%s",str,str2);
        ll dif=0;
        ll pos1=-1,pos2;
        for(int i=0;str[i];i++){
            cnt[str[i]]++;
            cnt[str2[i]]++;
        }
        int fa=1;
        for(int i='a';i<='z';i++){
            if(cnt[i]%2==1){
        fa=0;
            }
        }
        if(fa==0)
        {
            printf("No\n");
        }
        else
        {
//            int cc=0;
//            for(int i='a';i<='z';i++){
//                for(int j=0;j<cnt[i];j+=2){
//                    tar[cc++]=i;
//                }
//            }
//            tar[n]=0;
//            printf("%s\n",tar);
            printf("Yes\n");
            int ccc=0;
            for(int i=0;i<n;i++){
                if(str[i]==str2[i])
                {

                }
                else
                {
                    for(int j=i+1;j<n;j++){
                        if(str2[j]==str2[i]){
                            //printf("%d %d\n",i+1,j+1);
                            op[0][ccc]=i+1;
                            op[1][ccc++]=j+1;
                            swap(str2[j],str[i]);
                            break;
                        }
                    }
                    if(str[i]!=str2[i])
                    {
                        for(int j=i+1;j<n;j++){
                            if(str[j]==str2[i]){
//                                printf("%d %d\n",j+1,n);
                            op[0][ccc]=j+1;
                            op[1][ccc++]=n;
                                swap(str[j],str2[n-1]);
                            op[0][ccc]=i+1;
                            op[1][ccc++]=n;
//                                printf("%d %d\n",i+1,n);
                                swap(str[i],str2[n-1]);
                                break;
                            }
                        }
                    }
                }
            }
            if(ccc==0)
            {
                op[0][ccc]=1;
                op[1][ccc++]=1;
            }
            printf("%d\n",ccc);
            for(int i=0;i<ccc;i++){
                printf("%d %d\n",op[0][i],op[1][i]);
            }
        }

//        for(int i=0;str[2])

    }
    return 0;
}

