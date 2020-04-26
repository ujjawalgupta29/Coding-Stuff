class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp{nums[0]};
        deque<int> decrease{nums[0]};
        int res = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(i > k && decrease[0] == dp[i-k-1])
                decrease.pop_front();
            int temp = max(decrease[0] + nums[i], nums[i]);
            dp.push_back(temp);
            while(!decrease.empty() && temp > decrease.back())
                decrease.pop_back();
            decrease.push_back(temp);
            
            res = max(res, temp);
        }
        
        return res;
    }
};