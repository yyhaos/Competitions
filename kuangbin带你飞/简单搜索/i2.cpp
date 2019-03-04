
#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cmath>

#include<cstring>

#include<queue>

using namespace std;



#define INF 0x3f3f3f3f



int T,N,M,cou;

char grid[15][15];



struct Point

{

	int x,y;

	int times;

}point[105];



Point p1,p2;

int ans;

bool book[15][15];



bool isValid(int x,int y)

{

	if(x<0 || x>=N || y<0 || y>=M || grid[x][y]!='#' || book[x][y])

		return false;

	return true;

}

int dir[8]={0,1,0,-1, 1,0,-1,0};

queue<Point> que1;



int BFS()

{

	int counter=1,time=0;

	Point tp1,tp2;

	memset(book,false,sizeof(book));

	que1.push(p1);

	book[p1.x][p1.y]=true;



	if(p1.x!=p2.x || p1.y!=p2.y)//起点不同

	{

		que1.push(p2);

		++counter;

		book[p2.x][p2.y]=true;

	}



	while(!que1.empty())

	{

		if(!que1.empty())

		{

			tp1=que1.front();

			for(int i=0;i<8;i+=2)

			{

				if(isValid(tp1.x+dir[i], tp1.y+dir[i+1]))

				{

					tp2.times=tp1.times+1;

					tp2.x=tp1.x+dir[i];

					tp2.y=tp1.y+dir[i+1];

					que1.push(tp2);



					time=tp2.times;

					book[tp2.x][tp2.y]=true; ++counter;

				}

			}

			que1.pop();

		}



	}

	if(counter<cou)

		return -1;

	return time;

}



int cas;



int main()

{

	scanf("%d",&T);

	cas=1;

	while(T--)

	{

		cou=0; ans=INF;

		scanf("%d%d",&N,&M);

		for(int i=0;i<N;i++)

			scanf("%s",grid[i]);

		for(int i=0;i<N;i++)

		for(int j=0;j<M;j++)

		{

			if(grid[i][j]=='#')

			{

				point[cou].x=i; point[cou].y=j; point[cou++].times=0;

			}

		}



		for(int i=0;i<cou;i++)

		{

			p1=point[i];

			for(int j=0;j<cou;j++)

			{

				p2=point[j];

				int tans=BFS();

				if(tans!=-1)

					ans=min(ans,tans);

			}

		}

		if(ans==INF)

			ans=-1;

		printf("Case %d: %d\n",cas++,ans);

	}

    return 0;

}
