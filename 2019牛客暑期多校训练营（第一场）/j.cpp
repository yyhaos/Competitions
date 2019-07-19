//Problem Web:https://ac.nowcoder.com/acm/contest/881/E
#include<bits/stdc++.h>
#include<ext/rope>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

#define ll long long
#define lowbit(x) (x&-x)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define crep(i,x,y) for(ll i=x;i>=y;i--)
#define gcd(x,y) __gcd(x,y)
#define mem(x,y) memset(x,y,sizeof(x))
#define pr pair
#define mp make_pair
//#define use_t 1
const double PI=acos(-1.0);
const double eps=1e-30;
const ll INF = 100000000;
const ll maxn=1000;
const ll q=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1LL;
    while(b>0)
    {
        if(b&1LL)
            ans=ans*a%q;
        a=a*a%q;
        b/=2LL;
    }
    return ans;
}

ll t,n,m;
ll k[10005];
ll C(ll m,ll n)
{
    return k[m]*ksm(k[n],q-2)%q*ksm(k[m-n],q-2)%q;
}
struct BigInteger
{
    vector<char> digits;
    bool sign;
    void trim();
    BigInteger();
    BigInteger(ll);
    friend BigInteger operator*=(const BigInteger&, const BigInteger&);
    friend bool operator==(const BigInteger&, const BigInteger&);
    friend bool operator<(const BigInteger&, const BigInteger&);
    friend BigInteger operator+=(BigInteger&, const BigInteger&);
    friend BigInteger operator+(const BigInteger&, const BigInteger&);
    static const BigInteger ZERO;
};
const BigInteger BigInteger::ZERO = BigInteger(0);
BigInteger::BigInteger() {
      sign = true;
}
void BigInteger::trim() {
      vector<char>::reverse_iterator iter = digits.rbegin();
      while (!digits.empty() && (*iter) == 0) {
            digits.pop_back();
            iter = digits.rbegin();
      }
      if (digits.size() == 0) {
            sign = true;
            digits.push_back(0);
      }
}
BigInteger operator+=(BigInteger& op1, const BigInteger& op2) {
      if (op1.sign == op2.sign) {
            vector<char>::iterator iter1;
            vector<char>::const_iterator iter2;
            iter1 = op1.digits.begin();
            iter2 = op2.digits.begin();
            char to_add = 0;
            while (iter1 != op1.digits.end() && iter2 != op2.digits.end()) {
                  (*iter1) = (*iter1) + (*iter2) + to_add;
                  to_add = ((*iter1) > 9);
                  (*iter1) = (*iter1) % 10;
                  iter1++;
                  iter2++;
            }
            while (iter1 != op1.digits.end()) {
                  (*iter1) = (*iter1) + to_add;
                  to_add = ((*iter1) > 9);
                  (*iter1) %= 10;
                  iter1++;
            }
            while (iter2 != op2.digits.end()) {
                  char val = (*iter2) + to_add;
                  to_add = (val > 9) ;
                  val %= 10;
                  op1.digits.push_back(val);
                  iter2++;
            }
            if (to_add != 0) {
                  op1.digits.push_back(to_add);
            }
            return op1;
      }
}
bool operator<(const BigInteger& op1, const BigInteger& op2) {
    if (op1.digits.size() != op2.digits.size())
        return (op1.sign && op1.digits.size() < op2.digits.size())
        || (!op1.sign && op1.digits.size() > op2.digits.size());
    vector<char>::const_reverse_iterator iter1, iter2;
    iter1 = op1.digits.rbegin();
    iter2 = op2.digits.rbegin();
    while (iter1 != op1.digits.rend()) {
          if (op1.sign &&  *iter1 < *iter2) {
                return true;
          }
          if (op1.sign &&  *iter1 > *iter2) {
                return false;
          }
          if (!op1.sign &&  *iter1 > *iter2) {
                return true;
          }
          if (!op1.sign &&  *iter1 < *iter2) {
                return false;
          }
          iter1++;
          iter2++;
    }
    return false;

}
BigInteger::BigInteger(ll val) {
    sign=true;
      do {
            digits.push_back((char)(val % 10));
            val /= 10;
      } while (val != 0);
}
bool operator==(const BigInteger& op1, const BigInteger& op2) {
      if (op1.sign != op2.sign  || op1.digits.size() != op2.digits.size()) {
            return false;
      }
      vector<char>::const_iterator iter1, iter2;
      iter1 = op1.digits.begin();
      iter2 = op2.digits.begin();
      while (iter1 != op1.digits.end()) {
            if (*iter1 != *iter2) {
                  return false;
            }
            iter1++;
            iter2++;
      }
      return true;
}
BigInteger operator+(const BigInteger& op1, const BigInteger& op2) {
      BigInteger temp(op1);
      temp += op2;
      return temp;
}
BigInteger operator*=(BigInteger& op1, const BigInteger& op2) {
      BigInteger result(0);
      if (op1 == BigInteger::ZERO || op2 == BigInteger::ZERO) {
            result = BigInteger::ZERO;
      }
      else {
            vector<char>::const_iterator iter2 = op2.digits.begin();
            while (iter2 != op2.digits.end()) {
                  if (*iter2 != 0) {
                        deque<char> temp(op1.digits.begin(), op1.digits.end());
                        char to_add = 0;
                        deque<char>::iterator iter1 = temp.begin();
                        while (iter1 != temp.end()) {
                              (*iter1) *= (*iter2);
                              (*iter1) += to_add;
                              to_add = (*iter1) / 10;
                              (*iter1) %= 10;
                              iter1++;
                        }
                        if (to_add != 0) {
                              temp.push_back(to_add);
                        }
                        int num_of_zeros = iter2 - op2.digits.begin();
                        while (num_of_zeros--) {
                              temp.push_front(0);
                        }
                        BigInteger temp2;
                        temp2.digits.insert(temp2.digits.end(), temp.begin(), temp.end());
                        temp2.trim();
                        result = result + temp2;
                  }
                  iter2++;
            }
            result.sign = ((op1.sign && op2.sign) || (!op1.sign && !op2.sign));
      }
      op1 = result;
      return op1;
}
int main ()
{
#ifdef yyhao
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
#ifdef use_t
ll ii=1;
cin>>t;
for(ii=1;ii<=t;ii++)
{
#endif // use_t

    ll x,a,y,b;
    while(~scanf("%lld%lld%lld%lld",&x,&a,&y,&b))
    {
        BigInteger x1(x);
        BigInteger a1(a);
        BigInteger y1(y);
        BigInteger b1(b);
        x*=b;
        y*=a;
        if(x<y)
        {
            cout<<"<\n";
        }
        else if(y<x)
        {
            cout<<">\n";
        }
        else
            cout<<"=\n";

    }



#ifdef use_t
}
#endif // use_t
    return 0;
}



