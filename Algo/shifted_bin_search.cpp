class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        if(n == 0)
            return -1;
        
        int left = 0, right = n-1;
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            else if(nums[mid] > target)
            {
                if(nums[right] < nums[mid] && nums[left] > target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            
            else
            {
                if(nums[left] > nums[mid] && nums[right] < target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        
        return -1;
    }
};