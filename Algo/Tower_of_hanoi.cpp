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

void toh(int n, char src, char dest, char buff)
{
    if(n == 1)
    {
        cout << "Move disk 1 from rod " << src <<  
                            " to rod " << dest <<endl;  
        return;
    }
    toh(n-1, src, buff, dest);
    cout << "Move disk " << n << " from rod " << src << 
                                " to rod " << dest << endl;  
    toh(n-1, buff, dest, src);
}

int main()
{
    //Code
    int n;
    cin >> n;
    toh(n, 'S', 'D', 'B');
    return 0;
}