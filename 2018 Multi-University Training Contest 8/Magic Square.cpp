#include <bits/stdc++.h>

using namespace std;

char s[5][5];
int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for (int i=1;i<=3;i++){
            scanf("%s",s[i]+1);
        }
        char op[5];
        while(n--){
            scanf("%s",op);
            int q = op[0] - '0';
            char ch = op[1];
            if (q==1){
                if(ch=='C'){
                    char t = s[1][1];
                    s[1][1] = s[2][1];
                    s[2][1] = s[2][2];
                    s[2][2] = s[1][2];
                    s[1][2] = t;
                }
                else{
                    char t = s[1][1];
                    s[1][1] = s[1][2];
                    s[1][2] = s[2][2];
                    s[2][2] = s[2][1];
                    s[2][1] = t;
                }
            }else if(q==2){
                if (ch=='C'){
                    char t = s[1][2];
                    s[1][2] = s[2][2];
                    s[2][2] = s[2][3];
                    s[2][3] = s[1][3];
                    s[1][3] = t;
                }else{
                    char t = s[1][2];
                    s[1][2] = s[1][3];
                    s[1][3] = s[2][3];
                    s[2][3] = s[2][2];
                    s[2][2] = t;
                }
            }else if (q==3){
                if (ch=='C'){
                    char t = s[2][1];
                    s[2][1] = s[3][1];
                    s[3][1] = s[3][2];
                    s[3][2] = s[2][2];
                    s[2][2] = t;
                }else{
                    char t = s[2][1];
                    s[2][1] = s[2][2];
                    s[2][2] = s[3][2];
                    s[3][2] = s[3][1];
                    s[3][1] = t;
                }
            }else if(q==4){
                if (ch=='C'){
                    char t = s[2][2];
                    s[2][2] = s[3][2];
                    s[3][2] = s[3][3];
                    s[3][3] = s[2][3];
                    s[2][3] = t;
                }else{
                    char t = s[2][2];
                    s[2][2] = s[2][3];
                    s[2][3] = s[3][3];
                    s[3][3] = s[3][2];
                    s[3][2] = t;
                }
            }
        }
        for (int i=1;i<=3;i++) printf("%s\n",s[i]+1);
    }
    return 0;
}
