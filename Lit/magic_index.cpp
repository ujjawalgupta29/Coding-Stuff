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

int magic(VI nums, int l, int r)
{
    if(l > r)
        return -1;
    
    int mid = (l + r) / 2;

    if(nums[mid] == mid)
        return mid;
    
    int l_idx = min(mid-1, nums[mid]);
    int left = magic(nums, l, l_idx);
    
    if(left >= 0)
        return left;

    int r_idx = max(mid+1, nums[mid]);
    int right = magic(nums, r_idx, r);

    if(right < nums.size())
        return right;

    return -1;
}

int main()
{
    //Code
    int n;
    cin >> n;
    VI nums(n);

    ifor(i, 0, n)   cin >> nums[i];

    cout << magic(nums, 0, n-1);
    return 0;
}