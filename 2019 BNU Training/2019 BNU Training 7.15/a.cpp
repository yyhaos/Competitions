#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int main(){
	int n,m;
	cin>>n>>m;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]=='*'){
				cout<<"*";
				continue;
			}
			int cnt=0;
			for(int k=-1;k<=1;++k){
				if(a[i+k][j-1]=='*')cnt++;
				if(a[i+k][j+1]=='*')cnt++;
			}
            if(a[i-1][j]=='*')cnt++;
            if(a[i+1][j]=='*')cnt++;
			//}
			cout<<cnt;
		}
		cout<<endl;
	}
	return 0;
}

