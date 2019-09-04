//Problem Web:
#include<bits/stdc++.h>
using namespace std;


char a[105][105];
int b[105][105];

string s;
int n,m;

signed main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
while(cin>>n){
//        cout<<n<<endl;
	memset(b,0,sizeof b);
	memset(a,0,sizeof a);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}



	s="";
	s+=a[0][0];
	int fl=0;


	int x=0;
	int y=0;
	while(x!=n-1||y!=n-1){

		if(fl==0&&x==0){
			if(y<n-1){
				y++;
				fl=1;
			}
			else{
				x++;
				fl=1;
			}
		}

		else if(fl==1&&y==0){
			if(x<n-1){
				x++;
				fl=0;
			}
			else{
				y++;
				fl=0;
			}
		}


		else if(fl==1){
			if(x<n-1&&y>0){
				x++;y--;
				fl=1;
			}

			else{
				y++;
				fl=0;
			}


		}

		else if(fl==0){

			if(x>0&&y<n-1){
				x--;y++;
				fl=0;
			}

			else{
				x++;
				fl=1;
			}

		}

		s+=a[x][y];

	}


	//cout<<s<<endl;


	x=0;
	y=0;

	int p=1;


	b[0][0]=1;

	while(p<n*n){
		while(y<n-1&&b[x][y+1]==0)b[x][++y]=++p;
		while(x<n-1&&b[x+1][y]==0)b[++x][y]=++p;

		while(x>0&&b[x-1][y]==0) b[--x][y]=++p;
		while(y>0&&b[x][y-1]==0) b[x][--y]=++p;

	}


	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			printf("%c",s[b[i][j]-1]);
		}
		printf("\n");
	}

}

    return 0;
}
