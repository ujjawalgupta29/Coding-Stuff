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

int main()
{
    //Code
    int t;
    cin >> t;

    while(t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        VI res;

        for(int i=0; i<n; i++)
        {
            int k1 = k;
            int idx = 0;
            int maxi = INT_MIN;
            MI counts;

            while(k1--)
            {
                int temp;
                cin >> temp;
                counts[temp]++;
                if(counts[temp] > maxi)
                {
                    maxi = counts[temp];
                    idx = temp;
                }
            }
            res.push_back(idx);
        }

        for(auto x : res)   cout << x << " ";
        cout << endl;
    }

    return 0;
}