#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)

typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class A {
    public:

    virtual void print() = 0;
};

void A::print()
{
    cout << "default" << endl;
}

class B : public A {
    public:

    void print()
    {
        cout << "Class B called";
    }

};

int main()
{
    B b1;
    A* a = &b1;
    a->print();
    
    B b2;
    A *a1 = &b2;
    a1->print();
}