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

int main()
{
    //Code
    int t;
    cin >> t;

    while(t--)
    {
        int n,s;
        cin >> n >> s;

        VI prices(n);
        ifor(i, 0, n) cin >> prices[i];

        int fwd = 100;
        int def = 100;

        ifor(i, 0, n)
        {
            int x;
            cin >> x;
            if(x == 0)
            {
                def = min(def, prices[i]);
            }
            else
            {
                fwd = min(fwd, prices[i]);
            }
            
        }

        int cost = s + def + fwd;
        cout << ( (cost <= 100) ? "yes" : "no") << endl;

    }
    return 0;
}