#include<bits/stdc++.h>
using namespace std;
vector<pair<string,int> > q;
map<string,int> mmp;
int main(){
    freopen("in.txt","r",stdin);
	int T;
	cin>>T;
	while(T--){
	    mmp.clear();//��ʼ��
	    q.clear();//��ʼ��
		int n;cin>>n;
		int cnt=0,N=0;int in=0;int in0=0;//in0�ǰ�˳����׵���
		for(int j=0;j<n;j++){
			string x;string name;
			cin>>x>>name;
			//cout<<"x:"<<x<<"  "<<"name:"<<name<<endl;
			if(x[0]=='i'){
				q.push_back(make_pair(name,1));
				mmp[name]=N;

				N++;
			}else{
				int benying=mmp[name];
				if(benying==in0){
                    in0++;//����ĸ���in0������ �� in0�ȱ���+1
					for(int i=in0;i<=q.size();i++){ // in0�Ľ��������Ƕ���ĩλ����һλ����ʾ��ǰ�������ˣ����ǻ��к����������¿�ʼ�Ŷӣ�
						if(i==q.size() || q[i].second==1){
							in0=i;break;
						}
					}
				}else{
					cnt++;
					//cout<<"cnt:"<<cnt<<" "<<"x[0]:"<<x[0]<<" name:"<<name<<endl;
				}
				q[benying].second=0;
			}
		}
		cout<<N-cnt;if(T!=0)cout<<endl;
	}
}
