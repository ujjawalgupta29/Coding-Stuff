class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> prod(n);
        if(n <= 1)
            return prod;
        
        prod[0] = 1;
        for(int i=1; i<n; i++)
        {
            prod[i] = prod[i-1] * nums[i-1];
        }
        
        int temp = 1;
        for(int i=n-2; i >= 0; i--)
        {
            temp = temp * nums[i+1];
            prod[i] *= temp;
        }
        
        return prod;
    }
};