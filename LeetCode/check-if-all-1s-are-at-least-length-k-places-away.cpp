static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = -1;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 1)
            {
                if(prev == -1)
                {
                    prev = i;
                }
                else
                {
                    if(i - prev - 1 < k)
                        return 0;
                    else
                        prev = i;
                }
            }
        }
        
        return 1;
    }
};