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

class Solution {
public:
    
    void binarySearch(VI &nums, int l, int r, int target, bool left, VI &range)
    {
        while(l <= r)
        {
            int mid = l + (r - l) / 2;

            if(nums[mid] < target)  l = mid + 1;
            else if(nums[mid] > target) r = mid - 1;
            else
            {
                if(left)
                {
                    if(mid == 0 || nums[mid] != nums[mid - 1])
                    {
                        range[0] = mid;
                        return;
                    }
                    else
                    {
                        r = mid - 1;
                    }

                }
                else
                {
                    if(mid == nums.size() - 1 || nums[mid] != nums[mid + 1])
                    {
                        range[1] = mid;
                        return;
                    }
                    else
                    {
                        l = mid + 1;
                    }

                }

            }

        }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        VI range{-1, -1};

        binarySearch(nums, 0, n-1, target, true, range);
        binarySearch(nums, 0, n-1, target, false, range);
        
        return range;
    }
};