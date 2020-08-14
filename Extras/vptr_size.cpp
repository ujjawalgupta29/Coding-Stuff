#include <iostream>
using namespace std;
 
class A
{
public:
    int x;
    virtual void fun();
};
 
class B
{
public:
    int y;
   void fun();
};
 
int main()
{
    int a = sizeof(A), b = sizeof(B);
    cout << a << " " << b << endl;
    if (a == b) cout << "a == b";
    else if (a > b) cout << "a > b";
    else cout << "a < b";
    return 0;
}