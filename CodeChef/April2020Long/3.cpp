#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)
typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

ll getCounts2(ll x)
{
    ll counts = 0;

    for(ll i = 2; i <= sqrt(x); i++)
    {
        while(x % i == 0)
        {
            counts++;
            x = x/i;
        }
    }

    if(x > 1)
        counts++;

    return counts;
}

int main()
{
    //Code
    int t;
    cin >> t;
    while(t--)
    {
        ll x, k;
        cin >> x >> k;

        ll counts2 = getCounts2(x);

        if(k <= counts2)
            cout << "1" << endl;
        else
        {
            cout << "0" << endl;
        }
    }
    return 0;
}