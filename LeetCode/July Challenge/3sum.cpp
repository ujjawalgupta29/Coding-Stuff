static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        int a;
        
        if(nums.size() < 3)
            return res;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            a= nums[i];
            int l = i+1;
            int r = n-1;
            
            while(l < r)
            {
                if(nums[l] + nums[r] + a == 0)
                {
                    vector<int>temp{a, nums[l], nums[r]};
                    res.push_back(temp);
                    l++; r--;
                    while(l < r && nums[l] == temp[1]) l++;
                    while(r > l && nums[r] == temp[2]) r--;
                }
                
                else if(nums[l] + nums[r] + a > 0)
                {
                    r--;
                }
                
                else
                {
                    l++;
                }
            }
        }
        
        return res;
    }
};