#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int multiply(int x, int y)
{
    if(y == 0)
        return 0;
    if(y == 1)
        return x;

    int times = y / 2;
    int mult = (y%2 == 0) ? 0 : x;

    int add = x+x;

    for(int i=0; i<times; i++)
        mult += add;

    return mult;
}

int main()
{
    //Code
    int x, y;
    cin >> x >> y;
    if(y>x)
        swap(x,y);

    cout << multiply(x, y) << endl;
    
    return 0;
}