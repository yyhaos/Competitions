#include<iostream>
using namespace std;
class Base
{
private:
    int A;
public:
    Base(){}
    Base(int a):A(a){}
    void show()
    {
        cout<<"A="<<A<<endl;
    }
};
class Base2
{
private:
    int A;
public:
    Base2(){}
    Base2(int a):A(a){}
    void show()
    {
        cout<<"B2="<<A<<endl;
    }
};
class Der:public Base
{
private:
    int B;
    Base2 em;
public:
    Der(){}
    Der(int a,int b,int c):em(b),Base(c)
    {
        B=a;
//         Base(a);
    }
    void show()
    {
        Base::show();
        em.show();
        cout<<"B="<<B<<endl;
    }
};
int main ()
{
    Der a(1,2,3);
    a.show();
    return 0;
}
