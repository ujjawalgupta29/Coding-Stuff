class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int res = 0;
        int l = 0;
        
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
            mp[nums[i]] = i;
        
        while(l < n)
        {
            if(nums[l] + k > nums[n-1])
                break;
            
            if(mp[nums[l] + k] > 0 && mp[nums[l] + k] > l)
            {
                res++;
                int temp = nums[l];
                while(l<n && temp == nums[l])
                    l++;
            }
            
            else
                l++;
        }
        
        return res;
    }
};