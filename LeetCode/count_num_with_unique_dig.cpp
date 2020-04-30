class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        vector<int> dp(n+1);
        dp[0] = 1;
        
        for(int i=1; i<=n; i++)
        {
            int temp = i-1;
            int res = 9;
            int mult = 9;
            while(temp--)
            {
                res = res * mult;
                mult--;
            }
            dp[i] = res + dp[i-1];
        }
        
        return dp[n];
    }
};