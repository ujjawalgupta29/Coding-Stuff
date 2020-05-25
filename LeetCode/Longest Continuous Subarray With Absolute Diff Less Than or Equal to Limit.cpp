class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> maxi;
        deque<int> mini;
        int max_len = INT_MIN;
        
        int i=0,j;
        for(j=0; j<n; j++)
        {
            
            while(!maxi.empty() && nums[j] > maxi.back())
                maxi.pop_back();
            while(!mini.empty() && nums[j] < mini.back())
                mini.pop_back();
            
            maxi.push_back(nums[j]);
            mini.push_back(nums[j]);
            
            if(maxi.front() - mini.front() > limit)
            {
                if(maxi.front() == nums[i])
                    maxi.pop_front();
                
                if(mini.front() == nums[i])
                    mini.pop_front();
                
                i++;
            }
            max_len = max(max_len, j-i+1);
        }
        return max_len;;
    }
};