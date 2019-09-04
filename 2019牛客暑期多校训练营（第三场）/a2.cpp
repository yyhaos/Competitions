#include<bits/stdc++.h>
using namespace std;
double a[1005];
double b[1005]={0,4,3.7,3.3,3.0,2.7,2.3,2.0,1.7,1.3,1.0,0};
string c;
int main(){
	int n;
	while(cin>>n){
		double s1=0;
		double s2=0;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			cin>>c;
			int tp;
			if(c=="A")tp=1;
			else if(c=="A-")tp=2;
			else if(c=="B+")tp=3;
			else if(c=="B")tp=4;
			else if(c=="B-")tp=5;
			else if(c=="C+")tp=6;
			else if(c=="C")tp=7;
			else if(c=="C-")tp=8;
			else if(c=="D")tp=9;
			else if(c=="D-")tp=10;
			else if(c=="F")tp=11;
			else if(c=="P"||c=="N")tp=0;
			s1+=a[i]*b[tp];
			if(tp)s2+=a[i];
		}
		if(s2!=0)printf("%.2f\n",s1/s2);
		else cout<<"0.00"<<endl;
	}
	return 0;
}
