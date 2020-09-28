class Solution {
public:
    
    int mod = 1e9 + 7;
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> pascal(n+1);
        
        for(int i=0; i<n; i++)
        {
            pascal[i] = vector<long long>(i+1, 1);
            
            for(int j=1; j<i; j++)
                pascal[i][j] = (pascal[i-1][j] + pascal[i-1][j-1]) % mod;
        }
        
        long long ans = dfs(nums, pascal);
        return ans%mod - 1;
    }
    
    long long dfs(vector<int> &nums, vector<vector<long long>> &pascal)
    {
        int n = nums.size();
        if(n <= 2)
            return 1;
        
        vector<int> left;
        vector<int> right;
        int root = nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i] < root)
                left.push_back(nums[i]);
            
            else
                right.push_back(nums[i]);
        }
        
        int left_len = left.size();
        int right_len = right.size();
        
        long long left_res = dfs(left, pascal) % mod;
        long long right_res = dfs(right, pascal) % mod;
        
        return (((pascal[n-1][right_len] * left_res)%mod) * right_res) % mod;
    }
};