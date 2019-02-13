#include<bits/stdc++.h>
using namespace std;
#include<cstdio>
#include<cstring>
#define maxn 100000
int check[maxn]={0};
int prime[maxn]={0};
using namespace std;

int main()
{
		int num=0;
		memset(check,0,sizeof(check));
		int n=maxn-5;
		for(int i=2;i<=n;i++)
		{
			if(check[i]==0)
			prime[num++]=i;
			for(int j=i+i;j<=n;j+=i)        //素数的倍数全部标记
			{
				check[j]=1;
			}
		}
		//for(int i=0;i<num;i++)
			//printf("%d ",prime[i]);				//埃筛法
    for(int i=0;i<2000;i++)
    {
        cout<<prime[i]*prime[4000-1-i]<<endl;
    }
}

