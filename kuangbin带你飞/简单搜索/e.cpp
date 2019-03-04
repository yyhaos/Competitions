#include<stdio.h>
#include <string.h>
#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n;
bool done=false;
void dfs(unsigned __int64  k)
{
    if(done)
        return;
    if(k%n==0)
    {
        printf("%I64u\n",k);
        done=true;
        return ;
    }
    if(k>1000000000000000000)
        return;
    dfs(k*10);
    dfs(k*10+1);
}
int main ()
{
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        done=false;
        dfs(1);
    }
    return 0;
}
