#include<bits/stdc++.h>
using namespace std;

const int maxn = 10005;

struct member{
    char name[10];
    int c;
}G[maxn];

int cmp(member a,member b){
    return a.c > b.c;
}

int main()
{
    int n,d,k;
    scanf("%d%d%d",&n,&d,&k);
    for(int i = 0;i<n;i++){
        scanf("%s%d",&G[i].name,&G[i].c);
    }
    sort(G,G+n,cmp);
    long long sum = 0;
    int flag = 0;
    int p;
    for(int i = 0;i<k;i++){
        sum += G[i].c;
        if(sum >= d){
            flag = 1;
            p = i;
            break;
        }
    }
    if(flag == 0)
        printf("impossible\n");
    else{
        printf("%d\n",p+1);
        for(int i = 0;i<=p;i++)
            printf("%s, YOU ARE FIRED!\n",G[i].name);
    }
    return 0;
}
