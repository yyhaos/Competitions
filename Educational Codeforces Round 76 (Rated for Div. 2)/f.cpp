#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int a,b;
void dfs(int x){

    printf("%c",'A'+x%26);
    if(x>=26)
    {
        dfs(x/26);
    }
}
int main ()
{
    freopen("in.txt","r",stdin);
    cin>>n;
    getchar();
    while(n--)
    {
        getchar();
        scanf("%d",&a);
        getchar();
        scanf("%d",&a);
        printf("R");
        dfs(a-1);
        printf("C");
        dfs(b-1);
        printf("\n");
    }
}
