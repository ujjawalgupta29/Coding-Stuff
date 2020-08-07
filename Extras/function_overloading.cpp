#include <iostream> 
using namespace std; 
class Base 
{ 
public: 
    int f(int i) 
    { 
        cout << "f(int): "; 
        return i+3; 
    } 
}; 
class Derived : public Base 
{ 
public: 
    double f(double d) 
    { 
        cout << "f(double): "; 
        return d+3.3; 
    } 
}; 
int main() 
{ 
    Derived* dp = new Derived; 
    int n1 = 3;
    double n2 = 3.3;
    cout << dp->f(n1) << '\n'; 
    cout << dp->f(n2) << '\n'; 
    delete dp; 
    return 0; 
}