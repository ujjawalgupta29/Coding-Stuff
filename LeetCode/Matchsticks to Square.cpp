class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int x : nums)
            sum += x;
        
        if(sum % 4 != 0 || n < 4)
            return 0;
        
        int len_each = sum/4;
        vector<bool> visited(nums.size(), 0);
        return solve(nums, len_each, 0, 4, 0, visited);
    }
    
    bool solve(vector<int> &nums, int len, int curr_len, int total, int i,
              vector<bool> &visited)
    {
        if(total == 0)
            return 1;
        
        if(curr_len == len)
            return solve(nums, len, 0, total-1, 0, visited);
        
        for(int idx=i; idx<nums.size(); idx++)
        {
            if(curr_len + nums[idx] <= len && visited[idx] == 0)
            {
                visited[idx] = 1;
                
                if(solve(nums, len, curr_len + nums[idx], total, idx+1, visited))
                {
                    return true;
                }
                
                visited[idx] = 0;
            }
        }
        
        return false;
        
    }
};