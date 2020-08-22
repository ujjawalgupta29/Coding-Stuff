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


long long int solve(vector<long long int> &nums, int x, int y, int z, int t)
{
    long long int ans = nums[x] & nums[y];

    for(long long int i=x; i<=z; i++)
    {
        for(long long int j=y; j<=t; j++)
        {
            if(i == x && j == y)
                continue;

            ans ^= (nums[i] & nums[j]);
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<long long int> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];

    int x,y,z,t;

    cin >> x >> y >> z >> t;

    cout << solve(nums, x-1, y-1, z-1, t-1) << endl;
}