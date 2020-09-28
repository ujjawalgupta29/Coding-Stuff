class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        int mod = 1e9 + 7;
       vector<vector<long long int>> dp(n+1, vector<long long int>(n+1, 0));

        for(int i=0; i<n; i++)
            dp[i][i] = 1;

        for(int l=2; l<=n; l++)
        {
            for(int i=0; i<=n-l; i++)
            {
                int j = i + l -1;

                if(s[j] == s[i])
                {
                    int low = i+1;
                    int high = j-1;
                    
                    while(low <= high && s[low] != s[j])
                        low++;
                    
                    while(low <= high && s[high] != s[j])
                        high--;
                    
                    if(low < high)
                    {
                        dp[i][j] = dp[i+1][j-1]*2 - dp[low+1][high-1];
                    }
                    
                    else if(low == high)
                    {
                        dp[i][j] = dp[i+1][j-1]*2 + 1;
                    }
                    
                    else
                    {
                        dp[i][j] = dp[i+1][j-1]*2 + 2;
                    }
                }

                else
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                
                dp[i][j] = (dp[i][j] < 0) ? dp[i][j] + mod : dp[i][j] % mod;
            }
        }

        return dp[0][n-1];
    }
};