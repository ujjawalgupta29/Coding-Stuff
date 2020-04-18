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

void construct(int n, int days)
{
    if(n == 1)
        cout << 1 << ' ' << 1 << endl;
    else if(n == 2)
        cout << 2 << ' ' << 1 << ' ' << 2 << endl;
    else
    {
        cout << 3 << ' ' << 1 << ' ' << 2 << ' ' << 3 << endl;
        for(int i=4; i<=n; i += 2)
        {
            if(i+1 > n)
                cout << 1 << ' ' << i << endl;
            else
                cout << 2 << ' ' << i << ' ' << i+1 << endl;
        }
    }
}

int main()
{
    //Code
    int t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        ll days = n/2;
        if(n == 1) days = 1;

        cout<<days<<endl;
        construct(n, days);

    }

    return 0;
}