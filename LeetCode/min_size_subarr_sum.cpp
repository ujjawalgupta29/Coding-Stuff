class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        
        vector<int> preSum;
        int sum = 0;
        
        for(int x : nums)
        {
            sum += x;
            preSum.push_back(sum);
        }
        
        int min_len = INT_MAX;
        for(int i=0; i<n; i++)
        {
            int start = i;
            int rem = s - nums[i] + preSum[i];
            int end = lower_bound(preSum.begin() , preSum.end(), rem) - preSum.begin();
            if(end == n)
                continue;
            if(end - start + 1 < min_len)
            {
                min_len = end - start + 1;
            }
        }
        
        return (min_len != INT_MAX) ? min_len : 0;
    }
};