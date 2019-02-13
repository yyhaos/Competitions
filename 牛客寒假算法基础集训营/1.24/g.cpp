#include<bits/stdc++.h>
using namespace std;
string s,t;
int ls,lt;
int dp[105][105];
int dis(int st1,int st2)
{
    if(dp[st1][st2]!=-1)
        return dp[st1][st2];
    if(st1==ls && st2==lt)
        return dp[st1][st2]=0;
    if(st1==ls)
        return dp[st1][st2]=lt-st2;
    if(st2==lt)
        return dp[st1][st2]=ls-st1;
    int i;
    //ls=s.length();
    //lt=t.length();
    for(i=0;i+st1 < ls && i+st2<lt ;i++)
    {
        if(s[i+st1]==t[i+st2])
        {
            continue;
        }
        break;
    }
    int ans=9999999;
    if(i+st1==ls)
        return dp[st1][st2]=lt-st2-i;
    if(i+st2==lt)
        return dp[st1][st2]=ls-st1-i;

    ans=min(ans,1+dis(i+st1+1,i+st2));
    ans=min(ans,1+dis(i+st1,i+st2+1));
    ans=min(ans,1+dis(i+st1+1,i+st2+1));
    return dp[st1][st2]=ans;
}

int main ()
{
    for(int i=0;i<105;i++)
    for(int j=0;j<105;j++)
        dp[i][j]=-1;
    cin>>s>>t;
    ls=s.length();
    lt=t.length();
    if(lt<ls)
    {
        string tmp=s;
        s=t;
        t=tmp;
    }
    ls=s.length();
    lt=t.length();
    //cout<<ls<<" "<<lt<<endl;
    dis(0,0);
    if(dis(0,0)<=2)
    {
        printf("YES");
    }
    else
        cout<<"NO";

//     for(int i=0;i<5;i++)
//    for(int j=0;j<5;j++)
//        {
//            dis(i,j);
//            cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
//        }
    return 0;
}
