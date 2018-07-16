#include<bits/stdc++.h>
using namespace std;
int main ()
{
    map <string,int > m;
    m["red"]=1;
    m["yellow"]=2;
    m["green"]=3;
    m["brown"]=4;
    m["blue"]=5;
    m["pink"]=6;
    m["black"]=7;
    int N;
    int ans=0;
    cin>>N;
    int num_red=0;
    int num_other=0;
    int num[10];
    string tem;
    int maxn=0;
    memset(num,0,sizeof(num));
    while(N--)
    {
        cin>>tem;
        num[m[tem]]++;
        maxn=m[tem]>maxn?m[tem]:maxn;
    }
    if(maxn==1)
    {
        printf("1");
        return 0;
    }
   // for(int i=1;i<=7;i++)
       // printf("%d ",num[i]);
    ans+=num[1]*(1+maxn);
    for(int i=2;i<=7;i++)
    {
        ans+=i*num[i];
    }
    printf("%d",ans);
    return 0;
}
