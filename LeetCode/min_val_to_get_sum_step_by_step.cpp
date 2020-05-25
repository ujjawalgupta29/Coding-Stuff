class Solution {
public:
    
    bool check(vector<int>&nums, int start)
    {
        int n = nums.size();
        for(int x : nums)
        {
            start += x;
            if(start < 1)
                return 0;
        }
        
        return 1;
    }
    
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int l=1, r=10001;
        int min_val = INT_MAX;
        
        while(l <= r)
        {
            int mid = (l+r)/2;
            
            if(check(nums, mid))
            {
                min_val = min(min_val, mid);
                r = mid - 1;
            }
            
            else
                l = mid + 1;
        }
        
        return min_val;
    }
};