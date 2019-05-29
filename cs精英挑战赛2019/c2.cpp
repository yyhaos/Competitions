#include<bits/stdc++.h>

using namespace std;

queue<int> Q;

char land[107][107];

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int dis[107][107];
bool vis[107][107]={0};

int main(){

#ifdef yyhao
freopen("in.txt","r",stdin);
#endif // yyhao
		memset(dis,-1,sizeof(dis));

		int n,m;
		scanf("%d%d",&n,&m);
   // getchar();
		for(int i=0;i<n;++i)scanf("%s",land[i]);





		int x,y;
		int Tx,Ty;

		for(int i=0;i<n;++i)for(int j=0;j<m;++j){
			if(land[i][j]=='S'){
				x=i;y=j;
			}
			if(land[i][j]=='T'){
				Tx=i;Ty=j;
			}
		}



		Q.push(x*m+y);
		dis[x][y]=0;
		while(!Q.empty()){

			int cur=Q.front();
			Q.pop();
			int curx=cur/m; int cury=cur%m;
			vis[curx][cury]=true;
         //   cout<<curx<<" "<<cury<<endl;
			for(int dir=0;dir<4;++dir){

				int newx=curx+dx[dir],newy=cury+dy[dir];

				if(newx<0||newx>=n)continue;
				if(newy<0||newy>=m)continue;

				if(land[newx][newy]=='*')continue;
				if(vis[newx][newy])continue;

				dis[newx][newy]=dis[curx][cury]+1;

                vis[newx][newy]=1;
				Q.push(newx*m+newy);



			}



		}

		printf("%d\n",dis[Tx][Ty]);






	return 0;
}
