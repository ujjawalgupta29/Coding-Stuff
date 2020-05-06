class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        if(n <= 1)
            return 1;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3; i<=n; i++)
        {
            int ways = 0;
            for(int j = 0; j<i; j++)
            {
                int nodes = i-1;
                int left = j;
                int right = nodes-j;
                ways += dp[left] * dp[right];
            }
            dp[i] = ways;
        }
        
        return dp[n];
    }
};