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

int search(VI nums, int target)
{
    int len = 1;
    while(nums[len] != -1 && nums[len] < target)
    {
        len *=2;
    }

    int left = len/2;
    int right = len;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] == target)
            return mid;

        else if(nums[mid] == -1 || nums[mid] > target)
            right = mid - 1;

        else if(nums[mid] < target)
        {
            left = mid + 1;
        }

    }

    return -1;
}

int main()
{
    //Code
    vector<int> nums;
    int n;
    cin >> n;
    int target;
    cin>>target;
    
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    ifor(i, 0, 50)
        nums.push_back(-1);
    
    cout << search(nums, target);

    return 0;
}