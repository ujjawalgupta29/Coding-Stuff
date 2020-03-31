class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-3; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            for(int j=i+1; j<n-2; j++)
            {
                if(j > i+1 && nums[j] == nums[j-1])
                {
                    continue;
                }
                int left = j+1;
                int right = n-1;
                int rem = target - (nums[i] + nums[j]);
                
                while(left < right)
                {
                    int sum= nums[left] + nums[right];
                    if(sum == rem)
                    {
                        vector<int> temp{nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(temp);
                        left++;
                        right--;
                        while(left > 0 && left < right && nums[left] == nums[left - 1]) left++;
                        while(right < n-1 && left < right && nums[right] == nums[right + 1]) right--;
                    }
                    
                    else if(sum < rem)
                        left++;
                    
                    else
                        right--;
                }
                
                
            }
        }
        
        return res;
    }
};