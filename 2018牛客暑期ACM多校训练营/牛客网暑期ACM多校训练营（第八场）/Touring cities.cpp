#include<iostream>
#include<cstdio>
using namespace std;
 
typedef struct{
    int x1,y1,x2,y2;
}edge;
 
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        edge G[k+1];
        int len = 0;
        for(int i = 0;i<k;i++){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(a == c && b == d)
                continue;
            G[len++] = {a,b,c,d};
        }
        if(n%2 == 0 || m%2 == 0)
            printf("%d\n",n*m);
        else{
            int flag = 0;
            for(int i = 0;i<len;i++){
                if((G[i].x1 + G[i].y1)%2 == 0 && (G[i].x2 + G[i].y2)%2 == 0){
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                printf("%d\n",n*m+1);
            else
                printf("%d\n",n*m);
        }
    }
    return 0;
}