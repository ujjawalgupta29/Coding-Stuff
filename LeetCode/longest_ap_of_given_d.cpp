class Solution {
public:
    int longestSubsequence(vector<int>& nums, int diff) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int max_len = 1;
        
        for(int i=0; i<n; i++)
        {
            if(mp.find(nums[i] - diff) != mp.end())
                mp[nums[i]] = 1 + mp[nums[i] - diff];
            
            else
                mp[nums[i]] = 1;
            
            max_len = max(max_len, mp[nums[i]]);
        }
        
        return max_len;
    }
};