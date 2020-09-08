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
    int t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        ll sum = (n * (n+1)) / 2;
        // cout << sum << endl;

        if(sum % 2 != 0)
        {
            cout << 0 << endl;
        }

        else
        {
            ll half = sum/2;

            ll l=1;
            ll r=n;

            while(l < r)
            {
                ll mid = l + (r-l)/2;

                if((mid*(mid+1))/2 >= half)
                    r = mid;

                else 
                    l = mid + 1;
            }

            cout << n-l+1 << endl;
        }
        
    }
}