class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int counts = 0;
        
        int start = 0;
        int prod = 1;
        
        for(int i=0; i<n; i++)
        {
            prod *= nums[i];
            while(start <= i && prod >= k)
            {
                prod /= nums[start];
                start++;
            }
            
            counts += i - start + 1;
        }
        
        return counts;
    }
};