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
    int n;
    cin >> n;

    vector<int> cache;
    cache.push_back(1);

    for(int nodes = 1; nodes <=n; nodes++)
    {
        int numOfTrees = 0;
        for(int left = 0; left <= nodes; left++)
        {
            int right = nodes - 1 - left;
            numOfTrees += cache[left] * cache[right];
        }
        cache.push_back(numOfTrees);
    }

    cout << cache[n] << endl;

    return 0;
}