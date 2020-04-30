class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        int count = 0, preSum = 0;
        
        for(int x : nums)
        {
            mp[preSum]++;
            preSum += x;
            auto it = mp.find(preSum - k);
            if(it != mp.end())
                count += mp[preSum - k];
        }
        
        return count;
    }
};