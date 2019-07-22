#include<bits/stdc++.h>
#include<map>
using namespace std;
int main ()
{
    map<string,int> ball = {
        {"red"      ,1},
        {"yellow"   ,2},
        {"green"    ,3},
        {"brown"    ,4},
        {"blue"     ,5},
        {"pink"     ,6},
        {"black"    ,7} };
    //printf("%d\n",ball["red"]);
    int n;
    scanf("%d",&n);
    string tem;
    int score[10];
    memset(score,0,sizeof(score));
    while(n--)
    {
        cin>>tem;
        score[ball[tem]]++;
    }
    int ans=0,maxn=0;
    for(int i = 2 ;i<=8;i++)
    {
        if(score[i]!=0)
        {
            ans+=i;
            maxn=i;
        }
    }
    ans+=(1+maxn)*score[1];
    printf("%d",ans);
    return 0;
}
