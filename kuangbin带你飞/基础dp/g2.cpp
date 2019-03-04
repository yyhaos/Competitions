#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
int n,dp[100005][11],maxi;
int ins[100005][11];
void DP(){
   dp[0][5]=0;
   for(int i=0;i<=maxi;i++)
    for(int j=0;j<=10;j++)
     if(dp[i][j]!=-1){
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]+ins[i+1][j]);
      if(j<10)
       dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+ins[i+1][j+1]);
      if(j>0)
       dp[i+1][j-1]=max(dp[i+1][j-1],dp[i][j]+ins[i+1][j-1]);
   }
}
int main()
{
   while(scanf("%d",&n)){
      if(!n) break;
      maxi=0;
      memset(dp,-1,sizeof(dp));
      memset(ins,0,sizeof(ins));
      for(int i=1;i<=n;i++){
          int t,x;
          scanf("%d %d",&x,&t);
          ins[t][x]++;
          maxi=max(maxi,t);
      }
      DP();
      int ans=0;
      for(int i=0;i<=10;i++)
       ans=max(dp[maxi][i],ans);
      printf("%d\n",ans);
   }
   return 0;
}
