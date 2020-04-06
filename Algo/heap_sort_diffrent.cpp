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

void sift_down(int start, int end, VI &nums)
{
    int childOne = 2 * start + 1;
    int childTwo = -1;
    int idxToSwap;
    while(childOne <= end)
    {
        if(start*2 + 2 <= end) childTwo = start*2 + 2;

        if(childTwo != -1 && nums[childTwo] > nums[childOne])
            idxToSwap = childTwo;

        else
        {
            idxToSwap = childOne;
        }

        if(nums[start] < nums[idxToSwap])
        {
            swap(nums[idxToSwap], nums[start]);
            start = idxToSwap;
            childOne = 2*start + 1;
        }

        else
        {
            return;
        }
    }
}

void build_max_heap(VI &nums)
{
    int firstParent = (nums.size() - 2) / 2 ;
    dfor(i, firstParent, 0)
    {
        sift_down(i, nums.size() - 1, nums);
    }
}

void heap_sort(VI &nums, int n)
{
    build_max_heap(nums);
    dfor(i, n-1, 1)
    {
        swap(nums[i], nums[0]);
        sift_down(0, i-1, nums);
    }
}

int main()
{
    //Code
    int n;
     cin >> n;
    
    VI nums(n);
    ifor(i, 0, n) cin >> nums[i];

    heap_sort(nums, n);

    for(int x : nums) cout << x << " ";
    cout<<endl;
    return 0;
}