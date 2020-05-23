class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0;
        for(int x : nums)
            sum += x;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        int temp_sum = 0;
        vector<int> res;
        int idx = 0;
        
        while(idx < nums.size() && temp_sum <= sum)
        {
            temp_sum += nums[idx];
            sum -= nums[idx];
            res.push_back(nums[idx]);
            idx++;
        }
        
        return res;
    }
};