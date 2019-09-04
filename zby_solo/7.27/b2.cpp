#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
string a,b;
signed main(){
	//freopen("in.txt","r",stdin);
	while(getline(cin,a)&&a!="ENDOFINPUT"){
		if(a!="START"&&a!="END"){
			for(int i=0;a[i];++i){
				if(a[i]-5>='A'&&a[i]-5<='U')printf("%c",a[i]-5);
				else if(a[i]>='A'&&a[i]<='E')printf("%c",a[i]+21);
				else printf("%c",a[i]);
			}
			//printf(" ");
		}
		if(a=="END")printf("\n");
	}
	return 0;
}
