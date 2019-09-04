#include<bits/stdc++.h>
using namespace std;
int a[10][10];
char s[10];
int main(){

#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
	memset(a,0,sizeof a);
	for(int i=1;i<=5;++i){
		cin>>s;
		if(s[1]=='>'){
			a[s[0]-'A'+1][s[2]-'A'+1]=1;
			a[s[2]-'A'+1][s[0]-'A'+1]=-1;
		}
		else{
			a[s[0]-'A'+1][s[2]-'A'+1]=-1;
			a[s[2]-'A'+1][s[0]-'A'+1]=1;
		}
	}
	char p[10];
	for(int i=0;i<5;++i)p[i]='A'+i;
	int sn=0;
	int fl=1;
	for(int i=1;i<=5;++i){
		for(int j=1;j<=5;++j){
			if(a[p[i-1]-'A'+1][p[j-1]-'A'+1]==1 && i-1<j-1){
					fl=0;
					break;
				}
				if(a[p[i-1]-'A'+1][p[j-1]-'A'+1]==-1 && i-1>j-1){
					fl=0;
					break;
				}
		}
	}
	if(fl){
		sn=1;
		for(int i=0;i<5;++i)cout<<p[i];
		return 0;
	}
	while(next_permutation(p,p+5)){

		int fl=1;
		for(int i=1;i<=5;++i){
			for(int j=1;j<=5;++j){
//if(p[0]=='B' && p[1]=='D' && p[2]=='E' && p[3]=='C')
//        {
//            cout<<i<<" "<<j<<" "<<p[i-1]<<"_"<<p[j-1]<<" "<<a[p[i-1]-'A'+1][p[j-1]-'A'+1]<<endl;
//        }
				if(a[p[i-1]-'A'+1][p[j-1]-'A'+1]==1 && i-1<j-1){
					fl=0;
					break;
				}
				if(a[p[i-1]-'A'+1][p[j-1]-'A'+1]==-1 && i-1>j-1){
					fl=0;
					break;
				}


			}
			if(fl==0)
                {
                    break;
                }
		}

		if(fl){
			sn=1;
			for(int i=0;i<5;++i)cout<<p[i];
			return 0;
		}
	}

		cout<<"impossible";

	return 0;
}
