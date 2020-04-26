class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return 1;
        
        int counts = 0;
        for(int i=1; i<n; i++)
        {
            if(nums[i] < nums[i-1])
            {
                counts++;
                
                (i - 2 < 0 || nums[i - 2] <= nums[i]) ? nums[i - 1] = nums[i] : nums[i] = nums[i - 1];
            }
            if(counts > 1)
                return 0;
        }
        
        return 1;
    }
};