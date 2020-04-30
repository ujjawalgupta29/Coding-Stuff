class Solution {
public:
    int FindMaxSum(vector<int> arr, int n)
    {
        int take = 0, skip = 0;
        for(int num : arr)
        {
            int takei = skip + num;
            int skipi = max(take, skip);
            take = takei;
            skip = skipi;
        }
        
        return max(take, skip);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        vector<int> sum(10001, 0);
        for(int x : nums)
            sum[x] += x;
        
        return FindMaxSum(sum, 10001);        
            
    }
};