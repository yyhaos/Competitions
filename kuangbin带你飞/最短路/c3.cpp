
#include<stdio.h>

#include<iostream>

#include<math.h>

#include<string.h>

#include<algorithm>

using namespace std;

const int inf=0x3f3f3f3f;

int dis[1111];

int mp[1111][1111];

bool book[1111];

int n,m;

void dijkstra(int start)

{

     int ans;

    memset(book,0,sizeof(book));

     for(int i=1;i<=n;i++)

      dis[i]=mp[1][i];

     for(int i=1;i<=n;i++)

     {

        ans=0;

		int v;

	    for(int j=1;j<=n;j++)

         {   if(!book[j]&&dis[j]>ans)//������Ҫÿ��ѡȡ��Դ��Ȩֵ���ı�ȥ�ɳ�;ʹ����������������ܵĴ�;

             {  ans=dis[j];

                v=j;

			 }

		 }

		 book[v]=1;

		for(int j=1;j<=n;j++)

		{

		     dis[j]=max(dis[j],min(dis[v],mp[v][j]));//���ǱȽ��Ƶĵط�,������Ҫѡȡÿ��·������С��Ȩֵ��Ϊ��·�������������,������Ҫ��·�����������������Ƕ���,���Դ�ʱdis�����б����ΪԴ�㵽�õ�����������

		}

	 }

	 return ;

}

int main()

{   int k,a,b,c;

    int t=1;

    scanf("%d",&k);

    while(k--){

		 scanf("%d%d",&n,&m);

		 memset(mp,0,sizeof(mp));

         for(int i=1;i<=m;i++)

          {  scanf("%d %d %d",&a,&b,&c);

             if(c>0)

             mp[a][b]=mp[b][a]=c;

		  }

		   dijkstra(1);

		  printf("Scenario #%d:\n%d\n\n", t++, dis[n]);

	}

}
