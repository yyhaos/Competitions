#include<stdio.h>
#include<iostream>
#include <cstring>
#include <cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=2005;
int inf=(1<<31)-1;
int dp[maxn][maxn];
int a[maxn],b[maxn];
int n;
int main ()
{
    //printf("%d\n",inf);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
    {
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b,b+n);
	for(int i=0;i<n;i++)
    {
		int k;
        if(i)
            k=dp[i-1][0];
        else
            k=0;
		for(int j=0;j<n;j++){
			if(i)k=min(k,dp[i-1][j]);
			dp[i][j]=abs(a[i]-b[j])+k;
		}
	}
	int ans = inf;
	for(int i=0;i<n;i++)
		ans=min(ans,dp[n-1][i]);
	printf("%d\n",ans);
	return 0;
}
