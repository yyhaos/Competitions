#include<bits/stdc++.h>
using namespace std;

string s;
string op;
string ans;
int main(void)
{

#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    getline(cin,s);
    getline(cin,s);
    //cout<<s<<endl;
    int n;cin>>n;
    int cap=0;
    for(int i=0;i<n;i++){
        cin>>op;
        if(op=="CapsLock") { if(cap==0)cap=1; else cap=0;}
        else if(op=="Backspace"&&ans.length()!=0) ans=ans.substr(0,ans.length()-1);
        else if(op=="Space") ans+=" ";
        else ans+=op[0]+cap*('A'-'a');
    }
    if(ans==s) cout<<"Correct"<<endl;
    else cout<<"Incorrect"<<endl;

}
