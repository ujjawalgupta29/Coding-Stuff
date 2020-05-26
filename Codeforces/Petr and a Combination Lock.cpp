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

int solve(int mask, vector<int> &a)
{
    int temp = 0;

    for(int i=0; i<a.size(); i++)
    {
        if( (mask & (1 << i)) == 0)
        {
            temp -= a[i];
        }
        else
        {
            temp += a[i];
        }
        
    }

    return temp;
}

int main()
{
    //Code
    int n;
    cin >> n;
    vector<int> a(n);

    ifor(i, 0, n)   cin >> a[i];

    int counts = 0;

    for(int mask = 0; mask < ( (1<<n) ); mask++ )
    {
        int val = solve(mask, a);
        if(val%360 == 0)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}