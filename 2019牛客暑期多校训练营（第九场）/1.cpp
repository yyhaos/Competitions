#include <iostream>

//#include <bits/stdc++.h>
using namespace std;

string s;
signed main()
{
    int n;
    cin>>n;

    cin>>s;
int len=s.length();

    int st=-1;
    for(int i=0;s[i];++i)
    {
        if(s[i] != '.'){
            st=i;
            break;
        }

    }
    int mm=-1;

    for(int i=len-1;i>st;--i)
    {
        if(s[i]==s[st]){
            mm=i;
            break;
        }
    }

    int ed=-1;
    for(int i=len-1;i>0;--i)
    {
        if(s[i] != '.'){
            ed=i;
            break;
        }
    }

    if(s[st]=='L'){
        cout<<ed+1<<' '<<st<<endl;
    }
    else if(s[st]=='R'){

        if(s[mm+1]=='.'){
            cout<<st+1<<' '<<mm+2<<endl;
        }
        else {
            cout<<st+1<<' '<<mm+1<<endl;
        }



    }





    return 0;
}
