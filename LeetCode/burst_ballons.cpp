class Solution {
public:
    
    int dp[502][502];
    
    int dfs(vector<int> &nums, int i, int j)
    {
        if(i > j)
            return 0;
        
        if(i == j)
        {
            return nums[i]*nums[i-1]*nums[i+1];    
        }
        
        if(dp[i][j] == -1)
        {
            for(int k=i; k<=j; k++)
            {
                dp[i][j] = max(dp[i][j],
                              nums[i-1]*nums[k]*nums[j+1] + dfs(nums, i, k-1) + dfs(nums, k+1, j));
            }
        }
        
        return dp[i][j];
    }
    
    int maxCoins(vector<int>& nums) {
        for(int i=0;i<502; i++)
        {
            for(int j=0; j<502; j++)
                dp[i][j] = -1;
        }
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        return dfs(nums, 1, n - 2);
    }
};