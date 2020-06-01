class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        int counts = 0;
        int max_len = 0;
        mp[0] = -1;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i])
                counts++;
            else
                counts--;
            
            if(mp.find(counts) != mp.end())
            {
                max_len = max(max_len, i - mp[counts]);
            }
            
            else
            {
                mp[counts] = i;
            }
        }
        
        return max_len;
    }
};