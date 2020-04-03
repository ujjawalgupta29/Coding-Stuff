class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int max_till_here = nums[0];
        int max_total = nums[0];
        
        for(int i=1; i<n; i++)
        {
            max_till_here = max(max_till_here + nums[i], nums[i]);
            max_total = max(max_total, max_till_here);
        }
        
        return max_total;
    }
};