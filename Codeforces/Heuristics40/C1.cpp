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

int solve(VL nums)
{
    int n = nums.size();
    VL left(n, 0);
    VL right(n, 0);
    left[0] = 1;
    right[n-1] = 1;
    ll res = INT_MIN;

    ifor(i, 1, n)
    {
        if(nums[i] > nums[i-1])
            left[i] = left[i-1] + 1;
        else
        {
            left[i] = 1;
        }
        res = max(res, left[i]);
    }

    dfor(i, n-2, 0)
    {
        if(nums[i] < nums[i+1])
            right[i] = right[i+1] + 1;
        else
        {
            right[i] = 1;
        }
    }


    ifor(i, 1, n-1)
    {
        if(nums[i] < nums[i+1])
            res = max(res, left[i-1] + right[i+1]);
    }

    return res;

}

int main()
{
    //Code
    ll n;
    cin >> n;
    VL nums(n);
    ifor(i, 0, n)  cin >> nums[i];

    cout << solve(nums) << endl;

    return 0;
}