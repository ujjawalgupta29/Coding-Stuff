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

void quick_sort_helper(VI &nums, int start, int end)
{
    if(start >= end)
        return;

    int left = start + 1;
    int right = end;
    int pivot = start;

    while(left <= right)
    {
        if(nums[left] > nums[pivot] && nums[right] < nums[pivot])
            swap(nums[left], nums[right]);

        if(nums[left] < nums[pivot])
            left++;

        if(nums[right] > nums[pivot])
            right--;
    }
    swap(nums[pivot], nums[right]);

    quick_sort_helper(nums, start, right-1);
    quick_sort_helper(nums, right+1, end);
}

void quick_sort(VI &nums, int n)
{
    quick_sort_helper(nums, 0, n-1);
}

int main()
{
    //Code
    int n;
    cin >> n;

    VI nums(n);
    ifor(i, 0, n) cin >> nums[i];

    quick_sort(nums, n);

    for(int x : nums) cout << x << " ";
    cout<<endl;
    return 0;
}