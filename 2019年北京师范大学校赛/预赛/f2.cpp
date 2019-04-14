#include<bits/stdc++.h>
using namespace std;
vector<pair<string,int> > q;
map<string,int> mmp;
int main(){
    freopen("in.txt","r",stdin);
	int T;
	cin>>T;
	while(T--){
	    mmp.clear();//初始化
	    q.clear();//初始化
		int n;cin>>n;
		int cnt=0,N=0;int in=0;int in0=0;//in0是按顺序队首的人
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
                    in0++;//这里的更新in0有问题 ： in0先必须+1
					for(int i=in0;i<=q.size();i++){ // in0的结束可以是队列末位的下一位（表示当前人走完了，但是还有后来的人重新开始排队）
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
