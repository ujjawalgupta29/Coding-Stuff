class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> dp;
        dp[0] = -1;
        
        int sum=0, prevIdx=-1;
        int counts=0;
        
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            int rem = sum - target;
            
            if(dp.count(rem))
            {
                int idx = dp[rem];
                if(idx >= prevIdx)
                {
                    counts++;
                    prevIdx = i;
                }
            }
            
            dp[sum] = i;
        }
        
        return counts;
    }
};