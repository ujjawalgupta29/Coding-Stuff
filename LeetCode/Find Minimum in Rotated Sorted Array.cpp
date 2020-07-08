
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        if(nums[0] < nums[n-1])
            return nums[0];
        
        int l=0, r=n-1;
        
        while(l <= r)
        {
            int mid = (l + r) / 2;
            
            if(mid != 0 && nums[mid] < nums[mid-1])
                return nums[mid];
            
            else if( (nums[mid] > nums[r] && nums[mid] >= nums[l]) )
                l = mid + 1;
            
            else 
                r = mid - 1;
        }
        
        return -1;
    }
};