#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool vis;

int n;

void dfs(unsigned __int64 x,int n,int k){

	if(vis) return;

	if(x%n==0){

		printf("%I64u\n",x);

		vis=true;

		return;

	}

	if(k==19) return;

	dfs(x*10,n,k+1);

	dfs(x*10+1,n,k+1);

}

int main(){

	while(scanf("%d",&n)){

		if(n==0) break;

		vis=false;

		dfs(1,n,0);

	}

	return 0;

}

