class Solution {
public:
    int integerBreak(int n) {
        int max_prod = 0;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=i/2; j++)
            {
                int a = j;
                int b = i-a;
                dp[i] = max(dp[i], a * max(dp[b], b));
            }
        }
        
        return dp[n];
    }
};