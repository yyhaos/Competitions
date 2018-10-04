#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 6;
const int mod = 1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

string dp[28];
/*string ss(char c){
    if (c=='a'){
        return "a";
    }else {
        if (dp[c-'a'-1] == "") dp[c-'a'-1] = ss(c-1);
        string rr = dp[c-'a'-1] + c + dp[c-'a'-1];
        if (rr.length()>=1000) cout<<rr;
        return rr;
    }
}*/

int main(){
    int n;
    string s1 = "aba",s2;
    for (int i=2;i<=26;i++){
        char sss = 'a'+ i;
        string ss;
        ss+=sss;
        s2 = s1 + ss + s1;
        s1 = s2;
        if (s1.length()>1000){
            break;
        }
    }
    scanf("%d",&n);
    printf("%c",s1[n-1]);
    return 0;
}
