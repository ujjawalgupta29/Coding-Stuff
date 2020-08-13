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

int main()
{
    vector<int> bits1{1,1,0};
    vector<int> bits2{0,0,1};

    int comb1 = 3;
    int comb2 = 3;

    while(comb1--)
    {
        for(int x : bits1)
            cout << x << " ";
        cout << endl;

        next_permutation(bits1.begin(), bits1.end());
    }

    cout << "Next" << endl;

    while(comb2--)
    {
        for(int x : bits2)
            cout << x << " ";
        cout << endl;

        next_permutation(bits2.begin(), bits2.end());
    }
}