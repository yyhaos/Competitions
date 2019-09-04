#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		double cx,cy,r;
		double x1,y1,x2,y2;
		cin>>cx>>cy>>r;
		cin>>x1>>y1>>x2>>y2;
		double d,d1,d2;
		d1=sqrt((x1-cx)*(x1-cx)+(y1-cy)*(y1-cy));
		d2=sqrt((x2-cx)*(x2-cx)+(y2-cy)*(y2-cy));
		double ax=x1-cx;
		double ay=y1-cy;
		double bx=x2-cx;
		double by=y2-cy;
		double xx=x1-x2;
		double yy=y1-y2;
		double tp=fabs(ax*by-ay*bx);
		d=tp/sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		double sn1,sn2;
		sn1=(x1*y1+xx*yy);
		sn2=(x2*y2+xx*yy);
		if(d1<=r+1e-7&&d2<=r+1e-7)cout<<"ALL IN"<<endl;
		else if(d1>r&&d2<r||d1<r&&d2>r)cout<<"PART IN1"<<endl;
		else if(d>=r||sn1>=0&&sn2<=0||sn1<=0&&sn2>=0)cout<<"ALL OUT"<<endl;
		else cout<<"PART IN2"<<endl;
	}
	return 0;
}
