class Solution {
public:
    
    int binary_search(vector<int> nums, vector<int> indices, int num, int left, int right)
    {
        while(left <= right)
        {
            int mid = (left + right) / 2;
            
            if(nums[indices[mid]] < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> indices;
        indices.push_back(-1);
        
        for(int i=0; i<n; i++)
        {
            int len = binary_search(nums, indices, nums[i], 1, indices.size()-1);
            if(len == indices.size())
                indices.push_back(i);
            else
                indices[len] = i;
        }
        
        return indices.size()-1;
    }
};